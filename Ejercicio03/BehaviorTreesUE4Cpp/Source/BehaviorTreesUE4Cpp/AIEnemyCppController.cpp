// Fill out your copyright notice in the Description page of Project Settings.


#include "AIEnemyCppController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BrainComponent.h"
#include "AIEnemyTargetPoint.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "GameFramework/CharacterMovementComponent.h"

AAIEnemyCppController::AAIEnemyCppController()
: patrolSpeed(150.f), chaseSpeed(500.f)
{}

void AAIEnemyCppController::UpdateNextTargetPoint()
{
  UBlackboardComponent* pBlackboardComponent = BrainComponent->GetBlackboardComponent();
  int32 iTargetPosition = pBlackboardComponent->GetValueAsInt("TargetPointIndex");
  if (iTargetPosition >= 4)
  {
    iTargetPosition = 0;
    pBlackboardComponent->SetValueAsInt("TargetPointIndex", iTargetPosition);
  }

  for (TActorIterator<AAIEnemyTargetPoint> It(GetWorld()); It; ++It)
  {
    AAIEnemyTargetPoint* pTargetPoint = *It;
    if (iTargetPosition == pTargetPoint->m_iPosition)
    {
      pBlackboardComponent->SetValueAsVector("TargetPointPosition", pTargetPoint->GetActorLocation());
      break;
    }
  }
  
  pBlackboardComponent->SetValueAsInt("TargetPointIndex", iTargetPosition + 1);
}

void AAIEnemyCppController::CheckNearbyEnemy()
{
  APawn* pPawn = GetPawn();
  FVector multiSphereStart = pPawn->GetActorLocation();
  FVector multiSphereEnd = multiSphereStart + FVector(0.f, 0.f, 15.f);
  TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;
  objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));
  TArray<AActor*> actorsToIgnore;
  actorsToIgnore.Add(pPawn);
  TArray<FHitResult> outHits;
  bool bResult = UKismetSystemLibrary::SphereTraceMultiForObjects(
    GetWorld(),
    multiSphereStart,
    multiSphereEnd,
    700,
    objectTypes,
    false,
    actorsToIgnore,
    EDrawDebugTrace::ForDuration,
    outHits,
    true
  );

  UBlackboardComponent* pBlackboardComponent = BrainComponent->GetBlackboardComponent();
  if (bResult)
  {
    for (int32 i = 0; i < outHits.Num(); ++i)
    {
      FHitResult hit = outHits[i];
      APawn* pPlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
      if (hit.GetActor() == pPlayerPawn)
      {
        pBlackboardComponent->SetValueAsObject("TargetActorToFollow", pPlayerPawn);
        break;
      }
    }
  }
  else
  {
    pBlackboardComponent->SetValueAsObject("TargetActorToFollow", nullptr);
  }
}

EPathFollowingRequestResult::Type AAIEnemyCppController::MoveToEnemy()
{
  UBlackboardComponent* pBlackboardComponent = BrainComponent->GetBlackboardComponent();
  AActor* pPlayerActor = Cast<AActor>(pBlackboardComponent->GetValueAsObject("TargetActorToFollow"));
  EPathFollowingRequestResult::Type moveToActorResult = MoveToActor(pPlayerActor);
  return moveToActorResult;
}

void AAIEnemyCppController::CheckPlayerVisibility()
{
  UBlackboardComponent* pBlackboardComponent = BrainComponent->GetBlackboardComponent();
  APawn* pPawn = GetPawn();
  APawn* pTarget = Cast<APawn>(pBlackboardComponent->GetValueAsObject("TargetActorToFollow"));
  if (pTarget == nullptr)
  {
    pBlackboardComponent->SetValueAsBool("PlayerVisibility", false);
    return;
  }

  // Get the start and the end of the trace
  FVector rayStart = pPawn->GetActorLocation();
  FVector rayEnd = pTarget->GetActorLocation();

  // Trace setting
  TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;
  objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Camera));
  TArray<AActor*> actorsToIgnore;
  actorsToIgnore.Add(GetPawn());

  // Ray tracing
  FHitResult outHit;
  FCollisionQueryParams collisionParams;
  collisionParams.AddIgnoredActor(pPawn);
  bool bResult = GetWorld()->LineTraceSingleByChannel(outHit, rayStart, rayEnd, ECC_Camera, collisionParams);

  // Check result
  if (bResult && outHit.GetActor() == pTarget)
  {
    pBlackboardComponent->SetValueAsBool("PlayerVisibility", true);
    pBlackboardComponent->SetValueAsVector("TargetActorLastKnownPosition", pTarget->GetActorLocation());
  }
  else pBlackboardComponent->SetValueAsBool("PlayerVisibility", false);
}

void AAIEnemyCppController::ChangeControlledPawnSpeed(SpeedSelector _eSpeed)
{
  ACharacter* pControlledCharacter = Cast<ACharacter>(GetPawn());
  UCharacterMovementComponent* pMovementComponent = pControlledCharacter->GetCharacterMovement();
  switch(_eSpeed)
  {
  case SpeedSelector::PatrolSpeed:
    pMovementComponent->MaxWalkSpeed = patrolSpeed;
    break;
  case SpeedSelector::ChaseSpeed:
    pMovementComponent->MaxWalkSpeed = chaseSpeed;
    break;
  }
}
