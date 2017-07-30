// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CheckpointSerializer.generated.h"

USTRUCT()
struct FSerializedPosition
{
	GENERATED_BODY();

	FSerializedPosition();
	FSerializedPosition(const FVector& InVector);
	inline uint8* GetPointerData() const
	{
		return (uint8*)(Components);
	}

	inline void FromPointerData(uint8* BytePointer)
	{
		FMemory::Memcpy(Components, BytePointer, sizeof(float) * 3);
	}

	inline FVector GetAsVector() const
	{
		return FVector(XComponent, YComponent, ZComponent);
	}

	void CreateFromVector(const FVector& InVector);

	union 
	{
		struct { float XComponent, YComponent, ZComponent; };
		float Components[3];
	};
};

UCLASS()
class UCheckpointSerializer : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "ICT2017/Serialization/", meta=(DisplayName = "Serialize Respawn location"))
	static void SerializeCheckpointPosition(const FVector& InPosition);

	UFUNCTION(BlueprintCallable, Category = "ICT2017/Serialization/", meta = (DisplayName = "Read Respawn location from file"))
	static void DeserializeCheckpointPosition(FVector& OutPosition);
};

