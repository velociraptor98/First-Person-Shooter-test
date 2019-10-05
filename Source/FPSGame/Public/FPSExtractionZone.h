// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSExtractionZone.generated.h"


class UBoxComponent;
class UDecalComponent;

UCLASS()
class FPSGAME_API AFPSExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSExtractionZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Category = "gameplay")
		UBoxComponent *boxprim;
	UPROPERTY(VisibleAnywhere, Category = "gameplay")
		UDecalComponent *decal;
	UFUNCTION()
		void HandleOverlap(UPrimitiveComponent *prim, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
