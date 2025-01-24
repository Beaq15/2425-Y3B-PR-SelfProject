// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_FocusTarget.h"

EBTNodeResult::Type UBTT_FocusTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp)
    {
        return EBTNodeResult::Failed;
    }

    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController)
    {
        return EBTNodeResult::Failed;
    }

    AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject(FocusTargetKey.SelectedKeyName));
    FVector TargetLocation = BlackboardComp->GetValueAsVector(FocusTargetKey.SelectedKeyName);
    if (!TargetActor)
    {
        if (!TargetLocation.IsZero())
        {
            AIController->SetFocalPoint(TargetLocation);
        }
    }

    AIController->SetFocus(TargetActor);

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
