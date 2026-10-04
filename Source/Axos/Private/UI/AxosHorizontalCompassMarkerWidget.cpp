// MIT


#include "UI/AxosHorizontalCompassMarkerWidget.h"

#include "Data/AxosMarkerStylesDataAsset.h"
#include "Settings/AxosEditorSettings.h"

void UAxosHorizontalCompassMarkerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	// Get Widget Material Parameter Names
	if (const UAxosEditorSettings* Settings = GetDefault<UAxosEditorSettings>())
	{
		MarkerMaterialParameterNames = Settings->HorizontalCompassSettings.HorizontalCompassMaterialSettings.MarkerSettings.MarkerMaterialParameterNames;
		
	}
}

void UAxosHorizontalCompassMarkerWidget::SetMarkerData_Implementation(FAxosCompassMarkerData NewMarkerData)
{
	MarkerData = NewMarkerData;
}

void UAxosHorizontalCompassMarkerWidget::SetMarkerStyle_Implementation(FAxosMarkerStyle NewMarkerStyle)
{
	IconImageBlock->SetBrushFromSoftTexture(NewMarkerStyle.IconTexture);
	IconImageBlock->SetColorAndOpacity(NewMarkerStyle.IconPrimaryColorAndOpacity);
	UMaterialInstanceDynamic* IconImageDynamicMaterial = IconImageBlock->GetDynamicMaterial();

	// MarkerData.NameText.bDisplay
	// MarkerData.NameText.Font
	
}

FAxosMarkerStyle UAxosHorizontalCompassMarkerWidget::GetStyleForMarkerState_Implementation(FGameplayTag MarkerState)
{
	FAxosMarkerStyle ReturnMarkerStyle {FAxosMarkerStyle()};

	if (const UAxosEditorSettings* Settings = GetDefault<UAxosEditorSettings>())
	{
		if (UAxosMarkerStylesDataAsset* MarkerStylesDataAsset = Settings->HorizontalCompassSettings.HorizontalCompassMarkerStyleSettings.MarkerStylesDataAsset.Get())
		{
			if (MarkerStylesDataAsset->MarkerStyles.Num() > 0 && MarkerStylesDataAsset->MarkerStyles.Contains(MarkerState))
			{
				ReturnMarkerStyle = MarkerStylesDataAsset->MarkerStyles.FindChecked(MarkerState);
			}
		}
	}
	return ReturnMarkerStyle;
}
