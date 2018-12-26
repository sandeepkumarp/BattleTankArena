// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	controlledTank = GetControlledTank();
	if (!controlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TPC not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TPC possessing %s"), *controlledTank->GetName());
	}

	HitLocation = FVector::ZeroVector;
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!controlledTank) { return; }
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location %s"), *HitLocation.ToString());
	}
}

//Line Trace through Cross-hair, If it hits landscape, return true.
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}
