// Fill out your copyright notice in the Description page of Project Settings.


#include "ClearBlackboardValue.h"
#include "AIEnemyCppController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  AAIEnemyCppController* pController = Cast<AAIEnemyCppController>(OwnerComp.GetOwner());
  UBlackboardComponent* pBlackboardComponent = pController->BrainComponent->GetBlackboardComponent();
  pBlackboardComponent->ClearValue(variableToClear.SelectedKeyName);
  return EBTNodeResult::Succeeded;
}

FString UClearBlackboardValue::GetStaticDescription() const
{
  FString description(TEXT(
    "Limpiar una variable concreta de la blackboard.\nVariable: " + variableToClear.SelectedKeyName.ToString()
  ));
  return description;
}
