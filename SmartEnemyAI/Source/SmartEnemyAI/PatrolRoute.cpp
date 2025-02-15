// Fill out your copyright notice in the Description page of Project Settings.
#include "PatrolRoute.h"

APatrolRoute::APatrolRoute()
{
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	SplineComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APatrolRoute::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APatrolRoute::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APatrolRoute::IncrementPatrolRoute()
{
	PatrolIndex += Direction;

	if (PatrolIndex == SplineComponent->GetNumberOfSplinePoints() - 1)
	{
		Direction = -1;
	}
	else if (PatrolIndex == 0)
	{
		Direction = 1;
	}
}

FVector APatrolRoute::GetSplinePointAsWorldPosition()
{
	return SplineComponent->GetLocationAtSplinePoint(PatrolIndex, ESplineCoordinateSpace::World);
}

