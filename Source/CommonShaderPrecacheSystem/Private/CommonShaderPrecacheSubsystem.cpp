// Copyright Secret Dimension 2025


#include "CommonShaderPrecacheSubsystem.h"

#include "LoadingScreenManager.h"
#include "ShaderPipelineCache.h"

void UCommonShaderPrecacheSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	if (auto* LoadingScreenManager = GetGameInstance()->GetSubsystem<ULoadingScreenManager>())
	{
		LoadingScreenManager->RegisterLoadingProcessor(this);
	}
}

void UCommonShaderPrecacheSubsystem::Deinitialize()
{
	if (auto* LoadingScreenManager = GetGameInstance()->GetSubsystem<ULoadingScreenManager>())
	{
		LoadingScreenManager->UnregisterLoadingProcessor(this);
	}
	Super::Deinitialize();
}

int32 UCommonShaderPrecacheSubsystem::GetNumPrecompilesRemaining() const
{
	return FShaderPipelineCache::NumPrecompilesRemaining();
}

void UCommonShaderPrecacheSubsystem::SetEnabled(bool bInEnabled)
{
	bEnabled = bInEnabled;
}

bool UCommonShaderPrecacheSubsystem::ShouldShowLoadingScreen(FString& OutReason) const
{
	if (!bEnabled)
	{
		return false;
	}
	
	const auto Remaining = GetNumPrecompilesRemaining();
	if (Remaining > 0)
	{
		OutReason = FString::Printf(TEXT("%d Shaders Compiling"), Remaining);
		return true;
	}
	return false;
}
