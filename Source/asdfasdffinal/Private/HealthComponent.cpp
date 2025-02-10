// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::ModifyHealth(float Amount)
{
	CurrentHealth += Amount;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	else if (CurrentHealth > MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
}

void UHealthComponent::TakeDamage(float Amount)
{
	ModifyHealth(-Amount);
}

void UHealthComponent::Heal(float Amount)
{
	ModifyHealth(Amount);
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

