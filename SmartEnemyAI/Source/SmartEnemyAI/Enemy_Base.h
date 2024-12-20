// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy_Base.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttackEnd);

UCLASS()
class SMARTENEMYAI_API AEnemy_Base : public ACharacter
{
	GENERATED_BODY()

	//FUNCTIONS
public:

	AEnemy_Base();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UFUNCTION(BlueprintCallable)
	void Attack();
	//UFUNCTION(BlueprintCallable)
	void WieldSword();
protected:

	virtual void BeginPlay() override;

private:

	UFUNCTION()
	void HandleMontageEnded(UAnimMontage* montage, bool interrupted);

	//VARIABLES
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor>SwordClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* attackMontage;
private:

	bool isWieldingSword;
	AActor* spawnedSword;

	//UPROPERTY(BlueprintAssignable, Category = "Events") //allows it to be bound in blueprints
	//FOnAttackEnd OnAttackEnd;
};
