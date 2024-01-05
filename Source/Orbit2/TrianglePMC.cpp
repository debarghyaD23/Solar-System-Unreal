// Fill out your copyright notice in the Description page of Project Settings.


#include "TrianglePMC.h"

// Sets default values
ATrianglePMC::ATrianglePMC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ThisMesh= CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMeshCompnent"));
	RootComponent = ThisMesh;

}

// Called when the game starts or when spawned
void ATrianglePMC::BeginPlay()
{
	Super::BeginPlay();
	CreateVertices();
	CreateTriangles();
	ThisMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);
	
}

// Called every frame
void ATrianglePMC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

} 

void ATrianglePMC::CreateVertices() {
	for (int X{ 0 }; X < XSize; ++X) {
		for (int Y{ 0 }; Y < YSize; ++Y) {
			Vertices.Add(FVector(X*Scale, Y*Scale,FMath::RandRange(Zmin,Zmax)));
			//DrawDebugSphere(GetWorld(), FVector(X * Scale, Y * Scale, 0), 25.0f, 16, FColor::Red, true, -1.0f, 0U, 0.0f);
		}
	}
}

void ATrianglePMC::CreateTriangles() {
	int Vertex{ 0 };
	for (int X{ 0 }; X < XSize; ++X) {
		for (int Y{ 0 }; Y < YSize; ++Y) {
			Triangles.Add(Vertex);
			Triangles.Add(Vertex + 1);
			Triangles.Add(Vertex + YSize + 1);
			Triangles.Add(Vertex + 1);
			Triangles.Add(Vertex + YSize + 2);
			Triangles.Add(Vertex + YSize + 1);
			++Vertex;
		}
		++Vertex;
	}
}



