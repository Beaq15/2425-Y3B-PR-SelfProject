// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "PatrolRoute.generated.h"

UCLASS()
class SMARTENEMYAI_API APatrolRoute : public AActor
{
	GENERATED_BODY()
	
public:	
	APatrolRoute();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USplineComponent* SplineComponent;

	void IncrementPatrolRoute();
	FVector GetSplinePointAsWorldPosition();

	int PatrolIndex;
	UPROPERTY(meta = (ClampMin = "-1.0", ClampMax = "1.0"))
	int Direction;

protected:
	virtual void BeginPlay() override;

};
