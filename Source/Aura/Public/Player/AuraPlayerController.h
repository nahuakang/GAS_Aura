// Copyright Nahua Kang

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "AuraPlayerController.generated.h"

/**
 * FORWARD DECLARATIONS
 */
class IEnemyInterface;
class UAuraAbilitySystemComponent;
class UAuraInputConfig;
class UInputAction;
class UInputMappingContext;
class USplineComponent;
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
	/** CLICK-TO-MOVE & AUTO-RUN */
	void AbilityInputTagHeld(FGameplayTag InputTag);
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AutoRun();

	void CursorTrace();
	UAuraAbilitySystemComponent* GetASC();
	void Look(const FInputActionValue& InputActionValue);
	void Move(const FInputActionValue& InputActionValue);
	void ShiftPressed() { bShiftKeyDown = true; };
	void ShiftReleased() { bShiftKeyDown = false; };

	bool bShiftKeyDown = false;

	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UAuraInputConfig> InputConfig;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> ShiftAction;

	/** CURSOR TRACE */
	FHitResult CursorHit;
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;

	/** CLICK-TO-MOVE & AUTO-RUN */
	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;            // Acceptance threshold for stopping auto-run

	bool bAutoRunning = false;                       // If auto-run
	bool bTargeting = false;                         // If the mouse cursor is targeting an enemy
	FVector CachedDestination = FVector::ZeroVector; // Cached destination for click-to-move or auto-run
	float FollowTime = 0.f;                          // Cumulative time of following pressed mouse button
	float ShortPressThreshold = 0.5f;                // Threshold for short pressing mouse button

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;             // Spline component for auto-run around obstacles
};
