// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsHealthBelowTreshhold.h"
#include "AIController.h"
#include "Enemy_Base.h"

bool UBTD_IsHealthBelowTreshhold::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController)
    {
        AEnemy_Base* Enemy = Cast<AEnemy_Base>(AIController->GetPawn());
        if (Enemy)
        {
            if (Enemy->Health <= Enemy->MaxHealth * HealthTreshhold)
                return true;
        }
    }
	return false;
}
