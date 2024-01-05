// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetWidget.h"
#include <Components/Button.h>
#include <Components/TextBlock.h>

void UPlanetWidget::NativeConstruct() {
	Super::NativeConstruct();
	
	GenerateRandom();

	GenerateButton->OnClicked.AddUniqueDynamic(this, &UPlanetWidget::OnGenerateButtonClicked);
}

void UPlanetWidget::GenerateRandom() {
	int32 RandomNumber = FMath::RandRange(0, 100);

	RandomNumberLabel->SetText(FText::AsNumber(RandomNumber));

}

void UPlanetWidget::OnGenerateButtonClicked() {

	GenerateRandom();
}
