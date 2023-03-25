//Copyright CitroenGames 2023


#include "FPSE_BaseCharacter.h"

// Sets default values
AFPSE_BaseCharacter::AFPSE_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSE_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSE_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSE_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

