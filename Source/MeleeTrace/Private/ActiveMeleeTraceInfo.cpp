// Copyright 2023, Robert Lewicki, All rights reserved.

#include "ActiveMeleeTraceInfo.h"

// FActiveMeleeTraceInfo
FActiveMeleeTraceInfo::FActiveMeleeTraceInfo()
	: TraceDensity(1)
	, RotationOffset(FQuat::Identity)
	, DebugTraceColor(FLinearColor::White)
	, DebugTraceHitColor(FLinearColor::White)
{
}

FString FActiveMeleeTraceInfo::ToString() const
{
	return TraceHandle.ToString();
}

// FMeleeTraceInstanceHandle
FString FMeleeTraceInstanceHandle::ToString() const
{
	return FString::FormatAsNumber(TraceHash);
}
