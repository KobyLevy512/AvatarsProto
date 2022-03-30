// Copyright Epic Games, Inc. All Rights Reserved.

#include "AvatarsProtoGameMode.h"
#include "PlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAvatarsProtoGameMode::AAvatarsProtoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Player/MyPlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
