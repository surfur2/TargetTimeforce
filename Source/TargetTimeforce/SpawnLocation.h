// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnLocation.generated.h"

UCLASS()
class TARGETTIMEFORCE_API ASpawnLocation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnLocation();

	// Spawn a target at current location
	void SpawnTarget();

	// How often do we spawn our objects
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
		float spawnTimer = 0.25f;

	// The spawn volume that defines the spawn space.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
		UBoxComponent* spawnVolume;

	UPROPERTY(EditAnywhere, Category = Spawning)
		TSubclassOf<class ANewTarget> objectToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Last spawn time
	float lastSpawnTime;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
