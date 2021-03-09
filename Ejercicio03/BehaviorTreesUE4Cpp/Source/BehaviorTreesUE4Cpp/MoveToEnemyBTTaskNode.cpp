// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveToEnemyBTTaskNode.h"
#include "AIEnemyCppController.h"

UMoveToEnemyBTTaskNode::UMoveToEnemyBTTaskNode()
{
  bNotifyTick = true;
}

EBTNodeResult::Type UMoveToEnemyBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  return EBTNodeResult::InProgress;
}

void UMoveToEnemyBTTaskNode::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
  AAIEnemyCppController* pController = Cast<AAIEnemyCppController>(OwnerComp.GetOwner());
  EPathFollowingRequestResult::Type moveToActorResult = pController->MoveToEnemy();
  if (moveToActorResult == EPathFollowingRequestResult::AlreadyAtGoal)
  {
    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
  }
}

FString UMoveToEnemyBTTaskNode::GetStaticDescription() const
{
  return TEXT("Persigue al personaje principal.");
}
