// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIC_Enemy_Base.generated.h"


UENUM(BlueprintType)
enum class EState : uint8
{
	ES_Passive, //0
	ES_Attacking, //1
	ES_Frozen, //2
	ES_Investigating, //3
	ES_Dead //4
};

UCLASS()
class SMARTENEMYAI_API AAIC_Enemy_Base : public AAIController
{
	GENERATED_BODY()
public:
	AAIC_Enemy_Base();
	void SetStateAsPassive();
	void SetStateAsAttacking(AActor* AttackTarget);
protected:

	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTreeAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UBehaviorTreeComponent* BehaviorComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UBlackboardComponent* BlackboardComp;
};
