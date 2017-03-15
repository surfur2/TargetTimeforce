// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetTimeforce.h"
#include "TargetInteractions.h"


// Sets default values for this component's properties
UTargetInteractions::UTargetInteractions()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTargetInteractions::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTargetInteractions::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

