// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "AIC_Enemy_Base.generated.h"


UENUM(BlueprintType)
enum class EAIState : uint8
{
	ES_Passive, //0
	ES_Attacking, //1
	ES_Frozen, //2
	ES_Investigating, //3
	ES_Dead //4
};

UENUM(BlueprintType)
enum class EAISense : uint8
{
	EAS_None,
	EAS_Sight,
	EAS_Hearing,
	EAS_Damage
};

UCLASS()
class SMARTENEMYAI_API AAIC_Enemy_Base : public AAIController
{
	GENERATED_BODY()
public:
	AAIC_Enemy_Base();
	void SetStateAsPassive();
	void SetStateAsAttacking(AActor* AttackTarget);
	void SetStateAsInvestigating(FVector Location);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AActor* AttackTargetVariable;
protected:

	virtual void OnPossess(APawn* InPawn) override;
	/*UFUNCTION(BlueprintCallable)
	void PerceptionUpdated(const TArray<AActor*>& UpdatedActors);*/
	UFUNCTION(BlueprintCallable)
	bool CanSenseActor(AActor* Actor, EAISense Sense);

	UFUNCTION(BlueprintCallable)
	void HandleSensedSight(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void HandleSensedSound(FVector Location);

	UFUNCTION(BlueprintCallable)
	void HandleSensedDamage(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	int GetCurrentState();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UBehaviorTreeComponent* BehaviorComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UBlackboardComponent* BlackboardComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UAIPerceptionComponent* AIPerceptionComponent;

	FName AttackTargetKeyName;
	FName StateKeyName;
	FName PointOfInterestKeyName;
	FName AttackRadiusKeyName;
	FName DefendRadiusKeyName;

	

	UClass* GetSenseClass(EAISense Sense);
};
