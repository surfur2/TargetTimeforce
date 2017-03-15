// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TargetTimeforce.h"
#include "TargetTimeforceGameMode.h"
#include "TargetTimeforceHUD.h"
#include "TargetTimeforceCharacter.h"

ATargetTimeforceGameMode::ATargetTimeforceGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATargetTimeforceHUD::StaticClass();
}
