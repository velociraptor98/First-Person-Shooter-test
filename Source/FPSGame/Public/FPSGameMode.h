// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameMode.generated.h"

UCLASS()
class AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly,Category="spectator")
	TSubclassOf<AActor> Spectator;

public:

	AFPSGameMode();
	 void GameComplete(APawn* actor);
	 UFUNCTION(BlueprintImplementableEvent, Category = "gameplay")
		 void OnGameComplete(AActor* actor);
};



