// Copyright Nahua Kang


#include "AuraAssetManager.h"

#include "AbilitySystemGlobals.h"
#include "AuraGameplayTags.h"


UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);

	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAuraGameplayTags::InitializeNativeGameplayTags();
	// Required to use Target Data in custom Ability Tasks like TargetDataUnderMouse
	UAbilitySystemGlobals::Get().InitGlobalData(); // NOTE: Doesn't need this in UE5.3
}
