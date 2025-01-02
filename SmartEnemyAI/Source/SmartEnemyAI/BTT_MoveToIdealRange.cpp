// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_MoveToIdealRange.h"
#include "AIController.h"
#include "Enemy_Base.h"
#include "NavigationSystem.h"
#include "Navigation/PathFollowingComponent.h"
#include "AI/Navigation/NavigationTypes.h"

EBTNodeResult::Type UBTT_MoveToIdealRange::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		return EBTNodeResult::Failed;
	}
	AEnemy_Base* Enemy = Cast<AEnemy_Base>(OwnerComp.GetAIOwner()->GetPawn());
	if (!Enemy)
	{
		return EBTNodeResult::Failed;
	}
	UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject(AttackTarget.SelectedKeyName));
	if (!TargetActor)
	{
		return EBTNodeResult::Failed;
	}

	float Range = BlackboardComp->GetValueAsFloat(IdealRange.SelectedKeyName);

	AIController->MoveToLocation(TargetActor->GetActorLocation(), Range);
	return EBTNodeResult::Succeeded;

	//FVector Direction = (TargetActor->GetActorLocation() - Enemy->GetActorLocation()).GetSafeNormal();
	//FVector Destination = TargetActor->GetActorLocation() - Direction * Range; // Adjust destination to maintain 'Range' units away

	//FNavLocation NavLocation;
	//UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	//if (NavSys && NavSys->GetRandomPointInNavigableRadius(Destination, 10.0f, NavLocation)) // Use a small acceptance radius
	//{
	//	FAIMoveRequest MoveRequest;
	//	MoveRequest.SetGoalLocation(NavLocation.Location);
	//	MoveRequest.SetAcceptanceRadius(10.0f); // Small radius for precise movement

	//	FPathFollowingRequestResult Result = AIController->MoveTo(MoveRequest);
	//	if (Result.Code == EPathFollowingRequestResult::RequestSuccessful)
	//	{
	//		return EBTNodeResult::InProgress;
	//	}
	//}
}

