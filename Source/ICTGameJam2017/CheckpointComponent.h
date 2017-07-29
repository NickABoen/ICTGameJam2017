// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CheckpointComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICTGAMEJAM2017_API UCheckpointComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UCheckpointComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	virtual void OnActorBeginOverlap();
	
	UPROPERTY(EditAnywhere)
	float ActorRespawnHeightOffset : 0.0f; // Might not ever use this?
};
