// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyPatrolController.generated.h"

/**
 * 
 */
UCLASS()
class PERCEPTION_API AEnemyPatrolController : public AAIController
{
  GENERATED_BODY()

public:

  AEnemyPatrolController();

  void PerceptionUpdated(const TArray<AActor*>& UpdatedActors);


  UPROPERTY(VisibleAnywhere, BLueprintReadOnly, Category = "Perception")
  class UAIPerceptionComponent* Perception;
};
