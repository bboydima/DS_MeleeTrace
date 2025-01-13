// Copyright 2024 Antix, Inc. All Rights Reserved.

#include "MeleeTraceProvider.h"

TArray<UActorComponent*> IMeleeTraceProvider::GetMeshComponents_Implementation() const
{
	checkf(false, TEXT("IMeleeTraceProvider::GetMeshComponents() missed!"));

	TArray<UActorComponent*> DummyArray;
	return DummyArray;
}
