// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AIEnemyCppController.h"
#include "ChangeMovementSpeedBTTask.generated.h"

/**
 * 
 */
UCLASS()
class BEHAVIORTREESUE4CPP_API UChangeMovementSpeedBTTask : public UBTTaskNode
{
	GENERATED_BODY()

public:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

	/**
	 * Properties
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		TEnumAsByte<SpeedSelector> speedSelector;
};
