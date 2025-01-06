// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_CanSeeTarget.h"
#include "Enemy_Base.h"
#include "AIController.h"

bool UBTD_CanSeeTarget::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UObject* TargetActorObject = BlackboardComp->GetValueAsObject("TargetActorKey");
	AActor* TargetActor = Cast<AActor>(TargetActorObject);
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController)
	{
		AEnemy_Base* Enemy = Cast<AEnemy_Base>(AIController->GetPawn());
		if (TargetActor)
		{
			FHitResult HitResult;
			FCollisionQueryParams CollisionParams;
			CollisionParams.AddIgnoredActor(Enemy);
			bool bHit = GetWorld()->LineTraceSingleByChannel(
				HitResult,
				Enemy->GetActorLocation(),
				TargetActor->GetActorLocation(),
				ECC_Visibility,
				CollisionParams
			);
			return !bHit;
		}

	}
	return false;
}
