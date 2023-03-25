// Copyright CitroenGames 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "FPSE_BaseWeapon.generated.h"

UCLASS()
class FPSESSENTIAL_API AFPSE_BaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPSE_BaseWeapon();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Functions for firing and reloading the weapon
	UFUNCTION(BlueprintCallable, Server, Reliable)
		void Fire();

	UFUNCTION(BlueprintCallable, Server, Reliable)
		void Reload();

	// Replicated variables for the weapon's ammo count
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated)
		int32 MagazineSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_MagazineAmount)
		int32 MagazineAmount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_TotalAmmo)
		int32 TotalAmmo;

protected:
	// RepNotify functions for the replicated ammo count variables
	UFUNCTION()
		void OnRep_MagazineAmount();

	UFUNCTION()
		void OnRep_TotalAmmo();

	// Replication setup for the weapon's ammo count
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
