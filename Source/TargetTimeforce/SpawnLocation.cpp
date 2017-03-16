// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetTimeforce.h"
#include "SpawnLocation.h"
#include "NewTarget.h"

// Sets default values
ASpawnLocation::ASpawnLocation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	lastSpawnTime = 0.0f;

	//ConstructorHelpers::FClassFinder<UShootableTarget> temp(TEXT("Game/FirstPersonCPP/Blueprints/ShootableTarget"));
	//myclass = temp.Class;
}

// Called when the game starts or when spawned
void ASpawnLocation::BeginPlay()
{
	Super::BeginPlay();
	
	lastSpawnTime = FPlatformTime::Seconds();

	spawnVolume = (UBoxComponent*)GetDefaultSubobjectByName(TEXT("SpawnBox"));

}

// Called every frame
void ASpawnLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float currentTime = FPlatformTime::Seconds();
	if (lastSpawnTime + spawnTimer < currentTime)
	{
		lastSpawnTime = FPlatformTime::Seconds();
		SpawnTarget();
	}
}

// Spawn a target inside the spawning box at a random location
void ASpawnLocation::SpawnTarget()
{
	FVector boxBounds = spawnVolume->GetScaledBoxExtent();
	FVector boxOrigin = GetActorLocation();
	float randXLoc = FMath::RandRange(boxOrigin.X - boxBounds.X, boxOrigin.X + boxBounds.X);
	float randYLoc = FMath::RandRange(boxOrigin.Y - boxBounds.Y, boxOrigin.Y + boxBounds.Y);
	float randZLoc = FMath::RandRange(boxOrigin.Z - boxBounds.Z, boxOrigin.Z + boxBounds.Z);
	FVector spawnLocation = FVector(randXLoc, randYLoc, randZLoc);
	GetWorld()->SpawnActor<ANewTarget>(objectToSpawn, spawnLocation, FRotator::ZeroRotator);
}

