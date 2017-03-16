// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetTimeforce.h"
#include "NewTarget.h"


// Sets default values
ANewTarget::ANewTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANewTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANewTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

