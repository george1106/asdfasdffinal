// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Delegates/Delegate.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathCast);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASDFASDFFINAL_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth = 100.f;
	UFUNCTION(BlueprintCallable)
	void TakeDamage(float Amount);
	UFUNCTION(BlueprintCallable)
	void Heal(float Amount);

	UPROPERTY(BlueprintAssignable)
	FOnDeathCast OnDeath;

protected:
	virtual void BeginPlay() override;
	void ModifyHealth(float Amount);
	float CurrentHealth;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
