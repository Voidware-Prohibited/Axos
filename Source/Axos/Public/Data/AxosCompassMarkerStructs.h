// MIT

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Utility/AxosGameplayTags.h"
#include "AxosCompassMarkerStructs.generated.h"

class UAxosMarkerStylesDataAsset;

/**
 * 
 */

USTRUCT(BlueprintType)
struct AXOS_API FAxosHorizontalCompassMarkerMaterialParameterNames
{
	GENERATED_BODY()
	
	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName MarkerTextureMaterialParameterName {"MarkerTexture"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName MarkerForegroundColor1MaterialParameterName {"Color1"};
	
	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName MarkerForegroundColor2MaterialParameterName {"Color2"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName MarkerPulseRateMaterialParameterName {"PulseRate"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName MarkerPulseMinOpacityMaterialParameterName {"PulseMinOpacity"};
	
	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName MarkerPulseMaxOpacityMaterialParameterName {"PulseMaxOpacity"};

	bool operator==(const FAxosHorizontalCompassMarkerMaterialParameterNames& other) const
	{
		return (other.MarkerTextureMaterialParameterName == MarkerTextureMaterialParameterName);
	}
};

USTRUCT(BlueprintType)
struct AXOS_API FAxosHorizontalCompassMarkerMaterialSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	UMaterialInterface* IconMaterial {nullptr};
	
	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FAxosHorizontalCompassMarkerMaterialParameterNames MarkerMaterialParameterNames;

	bool operator==(const FAxosHorizontalCompassMarkerMaterialSettings& other) const
	{
		return (other.IconMaterial == IconMaterial);
	}
};

USTRUCT(BlueprintType)
struct AXOS_API FAxosHorizontalCompassMarkerStyleSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	TSoftObjectPtr<UAxosMarkerStylesDataAsset> MarkerStylesDataAsset {nullptr};

	bool operator==(const FAxosHorizontalCompassMarkerStyleSettings& other) const
	{
		return (other.MarkerStylesDataAsset == MarkerStylesDataAsset);
	}
};