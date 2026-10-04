// MIT

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Data/AxosCompassStructs.h"
#include "Data/AxosMarkerStylesDataAsset.h"
#include "Settings/AxosEditorSettings.h"
#include "AxosHorizontalCompassMarkerWidget.generated.h"

/**
 * 
 */
UCLASS()
class AXOS_API UAxosHorizontalCompassMarkerWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Compass")
	void SetMarkerData(FAxosCompassMarkerData NewMarkerData);
	void SetMarkerData_Implementation(FAxosCompassMarkerData NewMarkerData);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Compass")
	void SetMarkerStyle(FAxosMarkerStyle NewMarkerStyle);
	void SetMarkerStyle_Implementation(FAxosMarkerStyle NewMarkerStyle);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Compass")
	FAxosMarkerStyle GetStyleForMarkerState(FGameplayTag MarkerState);
	FAxosMarkerStyle GetStyleForMarkerState_Implementation(FGameplayTag MarkerState);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FAxosCompassMarkerData MarkerData;
	
	// Image
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	UTexture2D* IconImage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	UMaterialInterface* IconMaterial;
	
	// Text (Bearing Number) Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	bool bDisplayText {true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FAxosTextProperties NameText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	FAxosTextProperties DistanceText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compass|Text")
	float TextTopPadding {5.0};

protected:
	FAxosHorizontalCompassMarkerMaterialParameterNames MarkerMaterialParameterNames;
	
	UPROPERTY(meta = (BindWidget))
	UImage* IconImageBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* NameTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DistanceTextBlock;
};
