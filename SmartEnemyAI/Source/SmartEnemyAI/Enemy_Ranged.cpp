// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Ranged.h"

void AEnemy_Ranged::BeginPlay()
{
	EquipWeapon();
}

void AEnemy_Ranged::EquipWeapon()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Ranged enemy equipping rifle gun"));
	}
}
