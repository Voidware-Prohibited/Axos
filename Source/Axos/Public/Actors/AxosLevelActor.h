// MIT

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/DecalComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/TextRenderComponent.h"
#include "Interfaces/AxosInterface.h"
#include "AxosLevelActor.generated.h"

class AGameState;

UCLASS()
class AXOS_API AAxosLevelActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAxosLevelActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// RPC for clients to request a yaw change
	UFUNCTION(Server, Reliable)
	void Server_SetYaw(float NewYaw);

	// Replicated property for server-to-client yaw updates
	UPROPERTY(Replicated)
	float ReplicatedYaw;

	UFUNCTION()
	void OnGameStateChange(float OldValue, float NewValue);

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	TObjectPtr<UBillboardComponent> SpriteComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	TObjectPtr<class UTextRenderComponent> TextRender;
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class UArrowComponent* ArrowComponent;
	
	// A flag to indicate that the Game State has an active override
	bool bHasGameStateOverride = false;
	float GameStateOverrideYaw = 0.0f;
	TSoftObjectPtr<AGameState> GameState = nullptr;

	// Called when the GameState's override is updated
	void OnGameStateOverrideUpdated();

public:
	/** Returns TextRender subobject **/
	class UTextRenderComponent* GetTextRender() const { return TextRender; }
#if WITH_EDITORONLY_DATA
	/** Returns SpriteComponent subobject **/
	UBillboardComponent* GetSpriteComponent() const { return SpriteComponent; }
#endif
	
};
