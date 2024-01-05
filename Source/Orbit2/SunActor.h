// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SunActor.generated.h"

UCLASS()
class ORBIT2_API ASunActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASunActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		class UPointLightComponent* PointLightComponent;

	//// Use USceneComponent as the RootComponent
	//UPROPERTY(VisibleAnywhere)
	//	class USceneComponent* RootComponent;
};
