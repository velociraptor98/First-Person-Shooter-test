// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSExtractionZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "FPSCharacter.h"
#include "FPSGameMode.h"

// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	boxprim = CreateDefaultSubobject<UBoxComponent>(TEXT("ExtractionZone"));
	boxprim->SetBoxExtent(FVector(200.0f, 200.0f, 200.0f));
	boxprim->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	boxprim->SetCollisionResponseToAllChannels(ECR_Ignore);
	boxprim->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	boxprim->SetHiddenInGame(false);
	RootComponent = boxprim;
	decal = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	decal->DecalSize=(FVector(200.0f, 200.0f, 200.0f));
	decal->SetupAttachment(RootComponent);
	boxprim->OnComponentBeginOverlap.AddDynamic(this, &AFPSExtractionZone::HandleOverlap);
}

// Called when the game starts or when spawned
void AFPSExtractionZone::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSExtractionZone::HandleOverlap(UPrimitiveComponent* prim, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFPSCharacter *playerPawn;
	playerPawn = Cast<AFPSCharacter>(OtherActor);
	if (playerPawn&&playerPawn->bIsCarryingObjective)
	{
		UE_LOG(LogTemp, Error, TEXT("Collision detected, Objective Completed:%s"), playerPawn->bIsCarryingObjective ? "1" : "0")
			AFPSGameMode* GM = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
		if(GM)
		{
			GM->GameComplete(OtherActor);
		}

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Collision detected, Objective Completed:%s"), playerPawn->bIsCarryingObjective ? "1" : "0")
	}
}

// Called every frame
void AFPSExtractionZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

