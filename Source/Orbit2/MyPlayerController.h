// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "MyUserWidget.h"
#include "InputMappingContext.h"
#include "MyPlayerController.generated.h"

/**
 *
 */
UCLASS()
class ORBIT2_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMyPlayerController();

	void SetupInputComponent() override;

	UFUNCTION()
		void BeginPlay() override;
	
	UFUNCTION()
		void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<class UUserWidget>WidgetClass;

	UMyUserWidget* WidgetInstance;

	AActor* HitActor;

	double Distance;

	FString Mass, Velocity, Diameter;

	void PerformRaycast();

	UPROPERTY()
		class UInputMappingContext* PawnMappingContext;

	UPROPERTY()
		class UInputAction* ClickAction;

	UPROPERTY()
		class UInputAction* HideAction;

	UFUNCTION(BLueprintCallable, Category = "UI")
		void ShowWidget( FString Mass, FString Velocity, FString Diameter);

	UFUNCTION(BlueprintCallable, Category = "UI")
		void HideWidget();

};