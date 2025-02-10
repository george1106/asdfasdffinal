// Fill out your copyright notice in the Description page of Project Settings.


#include "AsdfCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HealthComponent.h"

// Sets default values
AAsdfCharacter::AAsdfCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(GetMesh());


	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;

	bFirstJump = true;
	bSecondJump = true;

}

// Called when the game starts or when spawned
void AAsdfCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAsdfCharacter::MoveRight(float value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	ControlRot.Yaw = 90.0f;

	AddMovementInput(ControlRot.Vector(), value);
}

void AAsdfCharacter::CheckJump()
{
	if (bFirstJump)
	{
		bFirstJump = false;
		Jump();
	}
	else if(bSecondJump)
	{
		bSecondJump = false;
		LaunchCharacter(FVector(0.0f, 0.0f, 500.0f), false, true);
	}
}

void AAsdfCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	bFirstJump = true;
	bSecondJump = true;
}

// Called every frame
void AAsdfCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAsdfCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &AAsdfCharacter::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AAsdfCharacter::CheckJump);

}

