// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsWieldingSword.h"
#include "Enemy_Base.h"
#include "AIController.h"

bool UBTD_IsWieldingSword::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController)
    {
        AEnemy_Base* Enemy = Cast<AEnemy_Base>(AIController->GetPawn());
        if (Enemy && Enemy->IsWieldingSword)
        {
            return true; 
        }
    }
    return false;
}
