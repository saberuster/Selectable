//  Copyright saberuster. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SelectableComponent.generated.h"

class USelectableComponent;

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FOnSelectedSignature, USelectableComponent,  OnSelectedSignature, APlayerController*, PlayerController);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnUnSelectedSignature, USelectableComponent,  OnUnSelectedSignature, APlayerController*, PlayerController, bool, IsCancel);
UCLASS( ClassGroup=(Selectable), meta=(BlueprintSpawnableComponent) )
class SELECTABLE_API USelectableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USelectableComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
public:
	UPROPERTY(BlueprintAssignable,Category="Selectable")
	FOnSelectedSignature OnSelectedSignature;

	UPROPERTY(BlueprintAssignable,Category="Selectable")
	FOnUnSelectedSignature OnUnSelectedSignature;

	UFUNCTION(BlueprintCallable, Category="Selectable")
	void Select(APlayerController* PlayerController);
	
	UFUNCTION(BlueprintCallable, Category="Selectable")
	void UnSelect(APlayerController* PlayerController);
	
	UFUNCTION(BlueprintCallable, Category="Selectable")
	bool IsSelectable() const { return bIsSelectable; }
	
	UFUNCTION(BlueprintCallable, Category="Selectable")
	void SetSelectable();

	UFUNCTION(BlueprintCallable, Category="Selectable")
	void SetUnSelectable();

private:

	uint8 bIsSelectable:1;
		
};
