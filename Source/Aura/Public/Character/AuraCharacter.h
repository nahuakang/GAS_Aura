// Copyright Nahua Kang

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 *
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	//~ End APawn Interface.

	//~ Begin ICombatInterface Interface.
	virtual int32 GetPlayerLevel() override;
	//~ End ICombatInterface Interface.

protected:
	virtual void InitAbilityActorInfo() override;
};
