// Copyright Epic Games, Inc. All Rights Reserved.

#include "SmartEnemyAIGameMode.h"
#include "SmartEnemyAICharacter.h"
#include "UObject/ConstructorHelpers.h"

ASmartEnemyAIGameMode::ASmartEnemyAIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
