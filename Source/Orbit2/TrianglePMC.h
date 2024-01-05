// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "TrianglePMC.generated.h"

UCLASS()
class ORBIT2_API ATrianglePMC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrianglePMC();

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
		int XSize = 0;//no. of rows in grid
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
		int YSize = 0;//no. of cols in grid

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.0001))
		float Scale = 0;

	UPROPERTY(EditAnywhere)
		float Zmin = 0;
	UPROPERTY(EditAnywhere)
		float Zmax = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*UPROPERTY(EditAnywhere,Meta=(MakeEditWidget=true))
	TArray<FVector>Vertices;

	UPROPERTY(EditAnywhere)
	TArray<int32>Triangles;*/

	void CreateVertices();
	void CreateTriangles();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UProceduralMeshComponent* ThisMesh;

	//UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	TArray<FVector>Vertices;

	//UPROPERTY(EditAnywhere)
	TArray<int32>Triangles;

};
