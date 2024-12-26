// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PatrolRoute.h"
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

	void Attack();
	void WieldSword();
	void SheathSword();
	float SetMovementSpeed(EMovementSpeed Speed);
	APatrolRoute* GetPatrolRoute();

	bool IsWieldingSword;

	UPROPERTY(EditInstanceOnly)
	APatrolRoute* PatrolRoute;
protected:
	virtual void BeginPlay() override;
};
