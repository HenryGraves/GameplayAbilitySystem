// Copyright (C) Strange Fire Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Input/AuraInputConfig.h"
#include "GameplayTagContainer.h"
#include "AuraPlayerController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
class IEnemyInterface;
class UAuraAbilitySystemComponent;
class USplineComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	void AutoRun();
	virtual void PlayerTick(float DeltaTime) override;
	FHitResult& GetCursorHitReference() { return CursorHit; }
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void CursorTrace();
	void Move(const FInputActionValue& InputActionValue);
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	void SpacebarPressed() { bSpacebarKeyDown = true; }
	void SpacebarReleased() { bSpacebarKeyDown = false; }
	UAuraAbilitySystemComponent* GetASC();

	FHitResult CursorHit;

	bool bSpacebarKeyDown = false;

	UPROPERTY(EditAnywhere, Category=Input)
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category=Input)
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category=Input)
	TObjectPtr<UInputAction> SpacebarAction;

	TObjectPtr<IEnemyInterface> LastActor;
	
	TObjectPtr<IEnemyInterface> ThisActor;

	UPROPERTY(EditDefaultsOnly, Category=Input)
	TObjectPtr<UAuraInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;

	FVector CachedDestination = FVector::ZeroVector;

	float FollowTime = 0.f;

	float ShortPressThreshold = 0.5f;

	bool bAutoRunning = false;

	bool bTargeting = false;

	UPROPERTY(EditAnywhere)
	float AutoRunAcceptanceRadius = 50.f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;
};


