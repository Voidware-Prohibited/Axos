// MIT

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "Data/AxosCompassStructs.h"
#include "AxosMarkerStylesDataAsset.generated.h"

USTRUCT(BlueprintType)
struct AXOS_API FAxosMarkerStyle
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	bool bDebugMode {false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	TSoftObjectPtr<UTexture2D> IconTexture {nullptr};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FAxosTextProperties LabelTextProperties;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FAxosTextProperties DistanceTextProperties;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	bool bEnableChannelPackedIcon {false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	bool bEnableIconColorization {false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	FLinearColor IconPrimaryColorAndOpacity {FLinearColor::White};

	// Pack Secondary elements in the Green channel of the Icon Texture to use this effect.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	bool bEnableSecondaryColor {false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	FLinearColor IconSecondaryColorAndOpacity {FLinearColor::White};

	// Effects
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	bool bEnablePulsing {false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	float PulseRate {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	float PulseMinOpacity {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	float PulseMaxOpacity {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	bool bEnablePrimaryColorGlowEffect {false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	FLinearColor IconPrimaryGlowColorAndOpacity {FLinearColor::White};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	float PrimaryColorGlowRate {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	float PrimaryColorGlowMinOpacity {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	float PrimaryColorGlowMaxOpacity {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	bool bEnableSecondaryColorGlowEffect {false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	FLinearColor IconSecondaryGlowColorAndOpacity {FLinearColor::White};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	float SecondaryColorGlowRate {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	float SecondaryColorGlowMinOpacity {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	float SecondaryColorGlowMaxOpacity {0.0f};

	bool operator==(const FAxosMarkerStyle& other) const
	{
		return (other.bDebugMode == bDebugMode);
	}
};


/**
 * 
 */
UCLASS()
class AXOS_API UAxosMarkerStylesDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MarkerStyles", meta=(ForceInlineRow))
	TMap<FGameplayTag, FAxosMarkerStyle> MarkerStyles;

	// Characters to enclose Distance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon", meta = (ShowOnlyInnerProperties))
	FAxosTextEnclosure DistanceTextBracketCharacters;
};
