// Fill out your copyright notice in the Description page of Project Settings.

#include "ICTGameJam2017.h"
#include "CheckpointSerializer.h"
#include "Engine.h"


FSerializedPosition::FSerializedPosition()
{
}

FSerializedPosition::FSerializedPosition(const FVector& InVector)
{
	CreateFromVector(InVector);
}

void FSerializedPosition::CreateFromVector(const FVector& InVector)
{
	XComponent = InVector.X;
	YComponent = InVector.Y;
	ZComponent = InVector.Z;
}


void UCheckpointSerializer::SerializeCheckpointPosition(const FVector& InPosition)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, "Calling the thingy");
	FSerializedPosition SerializedPosition(InPosition);

	FString SavePath = FPaths::GameContentDir() + TEXT("last_checkpoint.chkpt");

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, SavePath);
	GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Yellow, FString::FromInt(sizeof(FSerializedPosition)));

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle* SerializedFile = PlatformFile.OpenWrite(*SavePath, !PlatformFile.FileExists(*SavePath));

	if (SerializedFile != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, "The thingy succeeded");
		SerializedFile->Write(SerializedPosition.GetPointerData(), sizeof(FSerializedPosition));
		delete SerializedFile;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, "The thingy failed");
	}
}

void UCheckpointSerializer::DeserializeCheckpointPosition(FVector& OutPosition)
{
	FSerializedPosition ReturnPosition;

	FString SavePath = FPaths::GameContentDir() + TEXT("last_checkpoint.chkpt");

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle* SerializedFile = PlatformFile.OpenRead(*SavePath);

	if (SerializedFile != nullptr)
	{
		uint8* BytesRead = (uint8*)FMemory::Malloc(sizeof(float) * 3);
		SerializedFile->Read(BytesRead, sizeof(float) * 3);
		ReturnPosition.FromPointerData(BytesRead);
		FMemory::Free(BytesRead);
		OutPosition = ReturnPosition.GetAsVector();
	}
	else
	{
		OutPosition = FVector(0.0f, 0.0f, 0.0f);
	}
}


