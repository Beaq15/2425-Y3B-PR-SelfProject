// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Ranged.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "AIC_Enemy_Base.h"
#include "AIController.h"

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
	IsWieldingWeapon = true;
}

float AEnemy_Ranged::SetMovementSpeed(EMovementSpeed Speed)
{
	switch (Speed)
	{
	case EMovementSpeed::EMS_Idle:
		GetCharacterMovement()->MaxWalkSpeed = 0;
		break;
	case EMovementSpeed::EMS_Walking:
		GetCharacterMovement()->MaxWalkSpeed = 200;
		break;
	case EMovementSpeed::EMS_Jogging:
		GetCharacterMovement()->MaxWalkSpeed = 300;
		break;
	case EMovementSpeed::EMS_Sprinting:
		GetCharacterMovement()->MaxWalkSpeed = 500;
		break;
	default:
		GetCharacterMovement()->MaxWalkSpeed = 0;
	}

	return GetCharacterMovement()->MaxWalkSpeed;
}

void AEnemy_Ranged::GetIdealRange(float& AttackRadius, float& DefendRadius)
{
	AttackRadius = 600.0f;
	DefendRadius = 600.0f;
}

void AEnemy_Ranged::Attack()
{
	FHitResult HitResult;
	AAIController* AIController = Cast<AAIController>(this->GetController());
	if (AIController)
	{
		AAIC_Enemy_Base* Enemy = Cast<AAIC_Enemy_Base>(AIController);
		if (Enemy && Enemy->AttackTargetVariable)
		{
			UWorld* World = this->GetWorld();
			if (World)
			{
				bool bHit = World->LineTraceSingleByChannel(
					HitResult,
					this->GetActorLocation(),
					Enemy->AttackTargetVariable->GetActorLocation(),
					ECollisionChannel::ECC_Visibility
				);
				if (!bHit)
				{
					if (GEngine)
					{
						GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Emerald, TEXT("HIT Target"));
					}
				}
			}
		}

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Emerald, TEXT("Ranged enemy is shooting at player"));
		}
	}
}
