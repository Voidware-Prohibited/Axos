// Copyright Epic Games, Inc. All Rights Reserved.

using System.Linq;
using UnrealBuildTool;

public class Axos : ModuleRules
{
	public Axos(ReadOnlyTargetRules Target) : base(Target)
	{
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_7;
		
		// [CD/CI] For Code Coverage to run properly you can toggle optimization based on a custom flag: WITH_COVERAGE=1
		// To Activate, run build with: -define:WITH_COVERAGE=1
		if (Target.GlobalDefinitions.Contains("WITH_COVERAGE=1"))
		{
			OptimizeCode = CodeOptimization.Never;
			bUseUnity = false;
		}
		
		CppCompileWarningSettings.NonInlinedGenCppWarningLevel = WarningLevel.Warning;
		
		PublicDependencyModuleNames.AddRange([
				"Core", "DeveloperSettings", "GameplayTags"
			]
			);
			
		
		PrivateDependencyModuleNames.AddRange([
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UMG"
			]
			);
		
		if (Target.Type == TargetRules.TargetType.Editor)
        {
        	PrivateDependencyModuleNames.AddRange([
        		"MessageLog"
        	]);
        }

	}
}
