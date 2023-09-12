// Copyright Nahua Kang

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS()
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	/** <AActor> */
	AAuraCharacterBase();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	/** </AActor> */

protected:
	virtual void BeginPlay() override;

};
