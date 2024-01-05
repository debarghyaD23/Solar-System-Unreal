// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "OrbitMesh.generated.h"

UCLASS()
class ORBIT2_API  AOrbitMesh : public AActor
{
	GENERATED_BODY()

public:
	AOrbitMesh();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* ProceduralMeshComponent;

public:
	virtual void Tick(float DeltaTime) override;

	const int32 NumSegments = 360;

	void GenerateHollowEllipseMesh();
};
