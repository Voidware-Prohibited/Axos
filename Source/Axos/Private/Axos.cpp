// Copyright Epic Games, Inc. All Rights Reserved.

#include "Axos.h"
#include "Utility/AxosLog.h"

#if WITH_EDITOR
#include "MessageLogModule.h"
#endif

#define LOCTEXT_NAMESPACE "FAxosModule"

void FAxosModule::StartupModule()
{
	IModuleInterface::StartupModule();

#if WITH_EDITOR
	auto& MessageLog{FModuleManager::LoadModuleChecked<FMessageLogModule>(FName{TEXTVIEW("MessageLog")})};

	FMessageLogInitializationOptions MessageLogOptions;
	MessageLogOptions.bShowFilters = true;
	MessageLogOptions.bAllowClear = true;
	MessageLogOptions.bDiscardDuplicates = true;

	MessageLog.RegisterLogListing(AxosLog::MessageLogName, LOCTEXT("MessageLogLabel", "Axos"), MessageLogOptions);
#endif
}

void FAxosModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAxosModule, Axos)