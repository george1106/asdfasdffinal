
#include "PlayerBuffComponent.h"
#include "AsdfCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UPlayerBuffComponent::UPlayerBuffComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerBuffComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerBuffComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	SpeedBuffLeft -= DeltaTime;
	if (IsSpeedBuffed && SpeedBuffLeft <= 0)
	{
		IsSpeedBuffed = false;
		RemoveSpeedBuff();
	}
}

void UPlayerBuffComponent::ApplySpeedBuff()
{
	SpeedBuffLeft = SpeedBuffDuration;
	if (IsSpeedBuffed == false)
	{
		IsSpeedBuffed = true;
		Cast<ACharacter>(GetOwner())->GetCharacterMovement()->MaxWalkSpeed *= SpeedBuffMulti;
	}
}

void UPlayerBuffComponent::RemoveSpeedBuff()
{
	Cast<ACharacter>(GetOwner())->GetCharacterMovement()->MaxWalkSpeed /= SpeedBuffMulti;
}
