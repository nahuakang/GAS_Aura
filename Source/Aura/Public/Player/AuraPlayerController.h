// Copyright Nahua Kang

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class IEnemyInterface;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

/**
 *
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();

	//~ Begin APlayerController Interface.
	virtual void PlayerTick(float DeltaTime) override;
	//~ End APlayerController Interface.

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void CursorTrace();
	void Look(const FInputActionValue& InputActionValue);
	void Move(const FInputActionValue& InputActionValue);

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
};
