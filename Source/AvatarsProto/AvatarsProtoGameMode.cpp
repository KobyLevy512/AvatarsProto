// Copyright Epic Games, Inc. All Rights Reserved.

#include "AvatarsProtoGameMode.h"
#include "AvatarsProtoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAvatarsProtoGameMode::AAvatarsProtoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
