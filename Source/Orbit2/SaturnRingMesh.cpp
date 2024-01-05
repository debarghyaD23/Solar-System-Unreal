// Fill out your copyright notice in the Description page of Project Settings.


#include "SaturnRingMesh.h"

// Sets default values
ASaturnRingMesh::ASaturnRingMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProceduralMeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMeshComponent"));
	RootComponent = ProceduralMeshComponent;
	// Set default values for the properties
	SemiMajorAxis = 10300.0f;  // Modify these values as needed
	SemiMinorAxis = 10250.0f;
	OrbitSpeed = 6.0f;  // Degrees per second
	CurrentOrbitAngle = 0.0f;
}

// Called when the game starts or when spawned
void ASaturnRingMesh::BeginPlay()
{
	Super::BeginPlay();
	
	//GenerateHollowEllipseMesh();

	GenerateSaturnRingMesh();
}

// Called every frame
void ASaturnRingMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Set scale for actor
	FVector NewScale = FVector(3.9f, 3.9f, 3.9f);
	RootComponent->SetWorldScale3D(NewScale);

	// Rotate the actor around its own axis
	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = -70.5f; // You can adjust the rotation speed as needed

	// Modify the pitch, yaw, or roll based on your requirement
	NewRotation.Yaw += RotationSpeed * DeltaTime; // Rotate around the Yaw axis

	// Apply the new rotation to the actor
	SetActorRotation(NewRotation);

	// Calculate the new location for the actor based on the elliptical orbit
	const FVector NewLocation = FVector(
		SemiMajorAxis * FMath::Cos(FMath::DegreesToRadians(CurrentOrbitAngle)),
		SemiMinorAxis * FMath::Sin(FMath::DegreesToRadians(CurrentOrbitAngle)),
		GetActorLocation().Z
	);

	SetActorLocation(NewLocation);

	// Update the orbit angle
	CurrentOrbitAngle -= OrbitSpeed * DeltaTime;
	if (CurrentOrbitAngle >= 360.0f)
	{
		CurrentOrbitAngle = 0.0f;
	}

}
void ASaturnRingMesh::GenerateHollowEllipseMesh()
{
	if (!ProceduralMeshComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("ProceduralMeshComponent is not valid."));
		return;
	}

	TArray<FVector> Vertices;
	TArray<int32> Triangles;

	const float AngleIncrement = 2.0f * PI / NumSegments;
	const float OuterRadiusX = 250.0f;
	const float OuterRadiusY = 250.0f;
	//const float InnerRadius = 100.0f;  // Inner radius of the ring
	//const FColor RingColor = FColor::Yellow; // Set the color for the entire ring


	for (int32 i = 0; i <= NumSegments; i++)
	{
		const float Angle = i * AngleIncrement;
		const float X = OuterRadiusX * FMath::Cos(Angle);
		const float Y = OuterRadiusY * FMath::Sin(Angle);

		Vertices.Add(FVector(X+25.0f, Y, 0.0f));
		Vertices.Add(FVector(X-25.0f, Y, 0.0f));
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


void ASaturnRingMesh::GenerateSaturnRingMesh()
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector2D> UV;
	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> VertexColors; // Added array for vertex colors

	//const int32 NumSegments = 32;  // Number of segments in the ring
	const float OuterRadius = 325.0f;  // Outer radius of the ring
	const float InnerRadius = 200.0f;  // Inner radius of the ring
	const FColor RingColor = FColor::Yellow; // Set the color for the entire ring

	// Generate vertices, triangles, UVs, normals, tangents, and colors for a hollow circular ring
	for (int32 i = 0; i <= NumSegments; ++i)
	{
		float Angle = 2 * PI * i / NumSegments;

		float OuterX = FMath::Cos(Angle) * OuterRadius;
		float OuterY = FMath::Sin(Angle) * OuterRadius;

		float InnerX = FMath::Cos(Angle) * InnerRadius;
		float InnerY = FMath::Sin(Angle) * InnerRadius;

		// Outer edge
		Vertices.Add(FVector(OuterX, OuterY, 0));
		UV.Add(FVector2D(static_cast<float>(i) / NumSegments, 0.f));
		Normals.Add(FVector(0, 0, 1));
		Tangents.Add(FProcMeshTangent(0, 1, 0));
		VertexColors.Add(RingColor); // Set color for the outer edge

		// Inner edge
		Vertices.Add(FVector(InnerX, InnerY, 0));
		UV.Add(FVector2D(static_cast<float>(i) / NumSegments, 0.f));
		Normals.Add(FVector(0, 0, -1));
		Tangents.Add(FProcMeshTangent(0, -1, 0));
		VertexColors.Add(RingColor); // Set color for the inner edge
	}

	// Generate triangles for the ring
	for (int32 i = 0; i <= NumSegments ; ++i)
	{
		// Outer face
		Triangles.Add(2 * i);
		Triangles.Add(2 * i + 1);
		Triangles.Add(2 * i + 2);

		Triangles.Add(2 * i + 2);
		Triangles.Add(2 * i + 3);
		Triangles.Add(2 * i + 1);

		// Inner face
		Triangles.Add(2 * i + 2 * i + 1);
		Triangles.Add(2 * i + 2 * i + 2);
		Triangles.Add(2 * i + 2 * i);
		

		Triangles.Add(2 * i + 2 * i + 1);
		Triangles.Add(2 * i + 2 * i + 2);
		Triangles.Add(2 * i + 2 * i + 3);
	}

	//// Connect the last and first vertices to close the ring
	//Triangles.Add(2 * NumSegments - 2);
	//Triangles.Add(0);
	//Triangles.Add(2 * NumSegments - 1);

	//Triangles.Add(2 * NumSegments - 1);
	//Triangles.Add(0);
	//Triangles.Add(1);

	// Set generated data to the procedural mesh component
	ProceduralMeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UV, VertexColors, Tangents, true);

	// Enable collision if needed
	ProceduralMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ProceduralMeshComponent->SetCollisionResponseToAllChannels(ECR_Block);

	// Debug information
	UE_LOG(LogTemp, Warning, TEXT("Saturn Ring Mesh Generated with %d Vertices"), Vertices.Num());

	UMaterial* RingMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Game/CelestialBodies/Saturn/M_SaturnRing"));///Script/Engine.Texture2D'/Game/CelestialBodies/Saturn/8k_saturn_ring_alpha.8k_saturn_ring_alpha'
	if (RingMaterial)
	{
		ProceduralMeshComponent->SetMaterial(0, RingMaterial);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load material for the ring."));
	}
}
