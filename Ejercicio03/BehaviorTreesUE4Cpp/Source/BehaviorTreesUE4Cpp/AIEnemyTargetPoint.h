// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "AIEnemyTargetPoint.generated.h"

/**
 * 
 */
UCLASS()
class BEHAVIORTREESUE4CPP_API AAIEnemyTargetPoint : public ATargetPoint
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ejercicio")
		int32 m_iPosition;
	
};
