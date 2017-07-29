// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ICTGameJam2017.h"
#include "ICTGameJam2017GameMode.h"
#include "ICTGameJam2017Character.h"

AICTGameJam2017GameMode::AICTGameJam2017GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
