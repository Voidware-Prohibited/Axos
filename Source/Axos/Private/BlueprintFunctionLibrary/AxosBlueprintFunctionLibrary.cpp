// MIT

#include "BlueprintFunctionLibrary/AxosBlueprintFunctionLibrary.h"
#include "Components/AxosGameStateComponent.h"
#include "Interfaces/AxosInterface.h"
#include "Kismet/KismetMathLibrary.h"

float UAxosBlueprintFunctionLibrary::GetActorAzimuth(AActor* TargetActor, TSoftObjectPtr<AGameStateBase> GameState)
{
	if (!TargetActor || !GameState)
	{
		// Handle Errors gracefully by returning Actors Forward Vector
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("TargetActor or GameState Invalid in UAxosBlueprintFunctionLibrary::GetActorAzimuth(AActor* TargetActor, AGameState* GameState)")));
		}
		
		return TargetActor->GetActorForwardVector().Y;
	}

	// Ensure Game State implements AxosInterface
	if (!GameState->GetClass()->ImplementsInterface(UAxosInterface::StaticClass()))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("UAxosInterface not Implemented in UAxosBlueprintFunctionLibrary::GetActorAzimuth(AActor* TargetActor, AGameState* GameState)")));
		}
		
		return TargetActor->GetActorForwardVector().Y;
	}
	else
	{
		// Get AxosGameStateComponent
		TSoftObjectPtr<UAxosGameStateComponent> AxosGameStateComponent = IAxosInterface::Execute_GetAxosGameStateComponent(GameState.Get());

		if (!AxosGameStateComponent)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("AxosGameStateComponent not found in UAxosBlueprintFunctionLibrary::GetActorAzimuth(AActor* TargetActor, AGameState* GameState)")));
			return TargetActor->GetActorForwardVector().Y;
		}
		else
		{
			// Get North Yaw from GameState
			float NorthYaw = AxosGameStateComponent->NorthYaw;

			// Get TargetActor Yaw
			float ActorYaw = TargetActor->GetActorRotation().Yaw;

			// Calculate raw difference
			float RawAzimuth = ActorYaw - NorthYaw;

			// Use KismetMathLibrary::NormalizeAxis to normalize to -180 to 180 range.
			float NormalizedAzimuth = UKismetMathLibrary::NormalizeAxis(RawAzimuth);

			// Normalize to 0-360:
			if (NormalizedAzimuth < 0.0f)
			{
				NormalizedAzimuth += 360.0f;
			}

			return NormalizedAzimuth;
		}
	}
}
