// Fill out your copyright notice in the Description page of Project Settings.

#include "ICTGameJam2017.h"
#include "Engine.h"
#include "Runtime/Core/Public/UObject/ScriptDelegates.h"
#include "CheckpointComponent.h"
#include "RespawnComponent.h"


// Sets default values for this component's properties
UCheckpointComponent::UCheckpointComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCheckpointComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	TScriptDelegate<FWeakObjectPtr> OverlapDelegate;
	OverlapDelegate.BindUFunction(this, "OnActorBeginOverlap");

	GetOwner()->FindComponentByClass<UStaticMeshComponent>()->OnComponentBeginOverlap.Add(OverlapDelegate);
}


// Called every frame
void UCheckpointComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UCheckpointComponent::OnActorBeginOverlap()
{
	// ABSOLUTELY DISGUSTING!!!
	// Don't leave this code if you want to have the game run well

	TArray<AActor*> OverlappingActors;
	GetOwner()->GetOverlappingActors(OverlappingActors);

	URespawnComponent* RespawnComponent = nullptr;
	
	for (uint32 i = 0; i < (uint32)OverlappingActors.Num(); i++)
	{
		AActor* SetActor = OverlappingActors[i];
		UActorComponent* FoundComponent = SetActor->GetComponentByClass(URespawnComponent::StaticClass());
		if (FoundComponent != nullptr)
		{
			RespawnComponent = Cast<URespawnComponent>(FoundComponent);
			break;
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::White, "Setting respawn position");

	if (RespawnComponent != nullptr)
		RespawnComponent->RespawnLocation = GetOwner()->GetActorLocation() + FVector(0.f, 0.f, ActorRespawnHeightOffset);
}
