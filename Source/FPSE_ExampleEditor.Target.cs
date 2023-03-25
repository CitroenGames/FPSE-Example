// Copyright CtitroenGames 2023

using UnrealBuildTool;
using System.Collections.Generic;

public class FPSE_ExampleEditorTarget : TargetRules
{
	public FPSE_ExampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.AddRange( new string[] { "FPSE_Example" } );
	}
}
