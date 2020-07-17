//  Copyright saberuster. All Rights Reserved.


#include "SelectableComponent.h"

// Sets default values for this component's properties
USelectableComponent::USelectableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bIsSelectable = true;
}


void USelectableComponent::Select(APlayerController* PlayerController)
{
	OnSelectedSignature.Broadcast(PlayerController);
}

void USelectableComponent::UnSelect(APlayerController* PlayerController)
{
	OnUnSelectedSignature.Broadcast(PlayerController, false);
}

void USelectableComponent::SetSelectable()
{
	bIsSelectable = true;
}

void USelectableComponent::SetUnSelectable()
{
	bIsSelectable = false;
	OnUnSelectedSignature.Broadcast(nullptr, true);
}

// Called when the game starts
void USelectableComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USelectableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

