// Copyright Nahua Kang


#include "UI/HUD/AuraHUD.h"

#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(
	const FWidgetControllerParams& WidgetControllerParams)
{
	if (AttributeMenuWidgetController == nullptr)
	{
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->SetWidgetControllerParams(WidgetControllerParams);
		AttributeMenuWidgetController->BindCallbacksToDependencies(); // Bind callback dependencies for attributechanges

		return AttributeMenuWidgetController;
	}

	return AttributeMenuWidgetController;
}

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WidgetControllerParams);
		OverlayWidgetController->BindCallbacksToDependencies(); // Bind callback dependencies for attribute changes

		return OverlayWidgetController;
	}

	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(
	APlayerController* PlayerController,
	APlayerState* PlayerState,
	UAbilitySystemComponent* AbilitySystemComponent,
	UAttributeSet* AttributeSet
)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass uninitialized. Please fill it out in BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass uninitialized. Please fill it out in BP_AuraHUD"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues(); // Broadcast after Widget is hooked to the widget controller

	Widget->AddToViewport();
}
