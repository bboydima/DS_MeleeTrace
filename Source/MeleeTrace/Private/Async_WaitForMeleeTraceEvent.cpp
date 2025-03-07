﻿// Copyright 2024, Robert Lewicki, All rights reserved.

#include "Async_WaitForMeleeTraceEvent.h"

#include "Engine/Engine.h"
#include "Engine/World.h"

#include "MeleeTraceCommon.h"
#include "MeleeTraceComponent.h"

UAsync_WaitForMeleeTraceEvent* UAsync_WaitForMeleeTraceEvent::WaitForMeleeTraceEventHit(
	UObject* WorldContextObject, AActor* ActorToWatch)
{
	const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World)
	{
		return nullptr;
	}

	if (!ActorToWatch)
	{
		UE_LOG(
			LogMeleeTrace,
			Error,
			TEXT("%s: Invalid reference for actor to watch passed as parameter"), StringCast<TCHAR>(__FUNCTION__).Get());
		return nullptr;
	}

	auto* MeleeTraceComponent = ActorToWatch->FindComponentByClass<UMeleeTraceComponent>();
	if (!MeleeTraceComponent)
	{
		UE_LOG(
			LogMeleeTrace,
			Error,
			TEXT("%s: Actor to watch doesn't have MeleeTraceComponent attached"), StringCast<TCHAR>(__FUNCTION__).Get());
		return nullptr;
	}

	auto* NewAction = NewObject<UAsync_WaitForMeleeTraceEvent>();
	NewAction->ActorToWatch = ActorToWatch;
	NewAction->MeleeTraceComponent = MeleeTraceComponent;
	NewAction->RegisterWithGameInstance(World);
	return NewAction;
}

void UAsync_WaitForMeleeTraceEvent::Cancel()
{
	if (MeleeTraceComponent.IsValid())
	{
		MeleeTraceComponent->OnTraceHit.RemoveDynamic(this, &ThisClass::HandleTraceHit);
		MeleeTraceComponent->OnTraceStart.RemoveDynamic(this, &ThisClass::HandleTraceStarted);
		MeleeTraceComponent->OnTraceEnd.RemoveDynamic(this, &ThisClass::HandleTraceEnded);
	}

	ActorToWatch.Reset();
	MeleeTraceComponent.Reset();

	Super::Cancel();
}

void UAsync_WaitForMeleeTraceEvent::Activate()
{
	MeleeTraceComponent->OnTraceHit.AddDynamic(this, &ThisClass::HandleTraceHit);
	MeleeTraceComponent->OnTraceStart.AddDynamic(this, &ThisClass::HandleTraceStarted);
	MeleeTraceComponent->OnTraceEnd.AddDynamic(this, &ThisClass::HandleTraceEnded);
}

void UAsync_WaitForMeleeTraceEvent::HandleTraceHit(UMeleeTraceComponent* ThisComponent, const FHitResult& HitResult, FMeleeTraceInstanceHandle TraceHandle)
{
	FAsyncMeleeHitInfo HitInfo;
	HitInfo.OwnerTraceComponent = ThisComponent;
	HitInfo.HitActor = HitResult.GetActor();
	HitInfo.HitLocation = HitResult.ImpactPoint;
	HitInfo.HitNormal = HitResult.ImpactNormal;
	HitInfo.HitBoneName = HitResult.BoneName;
	OnHit.Broadcast(HitInfo, TraceHandle);
}

void UAsync_WaitForMeleeTraceEvent::HandleTraceStarted(
	UMeleeTraceComponent* ThisComponent, FMeleeTraceInstanceHandle TraceHandle)
{
	OnStarted.Broadcast();
}

void UAsync_WaitForMeleeTraceEvent::HandleTraceEnded(
	UMeleeTraceComponent* ThisComponent, int32 HitCount, FMeleeTraceInstanceHandle TraceHandle)
{
	OnEnded.Broadcast();
}
