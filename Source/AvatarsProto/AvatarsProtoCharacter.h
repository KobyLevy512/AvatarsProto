// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AvatarsProtoCharacter.generated.h"

UCLASS(config=Game)
class AAvatarsProtoCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAvatarsProtoCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;
protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

public:
	/* The current health of this player*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player_Stats")
	float Life;

	/*The amount of kills of this player*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player_Stats)
	int Kills;

	/* The current level of this player*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Player_Stats)
	float Level;

	/* The defence amount of this player*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Stats, meta=(ClampMin="1",ClampMax="20"))
	float Defence;

	/* The attack amount of this player*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Stats, meta = (ClampMin = "1", ClampMax = "20"))
	float Attack;
};

