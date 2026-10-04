// MIT

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Data/AxosCompassStructs.h"
#include "AxosHorizontalCompassWidget.generated.h"

/**
 * 
 */
UCLASS(meta = (PrioritizeCategories = "Combat Stats Movement"))
class AXOS_API UAxosHorizontalCompassWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UAxosHorizontalCompassWidget(const FObjectInitializer& ObjectInitializer);

	// Blueprint Native Functions

	// Updates Rotation of Compass on NativeTick.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Compass")
	void UpdateCompassRotation(float PlayerRotation);
	virtual void UpdateCompassRotation_Implementation(float PlayerRotation);

	// Updates Markers on NativeTick
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Compass")
	void UpdateMarkers(const TArray<FAxosCompassMarkerData>& NewMarkerData);
	virtual void UpdateMarkers_Implementation(const TArray<FAxosCompassMarkerData>& NewMarkerData);

	// Override to provide the widget with Compass Marker Data
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Compass")
	TArray<FAxosCompassMarkerData> GetPlayerCompassMarkers();
	virtual TArray<FAxosCompassMarkerData> GetPlayerCompassMarkers_Implementation();

	// Player Configuration
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Compass")
	float GetPlayerFOV();
	virtual float GetPlayerFOV_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Compass")
	float GetPlayerAzimuth();
	virtual float GetPlayerAzimuth_Implementation();
	
	// Player UI Customizations

	// Get Player defined Font Scale to enable widgets to adapt to Font Scale.
	// Retrieve this value from a Player UI Settings Save Data.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Compass")
	float GetPlayerFontScale();
	virtual float GetPlayerFontScale_Implementation();

	// Get Player-defined Compass Opacity Settings.
	// Retrieve this value from a Player UI Settings Save Data.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Compass")
	FAxosHorizontalCompassPlayerCustomizationSettings GetPlayerHorizontalCompassPlayerCustomizationSettings();
	virtual FAxosHorizontalCompassPlayerCustomizationSettings GetPlayerHorizontalCompassPlayerCustomizationSettings_Implementation();
	

    // Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|General")
	FAxosHorizontalCompassSettings Settings;

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

    // UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
    // float TickThickness {2.0};

    // UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Ticks")
    // FLinearColor TickColor {FLinearColor::White};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FAxosTextProperties TickLabels;

	// Text (Bearing Number) Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	bool bShowNumbers {true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FSlateFontInfo TextFont;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	float TextTopPadding {5.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	float TextLeftPadding {10.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FLinearColor TickLabelColor {FLinearColor::White};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	float TextSize {14.0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	TEnumAsByte<ETextJustify::Type> TextJustification {ETextJustify::Center};

    // Markers Settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Markers")
    TArray<FAxosCompassMarkerData> ActiveMarkers;

    UFUNCTION(BlueprintCallable, Category = "Compass|Markers")
    void AddMarker(FAxosCompassMarkerData NewMarker);

    UFUNCTION(BlueprintCallable, Category = "Compass|Markers")
    void ClearMarkers();

protected:
    UPROPERTY(meta = (BindWidget))
    UCanvasPanel* CompassCanvas;

    UPROPERTY(meta = (BindWidget))
    UCanvasPanel* MarkerRowCanvas;

    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
    
    // --- Internal Logic Functions ---
    void DrawCompassTicks(float CenterAngle, float CanvasWidth);
    void DrawCompassMarkers(float CenterAngle, float CanvasWidth);
    float CalculateXPosition(float TargetAngle, float CenterAngle, float CanvasWidth);

	UPROPERTY(BlueprintReadOnly, Category = "Compass|General")
	float CurrentPlayerRotation {0.0f};
	
};
