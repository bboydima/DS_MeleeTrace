// Copyright 2023, Robert Lewicki, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include <UObject/WeakInterfacePtr.h>
#include "MeleeTraceInfo.generated.h"

class IMeleeTraceProvider;
class UMeleeTraceShape;

USTRUCT(BlueprintType)
struct MELEETRACE_API FMeleeTraceInfo
{
	GENERATED_BODY()

	FMeleeTraceInfo();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "General")
	FName StartSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "General")
	FName EndSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "General")
	FName MeshTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Instanced, Category = "General")
	TObjectPtr<UMeleeTraceShape> TraceShape;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "General")
	int32 TraceDensity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Debug")
	bool bEnabled;

	FLinearColor DebugTraceColor;
	FLinearColor DebugTraceHitColor;
	mutable TWeakInterfacePtr<const IMeleeTraceProvider> MeleeTraceProvider;
};
