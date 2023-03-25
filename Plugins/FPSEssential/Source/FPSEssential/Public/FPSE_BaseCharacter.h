//Copyright CitroenGames 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSE_BaseCharacter.generated.h"

UCLASS()
class FPSESSENTIAL_API AFPSE_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSE_BaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
