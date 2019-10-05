// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameMode.generated.h"

UCLASS()
class AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	AFPSGameMode();
	 void GameComplete(AActor* actor);
	 UFUNCTION(BlueprintImplementableEvent, Category = "gameplay")
		 void OnGameComplete(AActor* actor);
};



