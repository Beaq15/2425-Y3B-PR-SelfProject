// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_SetStateAsPassive.h"
#include "AIC_Enemy_Base.h"

EBTNodeResult::Type UBTT_SetStateAsPassive::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	AAIC_Enemy_Base* EnemyBaseAI = Cast<AAIC_Enemy_Base>(AIController);
    if (EnemyBaseAI)
    {
        EnemyBaseAI->SetStateAsPassive();
        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}

