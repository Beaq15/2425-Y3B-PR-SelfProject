// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_SheathSword.h"
#include "Enemy_Base.h"
#include "AIController.h"

EBTNodeResult::Type UBTT_SheathSword::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AEnemy_Base* Enemy = Cast<AEnemy_Base>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		Enemy->SheathSword();
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}
}
