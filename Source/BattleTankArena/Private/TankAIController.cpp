// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankPlayerController.h"

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

	auto playerTank = GetPlayerTank();
	if (!playerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank NOT found!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found player tank :  %s"), *playerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APlayerController* tankPlayerController = GetWorld()->GetFirstPlayerController();
	if (tankPlayerController != nullptr)
	{
		APawn* playerTank = tankPlayerController->GetPawn();
		if (playerTank != nullptr)
		{
			return Cast<ATank>(playerTank);
		}
	}
	return nullptr;
}
