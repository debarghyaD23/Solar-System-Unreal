// Fill out your copyright notice in the Description page of Project Settings.


#include "EarthActor.h"

// Sets default values
AEarthActor::AEarthActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set default values for the properties
	SemiMajorAxis = 6300.0f;  // Modify these values as needed
	SemiMinorAxis = 6100.0f;
	OrbitSpeed =5.0f;  // Degrees per second
	CurrentOrbitAngle = 0.0f;
}

// Called when the game starts or when spawned
void AEarthActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEarthActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Set scale for actor
	FVector NewScale = FVector(1.35f, 1.35f, 1.35f);
	RootComponent->SetWorldScale3D(NewScale);

	// Rotate the actor around its own axis
	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = -50.0f; // You can adjust the rotation speed as needed

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

