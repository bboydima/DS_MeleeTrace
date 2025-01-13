// Copyright 2023, Robert Lewicki, All rights reserved.

#include "MeleeTraceInfo.h"

FMeleeTraceInfo::FMeleeTraceInfo()
	: StartSocketName(NAME_None)
	, EndSocketName(NAME_None)
	, MeshTag(NAME_None)
	, TraceDensity(5)
	, bEnabled(true)
	, DebugTraceColor(FLinearColor::White)
	, DebugTraceHitColor(FLinearColor::White)
{
}
