// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileActor.generated.h"

UCLASS()
class ASDFASDFFINAL_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectileActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage = 10.f;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
