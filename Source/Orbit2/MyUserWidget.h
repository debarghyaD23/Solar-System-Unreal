// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 *
 */
UCLASS()
class ORBIT2_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/** TextBlock widget to display the message */
	UPROPERTY(meta = (BindWidget),BlueprintReadWrite)
		class UTextBlock* DistanceBlock;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widget")
	//	FText DisplayText;
	/** TextBlock widget to display the message */
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
		class UTextBlock* DiameterBlock;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
		class UTextBlock* MassBlock;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
		class UTextBlock* VelocityBlock;

	UFUNCTION(BlueprintCallable, Category = "UI")
		void SetDistance(const FText& NewText);

	UFUNCTION(BlueprintCallable, Category = "UI")
		void SetDiameter(const FText& NewText);

	UFUNCTION(BlueprintCallable, Category = "UI")
		void SetMass(const FText& NewText);

	UFUNCTION(BlueprintCallable, Category = "UI")
		void SetVelocity(const FText& NewText);

protected:
	/** Native construct override, called when the widget is created */
	virtual void NativeConstruct() override;


};
