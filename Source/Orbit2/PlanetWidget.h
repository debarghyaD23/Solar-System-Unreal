// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlanetWidget.generated.h"

/**
 * 
 */
UCLASS()
class ORBIT2_API UPlanetWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	void GenerateRandom();

	UPROPERTY(meta=(BindWidget))
		class UTextBlock* RandomNumberLabel;

	UPROPERTY(meta = (BindWidget))
		class UButton* GenerateButton;

	UFUNCTION()
		void OnGenerateButtonClicked();

	void NativeConstruct() override;
	
};
