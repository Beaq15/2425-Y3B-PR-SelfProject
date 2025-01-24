// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Enemy_Base.generated.h"

UENUM(BlueprintType)
enum class EMovementSpeed : uint8
{
	EMS_Idle,
	EMS_Walking,
	EMS_Jogging,
	EMS_Sprinting
};
UCLASS()
class SMARTENEMYAI_API AEnemy_Base : public ACharacter
{
	GENERATED_BODY()

public:

	AEnemy_Base();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Attack();
	virtual void EquipWeapon();
	virtual void UnequipWeapon();
	virtual float SetMovementSpeed(EMovementSpeed Speed);
	//APatrolRoute* GetPatrolRoute();
	virtual void GetIdealRange(float& AttackRadius, float& DefendRadius);

	void Heal(float HealPercentage);
	bool IsWieldingWeapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float MaxHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Health;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsDead;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	APatrolRoute* PatrolRoute;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
protected:
	virtual void BeginPlay() override;
};
