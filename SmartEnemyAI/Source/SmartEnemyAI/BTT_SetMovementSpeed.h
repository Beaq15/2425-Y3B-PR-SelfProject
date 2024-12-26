// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Enemy_Base.h"
#include "BTT_SetMovementSpeed.generated.h"

/**
 * 
 */
UCLASS()
class SMARTENEMYAI_API UBTT_SetMovementSpeed : public UBTTaskNode
{
	GENERATED_BODY()
	
public:

	UBTT_SetMovementSpeed();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditInstanceOnly)
	EMovementSpeed MovementSpeed = EMovementSpeed::EMS_Idle;
};
