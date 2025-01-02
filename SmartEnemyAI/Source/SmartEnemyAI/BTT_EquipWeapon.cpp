// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_EquipWeapon.h"
#include "Enemy_Base.h"
#include "AIController.h"

EBTNodeResult::Type UBTT_EquipWeapon::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AEnemy_Base* Enemy = Cast<AEnemy_Base>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		Enemy->EquipWeapon();
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}
}