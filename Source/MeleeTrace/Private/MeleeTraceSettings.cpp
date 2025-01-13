// Copyright 2023, Robert Lewicki, All rights reserved.

#include "MeleeTraceSettings.h"

UMeleeTraceSettings::UMeleeTraceSettings()
	: MeleeTraceByType(EMeleeTraceByType::ByChannel)
	, MeleeTraceCollisionChannel(ECC_WorldStatic)
	, ObjectType(ObjectTypeQuery1)
	, ProfileName(NAME_None)
	, TraceColor(FLinearColor::Red)
	, TraceHitColor(FLinearColor::Green)
{
}
