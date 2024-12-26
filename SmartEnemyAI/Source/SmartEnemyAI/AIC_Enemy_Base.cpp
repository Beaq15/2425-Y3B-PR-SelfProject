// Fill out your copyright notice in the Description page of Project Settings.


#include "AIC_Enemy_Base.h"

AAIC_Enemy_Base::AAIC_Enemy_Base()
{
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void AAIC_Enemy_Base::SetStateAsPassive()
{
	BlackboardComp->SetValueAsInt(TEXT("State"), 0);
}

void AAIC_Enemy_Base::SetStateAsAttacking(AActor* AttackTarget)
{
	BlackboardComp->SetValueAsObject(TEXT("AttackTarget"), AttackTarget);
	BlackboardComp->SetValueAsInt(TEXT("State"), 1);
}

void AAIC_Enemy_Base::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (BehaviorTreeAsset)
	{
		BlackboardComp->InitializeBlackboard(*BehaviorTreeAsset->BlackboardAsset);
		BehaviorComp->StartTree(*BehaviorTreeAsset);
		SetStateAsPassive();
	}

}
