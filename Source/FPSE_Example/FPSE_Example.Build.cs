// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FPSE_Example : ModuleRules
{
	public FPSE_Example(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
