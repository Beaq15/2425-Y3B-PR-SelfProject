// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Melee.h"

void AEnemy_Melee::Attack()
{
	float MontageDuration = 2.0f;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, MontageDuration, FColor::Red, TEXT("Melee enemy is attacking with default attack"));
	}
}

void AEnemy_Melee::EquipWeapon()
{
	float WieldSwordDuration = 2.0f;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, WieldSwordDuration, FColor::Red, TEXT("Melee enemy is wielding sword"));
	}

	IsWieldingWeapon = true;
}

void AEnemy_Melee::UnequipWeapon()
{
	float SheathSwordDuration = 2.0f;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, SheathSwordDuration, FColor::Red, TEXT("Melee enemy is putting away sword"));
	}
	IsWieldingWeapon = false;
}