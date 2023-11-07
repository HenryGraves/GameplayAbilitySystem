// Copyright (C) Strange Fire Studios


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"
#include "AbilitySystemGlobals.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine)
	
	UAuraAssetManager* AAM = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AAM;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAuraGameplayTags::InitializeNativeGameplayTags();

	// this is required in order to use TargetData;
	UAbilitySystemGlobals::Get().InitGlobalData();
}
