// Copyright Secret Dimension 2025

#pragma once

#include "CoreMinimal.h"
#include "LoadingProcessInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CommonShaderPrecacheSubsystem.generated.h"

/**
 * Per-game subsystem that will hold your loading screen if there are shaders pre-compiling
 */
UCLASS()
class COMMONSHADERPRECACHESYSTEM_API UCommonShaderPrecacheSubsystem : public UGameInstanceSubsystem, public ILoadingProcessInterface
{
	GENERATED_BODY()

public:
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	virtual void Deinitialize() override;
	
	// Exposes FShaderPipelineCache::NumPrecompilesRemaining to blueprint callers
	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual int32 GetNumPrecompilesRemaining() const;

	/*
	 * Set whether or not to override this subsystem and *not* hold the loading screen even if there are pre-compiles.
	 * This is useful if you are in an open-world scenario and don't want pre-compiles after the initial load-in.
	 * OR you could leave this on and instead have your loading screen act as a way to detect shader hitches.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void SetDisabled(bool bInDisabled);
	
	// ILoadingProcessInterface Begin
	virtual bool ShouldShowLoadingScreen(FString& OutReason) const override;
	// ILoadingProcessInterface End

protected:
	// If true, this system will not hold the loading screen even if there are shader pre-compiles
	UPROPERTY()
	bool bDisabled = false;
};
