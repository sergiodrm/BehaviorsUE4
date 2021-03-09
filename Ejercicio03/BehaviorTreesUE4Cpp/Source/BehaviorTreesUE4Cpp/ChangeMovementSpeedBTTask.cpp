// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeMovementSpeedBTTask.h"

EBTNodeResult::Type UChangeMovementSpeedBTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  AAIEnemyCppController* pController = Cast<AAIEnemyCppController>(OwnerComp.GetOwner());
  pController->ChangeControlledPawnSpeed(speedSelector);
  return EBTNodeResult::Succeeded;
}

FString UChangeMovementSpeedBTTask::GetStaticDescription() const
{
  FString description(
    TEXT("Cambiar la velocidad de movimiento del character controlado.")
  );
  return description;
}
