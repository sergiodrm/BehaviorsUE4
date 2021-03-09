// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPatrolController.h"


#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AEnemyPatrolController::AEnemyPatrolController()
{
  Perception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception component"));

  UAISenseConfig_Sight* sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));
  Perception->ConfigureSense(*sight);
  Perception->SetDominantSense(sight->GetSenseImplementation());

  Perception->OnPerceptionUpdated.AddDynamic(this, &AEnemyPatrolController::PerceptionUpdated);
}

void AEnemyPatrolController::PerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
  
}
