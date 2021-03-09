// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CheckPlayerVisibilityBTService.generated.h"

/**
 * 
 */
UCLASS()
class BEHAVIORTREESUE4CPP_API UCheckPlayerVisibilityBTService : public UBTService
{
	GENERATED_BODY()

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
