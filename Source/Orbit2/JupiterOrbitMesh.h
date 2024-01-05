// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "JupiterOrbitMesh.generated.h"

UCLASS()
class ORBIT2_API AJupiterOrbitMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJupiterOrbitMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* ProceduralMeshComponent;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	void GenerateHollowEllipseMesh();
};
