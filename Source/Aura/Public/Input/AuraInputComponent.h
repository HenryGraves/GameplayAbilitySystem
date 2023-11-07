// Copyright (C) Strange Fire Studios

#pragma once

#include "CoreMinimal.h"
#include "AuraInputConfig.h"
#include "EnhancedInputComponent.h"
#include "AuraInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class UserClass, typename PressedFunctionType, typename ReleasedFunctionType, typename HeldFunctionType>
	void BindAbilityActions(const UAuraInputConfig* InputConfig, UserClass* Object, PressedFunctionType PressedFunction, ReleasedFunctionType ReleasedFunction, HeldFunctionType HeldFunction);
};

template <class UserClass, typename PressedFunctionType, typename ReleasedFunctionType, typename HeldFunctionType>
void UAuraInputComponent::BindAbilityActions(const UAuraInputConfig* InputConfig, UserClass* Object,
	PressedFunctionType PressedFunction, ReleasedFunctionType ReleasedFunction, HeldFunctionType HeldFunction)
{
	check(InputConfig)

	for (const FAuraInputAction& Action : InputConfig->AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag.IsValid())
		{
			if (PressedFunction)
			{
				BindAction(Action.InputAction, ETriggerEvent::Started, Object, PressedFunction, Action.InputTag);
			}

			if (ReleasedFunction)
			{
				BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunction, Action.InputTag);
			}
			
			if (HeldFunction)
			{
				BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, HeldFunction, Action.InputTag);
			}
		}
	}
}
