﻿// Copyright Nahua Kang

#pragma once

#include "GameplayEffectTypes.h"
#include "AuraAbilityTypes.generated.h"


USTRUCT(BlueprintType)
struct FAuraGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()

public:
	//~Begin FGameplayEffectContext Interface

	/** UE5.2: Returns the actual struct used for serialization, subclasses must override this! */
	// virtual UScriptStruct* GetScriptStruct() const
	// {
	// 	return FGameplayEffectContext::StaticStruct();
	// }

	/** UE5.3: Returns the actual struct used for serialization, subclasses must override this! */
	virtual UScriptStruct* GetScriptStruct() const override
	{
		return StaticStruct();
	}

	/** Custom serialization, subclasses must override this */
	virtual bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess) override;

	/** UE5.2: Creates a copy of this context, used to duplicate for later modifications */
	// virtual FGameplayEffectContext* Duplicate() const
	// {
	// 	FGameplayEffectContext* NewContext = new FGameplayEffectContext();
	// 	*NewContext = *this;
	// 	if (GetHitResult())
	// 	{
	// 		// Does a deep copy of the hit result
	// 		NewContext->AddHitResult(*GetHitResult(), true);
	// 	}
	// 	return NewContext;
	// }

	/** UE5.3: Creates a copy of this context, used to duplicate for later modifications */
	virtual FAuraGameplayEffectContext* Duplicate() const override
	{
		FAuraGameplayEffectContext* NewContext = new FAuraGameplayEffectContext();
		*NewContext = *this;
		if (GetHitResult())
		{
			// Does a deep copy of the hit result
			NewContext->AddHitResult(*GetHitResult(), true);
		}
		return NewContext;
	}

	//~End FGameplayEffectContext Interface

	bool IsCriticalHit() const { return bIsCriticalHit; }
	bool IsBlockedHit() const { return bIsBlockedHit; }

	void SetIsCriticalHit(bool bInIsCriticalHit) { bIsCriticalHit = bInIsCriticalHit; }
	void SetIsBlockedHit(bool bInIsBlockedHit) { bIsBlockedHit = bInIsBlockedHit; }

protected:
	UPROPERTY()
	bool bIsBlockedHit = false;

	UPROPERTY()
	bool bIsCriticalHit = false;
};

template <>
struct TStructOpsTypeTraits<FAuraGameplayEffectContext> : TStructOpsTypeTraitsBase2<FAuraGameplayEffectContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true
	};
};
