// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy_Base.h"
#include "Enemy_Ranged.generated.h"

/**
 * 
 */
UCLASS()
class SMARTENEMYAI_API AEnemy_Ranged : public AEnemy_Base
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay();
	virtual void EquipWeapon() override;
	virtual float SetMovementSpeed(EMovementSpeed Speed) override;
	virtual void GetIdealRange(float& AttackRadius, float& DefendRadius) override;
	virtual void Attack() override;
};
