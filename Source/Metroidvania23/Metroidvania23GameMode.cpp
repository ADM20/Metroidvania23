// Copyright Epic Games, Inc. All Rights Reserved.

#include "Metroidvania23GameMode.h"
#include "Metroidvania23Character.h"
#include "UObject/ConstructorHelpers.h"

AMetroidvania23GameMode::AMetroidvania23GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
