// Fill out your copyright notice in the Description page of Project Settings.


#include "SunActor.h"
#include "Components/PointLightComponent.h"
#include "UObject/ConstructorHelpers.h" 

// Sets default values
ASunActor::ASunActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create and attach the PointLightComponent
    PointLightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
    RootComponent = PointLightComponent;
    // Set default values for the PointLightComponent
    PointLightComponent->Intensity = 5000.0f;
    PointLightComponent->AttenuationRadius = 5000.0f;
    PointLightComponent->LightColor = FColor::Yellow;

    // Set mobility to Movable
    PointLightComponent->Mobility = EComponentMobility::Movable;

    // Load a sphere static mesh (replace "Path/To/Your/SphereMesh" with the actual path)
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("Game/StarterContent/Shapes/Shape_Sphere"));///Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'
    if (SphereMeshAsset.Succeeded())
    {
        UStaticMeshComponent* SphereMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
        SphereMeshComponent->SetStaticMesh(SphereMeshAsset.Object);
        SphereMeshComponent->SetupAttachment(RootComponent);
    }
}

// Called when the game starts or when spawned
void ASunActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASunActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Set scale for actor
    SetActorLocation(FVector(0.f, 0.f, 0.f));
	FVector NewScale = FVector(15.f, 15.f, 15.f);
	RootComponent->SetWorldScale3D(NewScale);

}

