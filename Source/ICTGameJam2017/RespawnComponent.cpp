// Fill out your copyright notice in the Description page of Project Settings.

#include "ICTGameJam2017.h"
#include "RespawnComponent.h"
#include "Engine.h"


URespawnComponent::URespawnComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void URespawnComponent::BeginPlay()
{
	Super::BeginPlay();

	ParentActor = GetOwner();
	RespawnLocation = ParentActor->GetActorLocation();
}


// Called every frame
void URespawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void URespawnComponent::SetRespawnLocation(const FVector& NewPosition)
{
	PixelRespawnLocation = RespawnLocation;
	RespawnLocation = NewPosition;
}

void URespawnComponent::RespawnCharacter()
{
	ParentActor->SetActorLocation(RespawnLocation, false, nullptr, ETeleportType::TeleportPhysics);

	if (PixelEnemy == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, "PixelEnemy is nullptr");
	}
	else
	{
		PixelEnemy->SetActorLocation(PixelRespawnLocation);
	}
}
