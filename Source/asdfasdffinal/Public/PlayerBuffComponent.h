// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerBuffComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASDFASDFFINAL_API UPlayerBuffComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerBuffComponent();

	UFUNCTION(BlueprintCallable)
	void ApplySpeedBuff();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpeedBuffMulti = 2.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpeedBuffDuration = 5.f;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float SpeedBuffLeft;
	bool IsSpeedBuffed = false;
	void RemoveSpeedBuff();
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
