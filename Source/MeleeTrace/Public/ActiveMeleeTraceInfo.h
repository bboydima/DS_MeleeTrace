﻿// Copyright 2023, Robert Lewicki, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CollisionShape.h"

#include "ActiveMeleeTraceInfo.generated.h"

class AActor;
class UMeshComponent;

USTRUCT(BlueprintType)
struct MELEETRACE_API FMeleeTraceInstanceHandle
{
	GENERATED_BODY()

	FMeleeTraceInstanceHandle() = default;
	FMeleeTraceInstanceHandle(uint32 InTraceHash) : TraceHash(InTraceHash) {};

	FString ToString() const;
	
	UPROPERTY()
	uint32 TraceHash = TNumericLimits<uint32>::Max();

	bool operator==(const FMeleeTraceInstanceHandle& Other) const { return TraceHash == Other.TraceHash; }
};

USTRUCT()
struct MELEETRACE_API FActiveMeleeTraceInfo
{
	GENERATED_BODY()

	FActiveMeleeTraceInfo();

	FString ToString() const;

	FMeleeTraceInstanceHandle TraceHandle;
	int32 TraceDensity;
	FQuat RotationOffset;
	FCollisionShape TraceCollisionShape;
	TWeakObjectPtr<UMeshComponent> SourceMeshComponent;
	TSet<TWeakObjectPtr<AActor>> HitActors;
	TArray<FVector> PreviousFrameSampleLocations;
	FName StartSocketName;
	FName EndSocketName;
	FLinearColor DebugTraceColor;
	FLinearColor DebugTraceHitColor;
};
