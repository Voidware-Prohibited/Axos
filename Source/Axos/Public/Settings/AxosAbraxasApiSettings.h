// MIT

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AxosAbraxasApiSettings.generated.h"

/**
 * 
 */
UCLASS(config = AxosAbraxasApi, DefaultConfig)
class AXOS_API UAxosAbraxasApiSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UAxosAbraxasApiSettings();

	// True = Integrate with Abraxas, False = Local Mode
	// Abraxas Integration sends Async HTTP API requests to the specified server.
	// Local mode makes changes directly.
	UPROPERTY(Config, EditAnywhere, Category = "Abraxas|API")
	bool bAbraxasIntegration {false};

	// Full HTTP Web Address
	UPROPERTY(Config, EditAnywhere, Category = "Abraxas|API")
	FURL AbraxasAddress;

	// API key used for Abraxas API requests.
	// WARNING: Keep this Key secret!
	UPROPERTY(Config, EditAnywhere, Category = "Abraxas|API")
	FString AbraxasApiKey;

#if WITH_EDITOR
	virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
	virtual FText GetSectionText() const override { return NSLOCTEXT("Axos", "AxosSectionText", "Axos Abraxas Integration API Settings"); }
	virtual FText GetSectionDescription() const override { return NSLOCTEXT("Axos", "AxosSectionDesc", "Configure Axos Abraxas Integration API Settings"); }
#endif
};
