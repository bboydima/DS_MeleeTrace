// Copyright 2023, Robert Lewicki, All rights reserved.

#pragma once

#include <CoreMinimal.h>
#include <Engine/DeveloperSettings.h>
#include <Misc/EngineVersionComparison.h>
#include "MeleeTraceSettings.generated.h"

#if UE_VERSION_OLDER_THAN(5, 2, 0)
enum ECollisionChannel;
#else
enum ECollisionChannel : int;
#endif

UENUM(BlueprintType)
enum class EMeleeTraceByType : uint8
{
	ByChannel	UMETA(DisplayName = "By Channel", Description = "By Channel."),
	ByObjectType UMETA(DisplayName = "By Object Type", Description = "By Object Type."),
	ByProfile	UMETA(DisplayName = "By Profile", Description = "By Profile.")
};

UCLASS(Config=Game, DefaultToInstanced)
class MELEETRACE_API UMeleeTraceSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UMeleeTraceSettings();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category = "General")
	EMeleeTraceByType MeleeTraceByType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category = "General", meta = (EditCondition = "MeleeTraceByType == EMeleeTraceByType::ByChannel"))
	TEnumAsByte<ECollisionChannel> MeleeTraceCollisionChannel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category = "General", meta = (EditCondition = "MeleeTraceByType == EMeleeTraceByType::ByObjectType"))
	TEnumAsByte<EObjectTypeQuery> ObjectType;

	UPROPERTY(EditDefaultsOnly,	BlueprintReadOnly, Config,Category = "General", meta = (EditCondition = "MeleeTraceByType == EMeleeTraceByType::ByProfile")) 
	FName ProfileName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category = "Debug")
	FLinearColor TraceColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category = "Debug")
	FLinearColor TraceHitColor;
};
