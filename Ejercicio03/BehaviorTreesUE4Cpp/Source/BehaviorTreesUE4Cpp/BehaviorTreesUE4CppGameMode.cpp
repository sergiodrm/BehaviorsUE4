// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BehaviorTreesUE4CppGameMode.h"
#include "BehaviorTreesUE4CppPlayerController.h"
#include "BehaviorTreesUE4CppCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABehaviorTreesUE4CppGameMode::ABehaviorTreesUE4CppGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABehaviorTreesUE4CppPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}