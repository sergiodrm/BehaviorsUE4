// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIEnemyCppController.generated.h"

UENUM(BlueprintType)
enum SpeedSelector
{
  PatrolSpeed,
	ChaseSpeed
};

/**
 * 
 */
UCLASS()
class BEHAVIORTREESUE4CPP_API AAIEnemyCppController : public AAIController
{
	GENERATED_BODY()

public:

	AAIEnemyCppController();

	UFUNCTION(BlueprintCallable, Category = "Ejercicio")
		void UpdateNextTargetPoint();

	UFUNCTION(BlueprintCallable, Category = "Ejercicio")
		void CheckNearbyEnemy();

	UFUNCTION(BlueprintCallable, Category = "Ejercicio")
		EPathFollowingRequestResult::Type MoveToEnemy();

	UFUNCTION(BlueprintCallable, Category = "Ejercicio|Mejora")
		void CheckPlayerVisibility();

	void ChangeControlledPawnSpeed(SpeedSelector _eSpeed);

	/**
	 * Properties
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy velocities")
		float chaseSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy velocities")
		float patrolSpeed;
};
