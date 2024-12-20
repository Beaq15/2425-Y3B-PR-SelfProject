// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Base.h"

// Sets default values
AEnemy_Base::AEnemy_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	attackMontage = nullptr;
	isWieldingSword = false;
	spawnedSword = nullptr;
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
	if (!attackMontage) return;
	USkeletalMeshComponent* mesh = GetMesh();
	if (!mesh) return;

	UAnimInstance* animInstance = mesh->GetAnimInstance();
	if (animInstance)
	{
		FOnMontageEnded montageEndedDelegate;
		montageEndedDelegate.BindUObject(this, &AEnemy_Base::HandleMontageEnded);

		animInstance->Montage_Play(attackMontage, 1.0f);
		animInstance->Montage_SetEndDelegate(montageEndedDelegate, attackMontage);
	}
}

//void AEnemy_Base::HandleMontageEnded(UAnimMontage* montage, bool interrupted)
//{
//	if (montage == attackMontage)
//	{
//		OnAttackEnd.Broadcast();
//	}
//}


void AEnemy_Base::WieldSword()
{
	FTransform spawnTransform = GetActorTransform();

	spawnedSword = GetWorld()->SpawnActor<AActor>(SwordClass, spawnTransform);
	if (spawnedSword)
	{
		USkeletalMeshComponent* mesh = GetMesh();
		if (mesh)
		{
			FAttachmentTransformRules attachmentRules(EAttachmentRule::SnapToTarget, true);
			FName socketName = TEXT("hand_r_sword_socket");
			spawnedSword->AttachToComponent(mesh, attachmentRules, socketName);

			isWieldingSword = true;
		}
	}
}

