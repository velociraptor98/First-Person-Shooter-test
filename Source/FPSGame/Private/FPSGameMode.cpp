// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AFPSGameMode::AFPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();
}

void AFPSGameMode::GameComplete(APawn* actor)
{
	actor->DisableInput(nullptr);
	OnGameComplete(actor);
	TArray<AActor*> ReturnedActors;
	UGameplayStatics::GetAllActorsOfClass(this, Spectator,ReturnedActors);
	AActor* NewTarget;
	if(ReturnedActors.Num()>0)
	{
		NewTarget = ReturnedActors[0];
		APlayerController* playerC = Cast<APlayerController>(actor->GetController());
		if (playerC)
		{
			playerC->SetViewTargetWithBlend(NewTarget, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
		}
	}
	
}
