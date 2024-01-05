// Fill out your copyright notice in the Description page of Project Settings.


#include "JupiterActor.h"

// Sets default values
AJupiterActor::AJupiterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set default values for the properties
	SemiMajorAxis = 8300.0f;  // Modify these values as needed
	SemiMinorAxis = 8250.0f;
	OrbitSpeed = 6.0f;  // Degrees per second
	CurrentOrbitAngle = 0.0f;

}

// Called when the game starts or when spawned
void AJupiterActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJupiterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//this->SetActorLocation(FVector(0, 0, 0));
	//Set scale for actor
	FVector NewScale = FVector(4.f, 4.f, 4.f);
	RootComponent->SetWorldScale3D(NewScale);

	// Rotate the actor around its own axis
	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = 67.5f; // You can adjust the rotation speed as needed

	// Modify the pitch, yaw, or roll based on your requirement
	NewRotation.Yaw -= RotationSpeed * DeltaTime; // Rotate around the Yaw axis

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

