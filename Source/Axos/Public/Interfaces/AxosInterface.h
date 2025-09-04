// MIT

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "AxosInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAxosInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AXOS_API IAxosInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Declare the delegate as a UPROPERTY within the interface
	// UDELEGATE(BlueprintAssignable, Category = "MyInterface")
	// class FOnGameStateChanged OnGameStateChangedDelegate;

	// Declare the interface function that will broadcast the delegate
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MyInterface")
	void BroadcastGameStateChange(const FString& NewState);
	virtual void BroadcastGameStateChange_Implementation(const FString& NewState) = 0; // Pure virtual for native implementation
	
};
