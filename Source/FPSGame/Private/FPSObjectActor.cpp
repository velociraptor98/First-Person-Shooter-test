// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSObjectActor.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FPSCharacter.h"


// Sets default values
AFPSObjectActor::AFPSObjectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	RootComponent = meshComp;
	
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	sphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	sphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	sphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	sphereComp->SetupAttachment(meshComp);
}

// Called when the game starts or when spawned
void AFPSObjectActor::BeginPlay()
{
	Super::BeginPlay();
	PlayEffects();
}

void AFPSObjectActor::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, particle, GetActorLocation());
}

// Called every frame
void AFPSObjectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AFPSObjectActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UE_LOG(LogTemp,Warning,TEXT("Overlap generated"))
	PlayEffects();
	AFPSCharacter *character = Cast<AFPSCharacter>(OtherActor);
	if(character)
	{
		character->bIsCarryingObjective = true;
		Destroy();
	}
}


