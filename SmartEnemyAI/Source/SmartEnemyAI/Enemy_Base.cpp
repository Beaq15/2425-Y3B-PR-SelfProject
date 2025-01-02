// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Base.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AEnemy_Base::AEnemy_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BehaviorTree = CreateDefaultSubobject<UBehaviorTree>(TEXT("BehaviorTree"));
}

// Called when the game starts or when spawned
void AEnemy_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy_Base::Attack()
{
}

void AEnemy_Base::EquipWeapon()
{
}

void AEnemy_Base::UnequipWeapon()
{
}

float AEnemy_Base::SetMovementSpeed(EMovementSpeed Speed)
{

	switch (Speed)
	{
	case EMovementSpeed::EMS_Idle:
		GetCharacterMovement()->MaxWalkSpeed = 0;
		break;
	case EMovementSpeed::EMS_Walking:
		GetCharacterMovement()->MaxWalkSpeed = 100;
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

APatrolRoute* AEnemy_Base::GetPatrolRoute()
{
	return PatrolRoute;
}


