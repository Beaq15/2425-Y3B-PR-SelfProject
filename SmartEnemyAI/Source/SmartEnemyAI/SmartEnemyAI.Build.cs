// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SmartEnemyAI : ModuleRules
{
	public SmartEnemyAI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "AIModule", "NavigationSystem", "GameplayTasks", "GameplayTags", "Engine", "InputCore", "EnhancedInput" });
	}
}
