// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTT_FocusTarget.generated.h"

/**
 * 
 */
UCLASS()
class SMARTENEMYAI_API UBTT_FocusTarget : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditInstanceOnly, Category = "Blackboard")
	FBlackboardKeySelector FocusTargetKey;
};
