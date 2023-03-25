// Copyright CtitroenGames 2023


#include "FPSE_MovementComponent.h"


UFPSE_MovementComponent::UFPSE_MovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SprintSpeedMultiplier = 1.5f;
}
void UFPSE_MovementComponent::Sprint()
{
	MaxWalkSpeed *= SprintSpeedMultiplier;
}
void UFPSE_MovementComponent::StopSprinting()
{
	MaxWalkSpeed /= SprintSpeedMultiplier;
}