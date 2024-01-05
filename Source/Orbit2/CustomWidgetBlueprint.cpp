//#include "CustomWidgetBlueprint.h"
//#include "Components/TextBlock.h"
//
//void UCustomWidgetBlueprint::SetMassText(const FText& MassValue)
//{
//	UTextBlock* MassTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("MassText")));
//	if (MassTextBlock)
//	{
//		MassTextBlock->SetText(MassValue);
//	}
//}
//
//void UCustomWidgetBlueprint::SetVelocityText(const FText& VelocityValue)
//{
//	UTextBlock* VelocityTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("VelocityText")));
//	if (VelocityTextBlock)
//	{
//		VelocityTextBlock->SetText(VelocityValue);
//	}
//}
//
//void UCustomWidgetBlueprint::SetDiameterText(const FText& DiameterValue)
//{
//	UTextBlock* DiameterTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("DiameterText")));
//	if (DiameterTextBlock)
//	{
//		DiameterTextBlock->SetText(DiameterValue);
//	}
//}
//
//void UCustomWidgetBlueprint::SetDistanceText(const FText& DistanceValue)
//{
//	UTextBlock* DistanceTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("DistanceText")));
//	if (DistanceTextBlock)
//	{
//		DistanceTextBlock->SetText(DistanceValue);
//	}
//}
//
//void UCustomWidgetBlueprint::CloseWidget()
//{
//	// Implement the logic to close or hide the widget here
//	SetVisibility(false);
//}
//
//void UCustomWidgetBlueprint::SetVisibility(bool bVisible)
//{
//	// Get the root canvas panel or top-level widget component of the user widget
//	UWidget* RootWidget = GetRootWidget();
//
//	// Set the visibility of the root widget component based on the input parameter
//	if (RootWidget)
//	{
//		if (bVisible)
//		{
//			RootWidget->SetVisibility(ESlateVisibility::Visible);
//		}
//		else
//		{
//			RootWidget->SetVisibility(ESlateVisibility::Hidden);
//		}
//	}
//}

