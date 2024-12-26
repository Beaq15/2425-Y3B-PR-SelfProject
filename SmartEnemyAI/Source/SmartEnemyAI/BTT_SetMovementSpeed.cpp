// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_SetMovementSpeed.h"
#include "Enemy_Base.h"
#include "AIController.h"

UBTT_SetMovementSpeed::UBTT_SetMovementSpeed()
{
	MovementSpeed = EMovementSpeed::EMS_Sprinting;
}

EBTNodeResult::Type UBTT_SetMovementSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AEnemy_Base* Enemy = Cast<AEnemy_Base>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		Enemy->SetMovementSpeed(MovementSpeed);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
