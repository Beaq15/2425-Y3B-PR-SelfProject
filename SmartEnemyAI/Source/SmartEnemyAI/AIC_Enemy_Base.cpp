// Fill out your copyright notice in the Description page of Project Settings.


#include "AIC_Enemy_Base.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Damage.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Enemy_Base.h"

AAIC_Enemy_Base::AAIC_Enemy_Base()
{
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComp"));
	
	UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SightConfig->SightRadius = 800.0f;
	SightConfig->LoseSightRadius = 1200.0f;
	SightConfig->PeripheralVisionAngleDegrees = 60.0f;
	SightConfig->SetMaxAge(5.0f);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	AIPerceptionComponent->ConfigureSense(*SightConfig);

	UAISenseConfig_Hearing* HearConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hear Config"));
	HearConfig->HearingRange = 500.0f;
	HearConfig->SetMaxAge(3.0f);

	AIPerceptionComponent->ConfigureSense(*HearConfig);

	UAISenseConfig_Damage* DamageConfig = CreateDefaultSubobject<UAISenseConfig_Damage>(TEXT("Damage Config"));
	DamageConfig->SetMaxAge(5.0f);

	AIPerceptionComponent->ConfigureSense(*DamageConfig);

	/*if (PerceptionComponent)
	{
		PerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &AAIC_Enemy_Base::PerceptionUpdated);
		PerceptionComponent->Activate();
	}*/

	AttackTargetKeyName = TEXT("AttackTarget");
	StateKeyName = TEXT("State");
	PointOfInterestKeyName = TEXT("PointOfInterest");
	AttackRadiusKeyName = TEXT("AttackRadius");
	DefendRadiusKeyName = TEXT("DefendRadius");
}

void AAIC_Enemy_Base::SetStateAsPassive()
{
	BlackboardComp->SetValueAsInt(StateKeyName, 0);
}

void AAIC_Enemy_Base::SetStateAsAttacking(AActor* AttackTarget)
{
	BlackboardComp->SetValueAsObject(AttackTargetKeyName, AttackTarget);
	BlackboardComp->SetValueAsInt(StateKeyName, 1);

	AttackTargetVariable = AttackTarget;
}

void AAIC_Enemy_Base::SetStateAsInvestigating(FVector Location)
{
	BlackboardComp->SetValueAsInt(StateKeyName, 3);
	BlackboardComp->SetValueAsVector(PointOfInterestKeyName, Location);
}

void AAIC_Enemy_Base::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

		AEnemy_Base* Enemy = Cast<AEnemy_Base>(InPawn);
		if (Enemy && Enemy->BehaviorTree)
		{
			BlackboardComp->InitializeBlackboard(*Enemy->BehaviorTree->BlackboardAsset);
			BehaviorComp->StartTree(*Enemy->BehaviorTree);
			SetStateAsPassive();
			BlackboardComp->SetValueAsFloat(AttackRadiusKeyName, 50.0f);
			BlackboardComp->SetValueAsFloat(DefendRadiusKeyName, 350.0f);

		}

}

//void AAIC_Enemy_Base::PerceptionUpdated(const TArray<AActor*>& UpdatedActors)
//{
//	for (AActor* Value : UpdatedActors)
//	{ 
//		if (CanSenseActor(Value, EAISense::EAS_Sight))
//		{
//			if (GEngine)
//			{
//				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("Sensed Sight"));
//			}
//		}
//		if (CanSenseActor(Value, EAISense::EAS_Hearing))
//		{
//			if (GEngine)
//			{
//				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("Sensed Sound"));
//			}
//		}
//		if (CanSenseActor(Value, EAISense::EAS_Damage))
//		{
//			if (GEngine)
//			{
//				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("Sensed Damage"));
//			}
//		}
//	}
//}

bool AAIC_Enemy_Base::CanSenseActor(AActor* Actor, EAISense Sense)
{
	FActorPerceptionBlueprintInfo Info;

	if (AIPerceptionComponent->GetActorsPerception(Actor, Info))
	{
		UClass* SenseClass = GetSenseClass(Sense);
		for (const FAIStimulus& Stimulus : Info.LastSensedStimuli)
		{
			if (UAIPerceptionSystem::GetSenseClassForStimulus(GetWorld(), Stimulus ) == SenseClass)
			{
				return Stimulus.WasSuccessfullySensed();
			}

		}
	}
	
	return false;
}

void AAIC_Enemy_Base::HandleSensedSight(AActor* Actor)
{
	if (GetCurrentState() == 0 || GetCurrentState() == 3)
	{
		ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(Actor->GetWorld(), 0);
		ACharacter* CharacterActor = Cast<ACharacter>(Actor);
		if (CharacterActor && CharacterActor == PlayerCharacter)
			SetStateAsAttacking(Actor);
	}
}

void AAIC_Enemy_Base::HandleSensedSound(FVector Location)
{
	if (GetCurrentState() == 0 || GetCurrentState() == 3)
	{
		SetStateAsInvestigating(Location);
	}
}

void AAIC_Enemy_Base::HandleSensedDamage(AActor* Actor)
{
	if (GetCurrentState() == 0 || GetCurrentState() == 3)
	{
		SetStateAsAttacking(Actor);
	}
}

int AAIC_Enemy_Base::GetCurrentState()
{
	return BlackboardComp->GetValueAsInt(StateKeyName);
}

UClass* AAIC_Enemy_Base::GetSenseClass(EAISense Sense)
{
	switch (Sense)
	{
	case EAISense::EAS_Sight:
		return UAISense_Sight::StaticClass();
		break;
	case EAISense::EAS_Hearing:
		return UAISense_Hearing::StaticClass();
		break;
	case EAISense::EAS_Damage:
		return UAISense_Damage::StaticClass();
		break;
	default:
		return NULL;
	}
}
