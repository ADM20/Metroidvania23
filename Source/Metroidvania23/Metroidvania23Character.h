// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Metroidvania23Character.generated.h"


// Player Stats
USTRUCT(BlueprintType)
struct FPlayerStats
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	int HP = 10;
};

UCLASS(config=Game)
class AMetroidvania23Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* DashAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability | Dash", meta = (AllowPrivateAccess = "true"))
		int DashForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability | Dash", meta = (AllowPrivateAccess = "true"))
		float MaxDashCooldown;

	// Player Stats
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats", meta = (AllowPrivateAccess = "true"))
		FPlayerStats Stats;

public:
	AMetroidvania23Character();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			
	void Dash(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime);


public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability | Dash", meta = (AllowPrivateAccess = "true"))
	bool IsDashOnCooldown;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability | Dash", meta = (AllowPrivateAccess = "true"))
	float DashCooldownTimer;

	int DashAmount;
};

