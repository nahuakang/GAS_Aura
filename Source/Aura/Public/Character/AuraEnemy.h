// Copyright Nahua Kang

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	//~ Begin IEnemyInterface Interface.
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
	//~ End IEnemyInterface Interface.

	//~ Begin ICombatInterface Interface.
	virtual int32 GetPlayerLevel() override;
	//~ End ICombatInterface Interface.

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
};
