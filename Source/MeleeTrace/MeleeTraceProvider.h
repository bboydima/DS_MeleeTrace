// Copyright 2024 Antix, Inc. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include <UObject/Interface.h>
#include "MeleeTraceProvider.generated.h"

class UActorComponent;

UINTERFACE(Blueprintable)
class MELEETRACE_API UMeleeTraceProvider : public UInterface
{
	GENERATED_BODY()
};

class MELEETRACE_API IMeleeTraceProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	TArray<UActorComponent*> GetMeshComponents() const;

	virtual TArray<UActorComponent*> GetMeshComponents_Implementation() const;
};
