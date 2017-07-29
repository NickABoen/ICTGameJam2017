// Fill out your copyright notice in the Description page of Project Settings.

#include "ICTGameJam2017.h"
#include "RespawnComponent.h"


URespawnComponent::URespawnComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void URespawnComponent::BeginPlay()
{
	Super::BeginPlay();

	ParentActor = GetOwner();
}


// Called every frame
void URespawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


void URespawnComponent::RespawnCharacter()
{
	ParentActor->SetActorLocation(RespawnLocation, false, nullptr, ETeleportType::TeleportPhysics);
}
