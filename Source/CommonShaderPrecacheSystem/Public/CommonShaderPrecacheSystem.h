// Copyright Secret Dimension 2025

#pragma once

#include "Modules/ModuleManager.h"

class FCommonShaderPrecacheSystemModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
