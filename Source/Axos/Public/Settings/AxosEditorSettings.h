// MIT

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Data/AxosMarkerStylesDataAsset.h"
#include "Data/AxosCompassStructs.h"
#include "Data/AxosCompassMarkerStructs.h"
#include "Engine/DeveloperSettings.h"
#include "Utility/AxosGameplayTags.h"
#include "AxosEditorSettings.generated.h"
/**
 * 
 */

USTRUCT(BlueprintType)
struct AXOS_API FAxosArchitectureSettings
{
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere, Category = "Architecture")
	FGameplayTag ExecutionMode {AxosTags::ExecutionMode::Direct};

	bool operator==(const FAxosArchitectureSettings& other) const
	{
		return (other.ExecutionMode == ExecutionMode);
	}
};

USTRUCT(BlueprintType)
struct AXOS_API FAxosDebugSettings
{
	GENERATED_BODY()

	// Enables Logging
	UPROPERTY(Config, EditAnywhere, Category = "Debug")
	bool bDebugMode {false};

	// The level of Verbosity of the Axos Log Output
	UPROPERTY(Config, EditAnywhere, Category = "Debug")
	uint8 LogVerbosity {ELogVerbosity::Log};

	bool operator==(const FAxosDebugSettings& other) const
	{
		return (other.bDebugMode == bDebugMode) && (other.LogVerbosity == LogVerbosity);
	}
};

USTRUCT(BlueprintType)
struct AXOS_API FAxosHorizontalCompassGlobalSettings
{
	GENERATED_BODY()

	// Enables Offscreen Markers to remain clamped to the Left or Right edge of the widget.
	UPROPERTY(Config, EditAnywhere, Category = "Compass|General")
	bool bEdgeClampOffScreenMarkers {true};
	
	UPROPERTY(Config, EditAnywhere, Category = "Architecture")
	FAxosHorizontalCompassMaterialSettings HorizontalCompassMaterialSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	FAxosHorizontalCompassMarkerStyleSettings HorizontalCompassMarkerStyleSettings;

	bool operator==(const FAxosHorizontalCompassGlobalSettings& other) const
	{
		return (other.HorizontalCompassMaterialSettings == HorizontalCompassMaterialSettings) && (other.HorizontalCompassMarkerStyleSettings == HorizontalCompassMarkerStyleSettings);
	}
};


UCLASS(config = Axos, DefaultConfig)
class AXOS_API UAxosEditorSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UAxosEditorSettings();

	UPROPERTY(Config, EditAnywhere, Category = "Architecture")
	FAxosArchitectureSettings ArchitectureSettings;

	UPROPERTY(Config, EditAnywhere, Category = "Architecture")
	FAxosHorizontalCompassGlobalSettings HorizontalCompassSettings;

	UPROPERTY(Config, EditAnywhere, Category = "Debug")
	FAxosDebugSettings DebugSettings;
	
#if WITH_EDITOR
	virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
	virtual FText GetSectionText() const override { return NSLOCTEXT("Axos", "AxosSectionText", "Axos Editor Settings"); }
	virtual FText GetSectionDescription() const override { return NSLOCTEXT("Axos", "AxosSectionDesc", "Configure Axos Editor Settings"); }
#endif
};
