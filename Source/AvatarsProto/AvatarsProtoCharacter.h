#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Projectile.h"
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

	// Function that handles firing projectiles.
	UFUNCTION(Server,Reliable)
	void Fire();

	// Gun muzzle offset from the camera location.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

	// Projectile class to spawn.
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AProjectile> ProjectileClass;

public:

	/* The current health of this player*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Player_Stats)
	float Life;

	/* The current level of this player*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Player_Stats)
	float Shield;

	/*The amount of kills of this player*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player_Stats)
	int Kills;

	/* The defence amount of this player*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Stats, meta=(ClampMin="1",ClampMax="100"))
	int Defence;

	/* The attack amount of this player*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Stats, meta = (ClampMin = "1", ClampMax = "100"))
	int Attack;

};

