// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UranusActor.generated.h"

UCLASS(config=Game)
class ORBIT2_API AUranusActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUranusActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMajorAxis; // Length of the semi-major axis (longest radius)

	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMinorAxis; // Length of the semi-minor axis (shortest radius)

	UPROPERTY(EditAnywhere, Category = "Orbit",config)
		float OrbitSpeed; // Speed of revolution in degrees per second

	float CurrentOrbitAngle;

};
