// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckNearbyEnemyBTService.h"
#include "AIEnemyCppController.h"


void UCheckNearbyEnemyBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
  Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
  AAIEnemyCppController* pController = Cast<AAIEnemyCppController>(OwnerComp.GetOwner());
  pController->CheckNearbyEnemy();
}
