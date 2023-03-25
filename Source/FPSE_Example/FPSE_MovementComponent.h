// Copyright CtitroenGames 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FPSE_MovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class FPSE_EXAMPLE_API UFPSE_MovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
public:
	UFPSE_MovementComponent(const FObjectInitializer& ObjectInitializer);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement")
	float SprintSpeedMultiplier;
	UFUNCTION(BlueprintCallable)
		void Sprint();
	UFUNCTION(BlueprintCallable)
		void StopSprinting();
protected:
	
};
