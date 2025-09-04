// MIT

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AxosGameStateComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AXOS_API UAxosGameStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAxosGameStateComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(ReplicatedUsing=OnRep_UseOverrideYaw, EditAnywhere, BlueprintReadWrite, Category = "Control")
	bool UseOverrideYaw;

	UPROPERTY(ReplicatedUsing=OnRep_OverrideYaw, EditAnywhere, BlueprintReadWrite, Category = "Control")
	float OverrideYaw;

	UFUNCTION()
	void OnRep_UseOverrideYaw();

	UFUNCTION()
	void OnRep_OverrideYaw();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
