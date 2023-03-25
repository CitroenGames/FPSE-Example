// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSE_ExampleGameMode.h"
#include "FPSE_ExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSE_ExampleGameMode::AFPSE_ExampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
