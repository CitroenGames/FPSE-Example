


#include "FPSE_HealthComponent.h"
#include "Net/UnrealNetwork.h"

UFPSE_HealthComponent::UFPSE_HealthComponent()
{
    // Set the health to the base health
    Server_SetHealth(BaseHealth);
}

void UFPSE_HealthComponent::Server_SetMaxHealth_Implementation(float MaxHealthToSet)
{
    //Set Max Health
	MaxHealth = MaxHealthToSet;
}


void UFPSE_HealthComponent::Server_AddHealth_Implementation(float NewHealth)
{
    //add health to the current health with clamp using the max health
    Health = FMath::Clamp(Health + NewHealth, 0.0f, MaxHealth);
}



void UFPSE_HealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // Replicate the health variable to all clients
    DOREPLIFETIME(UFPSE_HealthComponent, Health);
    DOREPLIFETIME(UFPSE_HealthComponent, MaxHealth);
}

void UFPSE_HealthComponent::Server_RemoveHealth_Implementation(float HealthToRemove)
{
    //remove health from the current health with clamp
    Health = FMath::Clamp(Health - HealthToRemove, 0.0f, MaxHealth);

}

void UFPSE_HealthComponent::Server_SetHealth_Implementation(float HealthToSet)
{
    //remove health from the current health with clamp
    Health = FMath::Clamp(Health - HealthToSet, 0.0f, MaxHealth);

}
