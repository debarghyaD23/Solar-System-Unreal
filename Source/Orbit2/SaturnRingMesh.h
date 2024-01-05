// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "SaturnRingMesh.generated.h"

UCLASS(config=Game)
class ORBIT2_API ASaturnRingMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASaturnRingMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* ProceduralMeshComponent;

public:	
	// Called every frame
	const int32 NumSegments = 360;

	virtual void Tick(float DeltaTime) override;

	void GenerateHollowEllipseMesh();

	void GenerateSaturnRingMesh();

private:
	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMajorAxis; // Length of the semi-major axis (longest radius)

	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMinorAxis; // Length of the semi-minor axis (shortest radius)

	UPROPERTY(EditAnywhere, Category = "Orbit", config)
		float OrbitSpeed; // Speed of revolution in degrees per second

	float CurrentOrbitAngle;

};
