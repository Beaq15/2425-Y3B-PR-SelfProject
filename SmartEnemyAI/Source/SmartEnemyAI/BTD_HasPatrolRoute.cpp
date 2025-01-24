// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_HasPatrolRoute.h"
#include "Enemy_Base.h"
#include "AIController.h"

bool UBTD_HasPatrolRoute::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AEnemy_Base* Enemy = Cast<AEnemy_Base>(OwnerComp.GetAIOwner()->GetPawn());
	if (Enemy->PatrolRoute)
		return true;

	return false;
}
