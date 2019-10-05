// Fill out your copyright notice in the Description page of Project Settings.

#include "BlackHole.h"
#include "Components/SphereComponent.h"

// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	innerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Inner Sphere"));
	outerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Outer sphere"));
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh component"));
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = meshComp;
	innerSphere->SetupAttachment(meshComp);
	outerSphere->SetupAttachment(meshComp);

	innerSphere->OnComponentBeginOverlap.AddDynamic(this, &ABlackHole::OverlapInnerSphere);
	

}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
}

void ABlackHole::OverlapInnerSphere(UPrimitiveComponent* overlappedcomponent, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if(otherActor)
	{
		otherActor->Destroy();
	}
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TArray<UPrimitiveComponent*> List;
	//Pass a out TArray to store the primitive components
	outerSphere->GetOverlappingComponents(List);
	for(int32 i=0;i<List.Num();i++)
	{
		UPrimitiveComponent *prim = List[i];
		if(prim && prim->IsSimulatingPhysics())
		{
			const float SphereRadius = outerSphere->GetScaledSphereRadius();
			const float ForceStrength = -2000;
			prim->AddRadialForce(GetActorLocation(), SphereRadius, ForceStrength, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}

}

