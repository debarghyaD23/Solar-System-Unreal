// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Components/TextBlock.h"

void UMyUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // Find the TextBlock widget in the widget blueprint
    //TextBlockWidget = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Message")));
}

void UMyUserWidget::SetDistance(const FText& Message)
{
    if (DistanceBlock)
    {
        // Set the text of the TextBlock widget to the provided message
        DistanceBlock->SetText(Message);
    }
}

void UMyUserWidget::SetDiameter(const FText& Message)
{
    if (DiameterBlock)
    {
        // Set the text of the TextBlock widget to the provided message
        DiameterBlock->SetText(Message);
    }
}

void UMyUserWidget::SetMass(const FText& NewText)
{
    if (MassBlock) {
        MassBlock->SetText(NewText);
    }
}

void UMyUserWidget::SetVelocity(const FText& NewText)
{
    if(VelocityBlock) {
        VelocityBlock->SetText(NewText);
    }
}



