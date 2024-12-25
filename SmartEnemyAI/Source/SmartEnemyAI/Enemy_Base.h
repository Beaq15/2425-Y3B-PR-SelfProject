// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy_Base.generated.h"

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

	bool IsWieldingSword;

protected:
	virtual void BeginPlay() override;
};
