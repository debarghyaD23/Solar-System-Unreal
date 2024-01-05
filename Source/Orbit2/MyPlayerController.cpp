// Fill out// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController() {	///Script/UMGEditor.WidgetBlueprint'.WBP_MyUserWidget'

	static ConstructorHelpers::FClassFinder<UMyUserWidget>panelWidgetClass(TEXT("/Game/Blueprints/WBP_MyUserWidget"));///Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/WBP_MyUserWidget.WBP_MyUserWidget'
	WidgetClass = panelWidgetClass.Class;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;//show mouse cursor on viewport all the time

	// Show the widget when the game starts (optional)

	if (!WidgetInstance && WidgetClass)
	{
		WidgetInstance = CreateWidget<UMyUserWidget>(this, WidgetClass);
	}
	//ShowWidget();
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	if (HitActor)
	{
		// Show the widget for the selected actor
		//double Distance = 0;
		FVector ActorLocation = HitActor->GetActorLocation();
		double XValue = ActorLocation.X;
		double YValue = ActorLocation.Y;
		double ZValue = ActorLocation.Z;
		Distance = FMath::Sqrt(FMath::Square(XValue) + FMath::Square(YValue) + FMath::Square(ZValue));

		if (WidgetInstance)
		{
			//WidgetInstance->AddToViewport();
			this->Mass = ""; 
			this->Velocity = ""; 
			this->Diameter = "";

			FVector ActorScale = HitActor->GetActorScale3D();

			// Define the desired scale
			FVector DesiredScale = FVector(15.f, 15.f, 15.f); // Change this to the scale you want to compare with

			// Check if the actor's scale is equal to the desired scale
			
			if (Distance >= 4000 && Distance <= 4300) {
				Mass = "Mercury Mass: 3.285 x 10^23 kg";
				Diameter = "Mercury Diameter: 4 879.4 km";
				Velocity = "Mercury Velocity: 47.4 km/s";
			}

			else if (Distance >= 5200 && Distance <= 5300) {
				Mass = "Venus Mass: 4.867 x 10^24 kg";
				Diameter = "Venus Diameter: 12,104 km";
				Velocity = "Venus Velocity: 35.02 km/s";
			}
			else if (Distance >= 6100 && Distance <= 6300) {
				Mass = "Earth Mass: 5.972 x 10^24 kg";
				Diameter = "Earth Diameter: 12,742 km";
				Velocity = "Earth Velocity: 29.78 km/s";
			}
			else if (Distance >= 7250 && Distance <= 7300) {
				Mass = "Mars Mass: 6.39 x 10^23 kg";
				Diameter = "Mars Diameter: 6,779 km";
				Velocity = "Mars Velocity: 24.08 km/s";
			}
			else if (Distance >= 8250 && Distance <= 8350) {
				Mass = "Jupiter Mass: 1.898 x 10^27 kg";
				Diameter = "Jupiter Diameter: 139,820 km";
				Velocity = "Jupiter Velocity: 13.06 km/s";
			}
			else if (Distance >= 10250 && Distance <= 10350) {
				Mass = "Saturn Mass: 5.683 x 10^26 kg";
				Diameter = "Saturn Diameter: 120,536 km";
				Velocity = "Saturn Velocity: 9.68 km/s";
			}
			else if (Distance >= 12250 && Distance <= 12300) {
				Mass = "Uranus Mass: 8.681 x 10^25 kg";
				Diameter = "Uranus Diameter: 50,724 km";
				Velocity = "Uranus Velocity: 6.80 km/s";
			}
			else if (Distance >= 13250 && Distance <= 13300) {
				Mass = "Neptune Mass: 1.024 x 10^26 kg";
				Diameter = "Neputne Diameter: 49,244 km";
				Velocity = "Neptune Velocity: 5.45 km/s";
			}
			else {
				if (ActorScale.Equals(DesiredScale)) {
					Mass = "Sun Mass: 1.9891 x 10^30 kg";
					Diameter = "Sun Diameter: 1.3927 million km";
					Velocity = "Sun Velocity: 251 km/s";
				}
				else Mass = "You clicked on an orbit";
			}

			ShowWidget(Mass, Velocity, Diameter);
			
		}
	}
}

void AMyPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();
	PawnMappingContext = NewObject<UInputMappingContext>(this);


	ClickAction = NewObject<UInputAction>(this);
	ClickAction->ValueType = EInputActionValueType::Axis3D;
	PawnMappingContext->MapKey(ClickAction, EKeys::LeftMouseButton);
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(this->InputComponent);
	EIC->BindAction(ClickAction, ETriggerEvent::Triggered, this, &AMyPlayerController::PerformRaycast);

	HideAction = NewObject<UInputAction>(this);
	HideAction->ValueType = EInputActionValueType::Axis1D;
	PawnMappingContext->MapKey(HideAction, EKeys::RightMouseButton);
	EIC->BindAction(HideAction, ETriggerEvent::Triggered, this, &AMyPlayerController::HideWidget);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = this->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(this->PawnMappingContext, 0);
}

void AMyPlayerController::PerformRaycast() {

	FVector WorldLocation, WorldDirection;
	DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

	FVector Start = WorldLocation;
	FVector End = Start + WorldDirection * 100000.f; // Ray length: 10000 units

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this); // Ignore the player controller during raycasting

	// Perform the raycast
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams))
	{
		HitActor = HitResult.GetActor();
	}
}

void AMyPlayerController::HideWidget() {
	HitActor = nullptr;
	if(WidgetInstance)WidgetInstance->SetVisibility(ESlateVisibility::Hidden);
}

void AMyPlayerController::ShowWidget( FString M, FString V, FString D) {

	if (WidgetInstance) {
		/*int32 RandomNumber = FMath::RandRange(1, 100);

		FString Message = FString::Printf(TEXT("Random Number: %d"), RandomNumber);*/
		FString Message = FString::Printf(TEXT("Distance from Sun: %f"), Distance);
		if (!Distance)Message = "";
		WidgetInstance->SetDistance(FText::FromString(Message));
		WidgetInstance->SetMass(FText::FromString(M));
		WidgetInstance->SetDiameter(FText::FromString(D));
		WidgetInstance->SetVelocity(FText::FromString(V));
		WidgetInstance->SetVisibility(ESlateVisibility::Visible);
		UE_LOG(LogTemp, Warning, TEXT("Some warning message"));
		WidgetInstance->AddToViewport();
		//WidgetInstance->SetMessage(FText::FromString("Left Mouse Button Clicked!")); // Set your desired message here
	}
}

