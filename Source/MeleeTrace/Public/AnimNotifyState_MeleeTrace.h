﻿// Copyright 2023, Robert Lewicki, All rights reserved.

#pragma once

#include <CoreMinimal.h>
#include <Animation/AnimNotifies/AnimNotifyState.h>
#include <Misc/EngineVersionComparison.h>
#include "MeleeTraceInfo.h"
#include "AnimNotifyState_MeleeTrace.generated.h"

UCLASS(DisplayName = "Melee Trace")
class MELEETRACE_API UAnimNotifyState_MeleeTrace : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UAnimNotifyState_MeleeTrace();

#if UE_VERSION_OLDER_THAN(5, 0, 0)
	virtual void NotifyBegin(
		USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
#else
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation,
		float TotalDuration,
		const FAnimNotifyEventReference& EventReference) override;		
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation,
		const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation,
		float FrameDeltaTime,
		const FAnimNotifyEventReference& EventReference) override;
#endif

	UPROPERTY(EditInstanceOnly, Category = "Setup")
	FMeleeTraceInfo MeleeTraceInfo;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, Category = "Debug")
	bool bShouldDrawDebugInEditor;

	UPROPERTY(EditInstanceOnly, Category = "Debug")
	float DebugDrawDuration;

	UPROPERTY(EditInstanceOnly, Category = "Debug")
	FLinearColor DebugTraceColor;

	UPROPERTY(EditInstanceOnly, Category = "Debug")
	FLinearColor DebugTraceHitColor;

	TArray<FVector> PreviousFrameSamples;
	TWeakObjectPtr<UMeshComponent> DebugMeshComponent = nullptr;
#endif
};
