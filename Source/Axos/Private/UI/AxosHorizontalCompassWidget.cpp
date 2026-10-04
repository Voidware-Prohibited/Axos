// MIT


#include "UI/AxosHorizontalCompassWidget.h"
#include "Rendering/DrawElements.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Fonts/SlateFontInfo.h"
#include "Fonts/FontMeasure.h"
#include "Framework/Application/SlateApplication.h"
#include "UI/AxosHorizontalCompassMarkerWidget.h"

UAxosHorizontalCompassWidget::UAxosHorizontalCompassWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    CurrentPlayerRotation = 0.0f;
}

void UAxosHorizontalCompassWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

	// 1. Ensure the world exists and we are not shutting down
	UWorld* World = GetWorld();
	if (!World || World->HasAnyFlags(RF_BeginDestroyed))
	{
		return;
	}

	// 2. Ensure world initialization/streaming is complete
	if (World->bIsTearingDown || !World->GetGameState())
	{
		return;
	}

    if (CompassCanvas && MarkerRowCanvas)
    {
        float CanvasWidth = CompassCanvas->GetCachedGeometry().GetLocalSize().X;
        
        // Clear children before redrawing to prevent object leaking/duplication
        CompassCanvas->ClearChildren();
        MarkerRowCanvas->ClearChildren();

        DrawCompassTicks(CurrentPlayerRotation, CanvasWidth);

    	UpdateMarkers(GetPlayerCompassMarkers());

    	if (ActiveMarkers.Num() > 0)
    	{
    		DrawCompassMarkers(CurrentPlayerRotation, CanvasWidth);
    	}
    }
	UpdateCompassRotation(GetPlayerAzimuth());
}

void UAxosHorizontalCompassWidget::UpdateCompassRotation_Implementation(float PlayerRotation)
{
    // Ensure rotation is clamped between 0 and 360
    CurrentPlayerRotation = FMath::Fmod(PlayerRotation, 360.0f);
    if (CurrentPlayerRotation < 0.0f)
    {
        CurrentPlayerRotation += 360.0f;
    }
}

float UAxosHorizontalCompassWidget::GetPlayerFOV_Implementation()
{
	return 90.0f;
}

float UAxosHorizontalCompassWidget::GetPlayerAzimuth_Implementation()
{
	return 0.0f;
}

float UAxosHorizontalCompassWidget::GetPlayerFontScale_Implementation()
{
	return 1.0f;
}

TArray<FAxosCompassMarkerData> UAxosHorizontalCompassWidget::GetPlayerCompassMarkers_Implementation()
{
	TArray<FAxosCompassMarkerData> EmptyCompassMarkerDataArray;
	return EmptyCompassMarkerDataArray;
}

FAxosHorizontalCompassPlayerCustomizationSettings UAxosHorizontalCompassWidget::GetPlayerHorizontalCompassPlayerCustomizationSettings_Implementation()
{
	FAxosHorizontalCompassPlayerCustomizationSettings EmptyHorizontalCompassPlayerCustomizationSettings;
	return EmptyHorizontalCompassPlayerCustomizationSettings;
}

void UAxosHorizontalCompassWidget::UpdateMarkers_Implementation(const TArray<FAxosCompassMarkerData>& NewMarkerData)
{
	if (ActiveMarkers == NewMarkerData)
	{
		return;
	}

	ActiveMarkers = NewMarkerData;
}

void UAxosHorizontalCompassWidget::AddMarker(FAxosCompassMarkerData NewMarker)
{
    ActiveMarkers.Add(NewMarker);
}

void UAxosHorizontalCompassWidget::ClearMarkers()
{
    ActiveMarkers.Empty();
}

float UAxosHorizontalCompassWidget::CalculateXPosition(float TargetAngle, float CenterAngle, float CanvasWidth)
{
    float DeltaAngle = TargetAngle - CenterAngle;

    // Normalize angle difference to [-180, 180] range
    if (DeltaAngle > 180.0f) DeltaAngle -= 360.0f;
    if (DeltaAngle < -180.0f) DeltaAngle += 360.0f;

    // Calculate screen position based on FOV
    float HalfFOV = GetPlayerFOV() / 2.0f;
    float ScreenX = (DeltaAngle / HalfFOV) * (CanvasWidth / 2.0f) + (CanvasWidth / 2.0f);

    return ScreenX;
}

void UAxosHorizontalCompassWidget::DrawCompassTicks(float CenterAngle, float CanvasWidth)
{
    // Draw all ticks for 360 degrees
    for (int32 i = 0; i < 360; i++)
    {
        float ScreenX = CalculateXPosition((float)i, CenterAngle, CanvasWidth);

    	// Measure a sample of TextFont using GetFontMeasureService. The Y value will be used to place the Tick lines.
    	TSharedRef<FSlateFontMeasure> FontMeasure = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();
    	FVector2D TextDimensions {FontMeasure->Measure(TEXT("0"), TextFont, GetPlayerFontScale())};

    	// Display numbers for 10-degree increments
    	if (bShowNumbers && i % 10 == 0)
    	{
    		UCanvasPanelSlot* TextSlot = CompassCanvas->AddChildToCanvas(NewObject<UTextBlock>(this));
    		UTextBlock* TickText = Cast<UTextBlock>(TextSlot->Content);
    		if (TickText)
    		{
    			TickText->SetText(FText::FromString(FString::Printf(TEXT("%d"), i)));
    			TickText->SetFont(TickLabels.Font);
    			TickText->SetColorAndOpacity(TickLabels.ColorAndOpacity);
    			TextSlot->SetPosition(FVector2D(ScreenX - TextLeftPadding, TextTopPadding));
    			TickText->SetMargin(TickLabels.Margin);
    			TickText->SetJustification(TickLabels.Justification);
    		}
    	}

        // Cull ticks that are too far off the screen
        if (ScreenX < -50.0f || ScreenX > CanvasWidth + 50.0f) continue;

        float TickLength = ShortTickLength;
        if (i % 10 == 0) TickLength = LongTickLength;
        else if (i % 5 == 0) TickLength = MediumTickLength;

    	float TickThickness = ShortTickThickness;
    	if (i % 10 == 0) TickThickness = LongTickThickness;
    	else if (i % 5 == 0) TickThickness = MediumTickThickness;

    	FLinearColor TickColor = ShortTickColor;
    	if (i % 10 == 0) TickColor = LongTickColor;
    	else if (i % 5 == 0) TickColor = MediumTickColor;

        // Ticks are drawn downwards from the top of the canvas
        UCanvasPanelSlot* TickSlot = CompassCanvas->AddChildToCanvas(NewObject<UImage>(this));
        TickSlot->SetPosition(FVector2D(ScreenX - (TickThickness / 2.0f), TextDimensions.Y + TextTopPadding + TicksTopPadding));
        TickSlot->SetSize(FVector2D(TickThickness, TickLength));
        
        // Apply Color
        UImage* TickImage = Cast<UImage>(TickSlot->Content);
        if (TickImage)
        {
            TickImage->SetColorAndOpacity(TickColor);
        }
    }
}

void UAxosHorizontalCompassWidget::DrawCompassMarkers(float CenterAngle, float CanvasWidth)
{
    float HalfFOV = GetPlayerFOV() / 2.0f;
    
    for (const FAxosCompassMarkerData& Marker : ActiveMarkers)
    {
        float ScreenX = CalculateXPosition(Marker.Angle, CenterAngle, CanvasWidth);
        float DeltaAngle = Marker.Angle - CenterAngle;

        // Normalize for checking if outside FOV
        if (DeltaAngle > 180.0f) DeltaAngle -= 360.0f;
        if (DeltaAngle < -180.0f) DeltaAngle += 360.0f;

        bool bIsOutsideFOV = FMath::Abs(DeltaAngle) > HalfFOV;
    	bool bEdgeClampOffScreenMarkers = bIsOutsideFOV ? true : false;

    	if (const UAxosEditorSettings* AxosEditorSettings = GetDefault<UAxosEditorSettings>())
    	{
    		AxosEditorSettings->HorizontalCompassSettings.bEdgeClampOffScreenMarkers;
    	}

        // Apply clamping if outside FOV so they stick to the edge
        if (bIsOutsideFOV)
        {
            if (DeltaAngle > 0) ScreenX = CalculateXPosition(CenterAngle + HalfFOV, CenterAngle, CanvasWidth); // Right Edge
            else ScreenX = CalculateXPosition(CenterAngle - HalfFOV, CenterAngle, CanvasWidth); // Left Edge
        }

        // Create Marker UI
        UAxosHorizontalCompassMarkerWidget* MarkerWidget = NewObject<UAxosHorizontalCompassMarkerWidget>(this);
        UCanvasPanelSlot* MarkerSlot = MarkerRowCanvas->AddChildToCanvas(MarkerWidget);
    	MarkerWidget->SetMarkerData(Marker);
    	MarkerSlot->SetPosition(FVector2D(ScreenX - (MarkerWidget->GetCachedGeometry().GetLocalSize().X / 2.0f), 0.0f));
        // Cast and style based on Marker.State, Marker.MarkerIcon, and Marker.MarkerName
    }
}
