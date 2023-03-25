// Copyright CtitroenGames 2023

using UnrealBuildTool;
using System.Collections.Generic;

public class FPSE_ExampleTarget : TargetRules
{
	public FPSE_ExampleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "FPSE_Example" } );
	}
}
