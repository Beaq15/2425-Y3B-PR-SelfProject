// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy_Base.h"
#include "Enemy_Melee.generated.h"

/**
 * 
 */
UCLASS()
class SMARTENEMYAI_API AEnemy_Melee : public AEnemy_Base
{
	GENERATED_BODY()
protected:

	virtual void Attack() override;
	virtual void EquipWeapon() override;
	virtual void UnequipWeapon() override;
};
