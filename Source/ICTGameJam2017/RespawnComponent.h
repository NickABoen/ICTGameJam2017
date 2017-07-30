// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RespawnComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICTGAMEJAM2017_API URespawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URespawnComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetRespawnLocation(const FVector& NewPosition);

	UFUNCTION(BlueprintCallable)
	void RespawnCharacter();

	AActor* ParentActor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = bAllowEdit))
	AActor* PixelEnemy; 
	
private:

	FVector RespawnLocation;
	FVector PixelRespawnLocation;
};
