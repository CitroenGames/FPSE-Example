//Copyright CitroenGames 2023
#include "FPSE_BaseWeapon.h"

#include "Net/UnrealNetwork.h"

AFPSE_BaseWeapon::AFPSE_BaseWeapon()
{
	// Set default values for the ammo count variables
	MagazineSize = 30;
	MagazineAmount = 30;
	TotalAmmo = 90;
}

void AFPSE_BaseWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void AFPSE_BaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPSE_BaseWeapon::Fire_Implementation()
{
	// Check if there is enough ammo in the magazine to fire
	if (MagazineAmount > 0)
	{
		// Decrement the ammo count and do the firing logic
		MagazineAmount--;
		// TODO: Implement firing logic here
	}

	// Update the replicated ammo count variables
	OnRep_MagazineAmount();
	OnRep_TotalAmmo();
}

void AFPSE_BaseWeapon::Reload_Implementation()
{
	// Calculate how much ammo is needed to fill the magazine
	int32 AmmoNeeded = MagazineSize - MagazineAmount;

	// Check if there is enough total ammo to fill the magazine
	if (TotalAmmo >= AmmoNeeded)
	{
		// Decrement the total ammo count and fill the magazine
		TotalAmmo -= AmmoNeeded;
		MagazineAmount = MagazineSize;
	}
	else
	{
		// If there isn't enough total ammo, just fill the magazine with whatever is left
		MagazineAmount += TotalAmmo;
		TotalAmmo = 0;
	}

	// Update the replicated ammo count variables
	OnRep_MagazineAmount();
	OnRep_TotalAmmo();
}

void AFPSE_BaseWeapon::OnRep_MagazineAmount()
{
	// Do any client-side logic that needs to be done when MagazineAmount changes
}

void AFPSE_BaseWeapon::OnRep_TotalAmmo()
{
	// Do any client-side logic that needs to be done when TotalAmmo changes
}

void AFPSE_BaseWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate the ammo count variables
	DOREPLIFETIME_CONDITION(AFPSE_BaseWeapon, MagazineSize, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AFPSE_BaseWeapon, MagazineAmount, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AFPSE_BaseWeapon, TotalAmmo, COND_OwnerOnly);
}
