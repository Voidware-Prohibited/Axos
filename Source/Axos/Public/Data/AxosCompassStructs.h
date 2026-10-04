// MIT

#pragma once

#include "CoreMinimal.h"
#include "AxosCompassMarkerStructs.h"
#include "GameplayTagContainer.h"
#include "Utility/AxosGameplayTags.h"
#include "Fonts/SlateFontInfo.h"
#include "AxosCompassStructs.generated.h"

USTRUCT(BlueprintType)
struct AXOS_API FAxosHorizontalCompassMaterialParameterNames
{
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName EnableCompassMaskMaterialParameterName {"EnableCompassMask"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName EnableCompassMaskImageMaterialParameterName {"EnableCompassMaskImage"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName CompassMaskImageMaterialParameterName {"CompassMaskImage"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName EnableAzimuthBoxMaskMaterialParameterName {"EnableAzimuthBoxMask"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName CompassBoxMaskCenterXMaterialParameterName {"CompassBoxMaskCenterX"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName CompassBoxMaskCenterYMaterialParameterName {"CompassBoxMaskCenterY"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName CompassBoxMaskWidthMaterialParameterName {"CompassBoxMaskWidth"};
	
	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName CompassBoxMaskHeightMaterialParameterName {"CompassBoxMaskHeight"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName CompassBoxMaskFalloffParameterName {"CompassBoxMaskEdgeFalloff"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName AzimuthBoxMaskCenterXMaterialParameterName {"AzimuthBoxMaskCenterX"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName AzimuthBoxMaskCenterYMaterialParameterName {"AzimuthBoxMaskCenterY"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName AzimuthBoxMaskWidthMaterialParameterName {"AzimuthBoxMaskWidth"};
	
	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName AzimuthBoxMaskHeightMaterialParameterName {"AzimuthBoxMaskHeight"};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName AzimuthBoxMaskFalloffParameterName {"AzimuthBoxMaskEdgeFalloff"};
	
	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FName CompassOpacityParameterName {"Opacity"};

	bool operator==(const FAxosHorizontalCompassMaterialParameterNames& other) const
	{
		return (other.EnableCompassMaskMaterialParameterName == EnableCompassMaskMaterialParameterName);
	}
};

USTRUCT(BlueprintType)
struct AXOS_API FAxosHorizontalCompassMaterialSettings
{
	GENERATED_BODY()

	// Enable the use Retention Widget Mask Material to Mask the Compass
	UPROPERTY(Config, EditAnywhere, Category = "Compass|General")
	bool bEnableCompassMask {true};

	// Material to use for Compass Mask
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	UMaterialInterface* CompassMaskMaterial {nullptr};

	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FAxosHorizontalCompassMaterialParameterNames CompassMaskMaterialParameterNames;
	
	UPROPERTY(Config, EditAnywhere, Category = "Material Parameter Names")
	FAxosHorizontalCompassMarkerMaterialSettings MarkerSettings;

	bool operator==(const FAxosHorizontalCompassMaterialSettings& other) const
	{
		return (other.CompassMaskMaterial == CompassMaskMaterial);
	}
};

USTRUCT(BlueprintType)
struct FAxosHorizontalCompassTickLengthSettings
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
    float Length {10.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	float Thickness {2.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	FLinearColor Color {FLinearColor::White};
};

USTRUCT(BlueprintType)
struct FAxosHorizontalCompassTickSettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	float TopPadding {10.0};
	
	// Tick (Line) Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	float Spacing {10.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	FAxosHorizontalCompassTickLengthSettings Short;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	FAxosHorizontalCompassTickLengthSettings Medium;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	FAxosHorizontalCompassTickLengthSettings Long;
};

USTRUCT(BlueprintType)
struct AXOS_API FAxosTextEnclosure
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	FString Prefix {"["};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	FString Suffix {"]"};

	bool operator==(const FAxosTextEnclosure& other) const
	{
		return (other.Prefix == Prefix) && (other.Suffix == Suffix);
	}
};

USTRUCT(BlueprintType)
struct FAxosTextProperties
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDisplay {true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Content", meta = (EditCondition = "bDisplay"))
	FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance", meta = (EditCondition = "bDisplay"))
	FLinearColor ColorAndOpacity {FLinearColor::White};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance", meta = (EditCondition = "bDisplay"))
	FSlateFontInfo Font;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance", meta = (EditCondition = "bDisplay"))
	FSlateBrush StrikeBrush;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance", meta = (EditCondition = "bDisplay"))
	FVector2D ShadowOffset {0.0f, 0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance", meta = (EditCondition = "bDisplay"))
	uint8 TransformationPolicy = static_cast<uint8>(ETextTransformPolicy::None);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance", meta = (EditCondition = "bDisplay"))
	TEnumAsByte<ETextJustify::Type> Justification {ETextJustify::Center};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance", meta = (EditCondition = "bDisplay"))
	FMargin Margin {0.0f, 0.0f, 0.0f, 0.0f};
	
};

USTRUCT(BlueprintType)
struct FAxosHorizontalCompassSettings
{
	GENERATED_BODY()

	// Settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|General")
    float FOVAngle {90.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	FAxosHorizontalCompassTickSettings TickSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	FAxosTextProperties TickLabels;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|General")
	bool bEdgeClampOffScreenMarkers {true};

	// OLD
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	float TicksTopPadding {10.0};
	
	// Tick (Line) Settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
    float TickSpacing {10.0};

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
    float ShortTickLength {10.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	float ShortTickThickness {2.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	FLinearColor ShortTickColor {FLinearColor::White};

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
    float MediumTickLength {15.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	float MediumTickThickness {2.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	FLinearColor MediumTickColor {FLinearColor::White};

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
    float LongTickLength {25.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	float LongTickThickness {2.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
	FLinearColor LongTickColor {FLinearColor::White};

	// Text (Bearing Number) Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	bool bDisplayBearingNumbers {true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FSlateFontInfo TextFont;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	float TextTopPadding {5.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	float TextLeftPadding {10.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FLinearColor TextColor {FLinearColor::White};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	float TextSize {14.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	TEnumAsByte<ETextJustify::Type> TextJustification {ETextJustify::Center};
};

USTRUCT(BlueprintType)
struct FAxosCompassMarkerData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	FText Label;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	FVector Location {FVector::ZeroVector};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	float Angle {0.0f};

	// Image
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	UTexture2D* Icon  {nullptr};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass", meta = (Categories = "Axos.Marker.State"))
	FGameplayTag State {AxosTags::Marker::State::Active};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FLinearColor IconForegroundColor {FLinearColor::White};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FLinearColor IconBackgroundColor {FLinearColor::White};

	
	
	// Text (Azimuth Number) Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FAxosTextProperties NameText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FAxosTextProperties DistanceText;

	bool operator==(const FAxosCompassMarkerData& other) const
	{
		return (Label.EqualTo(other.Label));
	}
};

USTRUCT(BlueprintType)
struct FAxosHorizontalCompassWidgetBlueprintSettings
{
	GENERATED_BODY()

	// Text (Azimuth Number) Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FAxosTextProperties AzimuthTextProperties;

	// Characters to enclose Azimuth with
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon", meta = (ShowOnlyInnerProperties))
	FAxosTextEnclosure AzimuthTextEnclosure;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	float CompassOpacity {1.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	float AzimuthOpacity {1.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	bool bEnableAzimuthBoxMask {true};

	// Enable the use Retention Widget Mask Material to Mask the Compass
	UPROPERTY(Config, EditAnywhere, Category = "Compass")
	bool bEnableCompassMask {true};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	bool bEnableCompassMaskImage {true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass Box Mask")
	FVector2D CompassBoxMaskCenter {0.0f, 0.5f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass Box Mask")
	FVector2D CompassBoxMaskSize {0.04f, 0.175f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass Box Mask")
	float CompassBoxMaskEdgeFalloff {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Azimuth Box Mask")
	FVector2D AzimuthBoxMaskCenter {0.0f, 0.5f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Azimuth Box Mask")
	FVector2D AzimuthBoxMaskSize {0.04f, 0.175f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Azimuth Box Mask")
	float AzimuthBoxMaskEdgeFalloff {0.0f}; 
};

USTRUCT(BlueprintType)
struct FAxosHorizontalCompassOpacitySettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	float CompassOpacity {1.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	float AzimuthOpacity {1.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	float TickOpacity {1.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	float TickLabelOpacity {1.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	float MarkerMaxOpacity {1.0f};	
};

USTRUCT(BlueprintType)
struct FAxosHorizontalCompassPlayerCustomizationSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	bool bEdgeClampOffScreenMarkers {true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass")
	FAxosHorizontalCompassOpacitySettings OpacitySettings;
};