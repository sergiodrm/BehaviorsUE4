// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckPlayerVisibilityBTService.h"
#include "AIEnemyCppController.h"

void UCheckPlayerVisibilityBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
  AAIEnemyCppController* pController = Cast<AAIEnemyCppController>(OwnerComp.GetOwner());
  pController->CheckPlayerVisibility();
}
