//Copyright CitroenGames 2023
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FPSE_HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSESSENTIAL_API UFPSE_HealthComponent : public UActorComponent
{
	GENERATED_BODY()




public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//Construction Script
	UFPSE_HealthComponent();

	// Max Health
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category = "HealthComponent")
		float MaxHealth = 100;

	// Current Health
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "HealthComponent")
		float Health;

	// Base Health (Default Health)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthComponent")
		float BaseHealth = 100;

	// Server function to update health
	UFUNCTION(Server, Reliable, BlueprintCallable, meta = (ToolTip = "It adds health it is already clamping between 0 and max health"))
		void Server_AddHealth(float HealthToAdd);

	// Server function to remove health
	UFUNCTION(Server, Reliable, BlueprintCallable, meta = (ToolTip = "It removes health it is already clamping between 0 and max health"))
	void Server_RemoveHealth(float HealthToRemove);

	// Server function to set health
	UFUNCTION(Server, Reliable, BlueprintCallable, meta = (ToolTip = "It sets health it is already clamping between 0 and max health"))
		void Server_SetHealth(float HealthToSet);

	// Server function to set max health
	UFUNCTION(Server, Reliable, BlueprintCallable, meta = (ToolTip = "It sets maxhealth"))
		void Server_SetMaxHealth(float HealthToSet);
		
};
