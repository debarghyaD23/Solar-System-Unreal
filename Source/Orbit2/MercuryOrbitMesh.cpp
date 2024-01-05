// Fill out your copyright notice in the Description page of Project Settings.


#include "MercuryOrbitMesh.h"

// Sets default values
//const int32 NumSegments = 360;
AMercuryOrbitMesh::AMercuryOrbitMesh()
{
 //	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	ProceduralMeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMeshComponent"));
	RootComponent = ProceduralMeshComponent;

}

// Called when the game starts or when spawned
void AMercuryOrbitMesh::BeginPlay()
{
	Super::BeginPlay();

	GenerateHollowEllipseMesh();
	
}

// Called every frame
void AMercuryOrbitMesh::GenerateHollowEllipseMesh()
{
	//Super::Tick(DeltaTime);

	if (!ProceduralMeshComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("ProceduralMeshComponent is not valid."));
		return;
	}

	TArray<FVector> Vertices;
	TArray<int32> Triangles;

	const float AngleIncrement = 2.0f * PI / NumSegments;
	const float OuterRadiusX = 4300.0f;
	const float OuterRadiusY = 4000.0f;

	for (int32 i = 0; i <= NumSegments; i++)
	{
		const float Angle = i * AngleIncrement;
		const float X = OuterRadiusX * FMath::Cos(Angle);
		const float Y = OuterRadiusY * FMath::Sin(Angle);

		Vertices.Add(FVector(X, Y, 0.0f));
		Vertices.Add(FVector(X, Y, -10.0f));
	}

	for (int32 i = 0; i <= NumSegments; i++)
	{
		Triangles.Add(i * 2);
		Triangles.Add(i * 2 + 1);
		Triangles.Add((i + 1) * 2);

		Triangles.Add(i * 2 + 1);
		Triangles.Add((i + 1) * 2 + 1);
		Triangles.Add((i + 1) * 2);

		Triangles.Add(i * 2);
		Triangles.Add((i + 1) * 2);
		Triangles.Add((i * 2) + 1);

		Triangles.Add(i * 2 + 1);
		Triangles.Add((i + 1) * 2);
		Triangles.Add((i + 1) * 2 + 1);
	}

	//Triangles.Add((NumSegments - 1) * 2);
	//Triangles.Add(0);
	//Triangles.Add((NumSegments - 1) * 2 + 1);

	//Triangles.Add(0);
	//Triangles.Add(1);
	//Triangles.Add((NumSegments - 1) * 2 + 1);

	ProceduralMeshComponent->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);
	ProceduralMeshComponent->ContainsPhysicsTriMeshData(true);

	SetActorLocation(FVector(0.0f, 0.0f, 0.0f));

}

