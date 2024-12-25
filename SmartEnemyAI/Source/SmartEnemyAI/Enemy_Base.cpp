// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Base.h"

// Sets default values
AEnemy_Base::AEnemy_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	float MontageDuration = 2.0f;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, MontageDuration, FColor::Blue, TEXT("Enemy is attacking with default attack"));
	}
}

void AEnemy_Base::WieldSword()
{
	float WieldSwordDuration = 2.0f;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, WieldSwordDuration, FColor::Blue, TEXT("Enemy is wielding sword"));
	}

	IsWieldingSword = true;
}

