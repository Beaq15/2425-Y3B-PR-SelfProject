// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Heal.h"
#include "AIController.h"
#include "Enemy_Base.h"
EBTNodeResult::Type UBTT_Heal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AEnemy_Base* Enemy = Cast<AEnemy_Base>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		Enemy->Heal(HealthPercentage);
	}
	return EBTNodeResult::Type();
}
