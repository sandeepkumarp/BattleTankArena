// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TAIC not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TAIC possessing %s"), *ControlledTank->GetName());
	}
}
