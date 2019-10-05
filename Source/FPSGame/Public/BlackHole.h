// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlackHole.generated.h"

class USphereComponent;

UCLASS()
class FPSGAME_API ABlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackHole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
		USphereComponent *innerSphere;
	UPROPERTY(VisibleAnywhere)
		USphereComponent *outerSphere;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent *meshComp;

	UFUNCTION()
		void OverlapInnerSphere(UPrimitiveComponent *overlappedcomponent, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
