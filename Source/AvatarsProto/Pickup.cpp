// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "PlayerCharacter.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collison"));
	collision->OnComponentBeginOverlap.AddDynamic(this, &APickup::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APickup::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString("Overlap"));
	if (OtherActor->GetClass()->IsChildOf(APlayerCharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString("Overlap Player"));
	}
}
