// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_MoveAlongPatrolRoute.h"
#include "Enemy_Base.h"
#include "AIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Navigation/PathFollowingComponent.h"

EBTNodeResult::Type UBTT_MoveAlongPatrolRoute::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		return EBTNodeResult::Failed;
	}
	AEnemy_Base* Enemy = Cast<AEnemy_Base>(OwnerComp.GetAIOwner()->GetPawn());
	if (!Enemy || !Enemy->GetPatrolRoute())
	{
		return EBTNodeResult::Failed;
	}

	FVector Destination = Enemy->GetPatrolRoute()->GetSplinePointAsWorldPosition();
	AIController->MoveToLocation(Destination, 10.0f, false);
	Enemy->GetPatrolRoute()->IncrementPatrolRoute();
	return EBTNodeResult::Succeeded;
}

EBTNodeResult::Type UBTT_MoveAlongPatrolRoute::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController)
	{
		AIController->StopMovement();
		return EBTNodeResult::Aborted;
	}
	return EBTNodeResult::Failed;
}
