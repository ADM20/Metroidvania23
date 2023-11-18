// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Metroidvania23 : ModuleRules
{
	public Metroidvania23(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
