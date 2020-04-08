
using UnrealBuildTool;

public class NansDifficultySystemUE4 : ModuleRules
{
    public NansDifficultySystemUE4(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                // ... add other public dependencies that you statically link with here ...
            }
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "UnrealEd",
                "KismetCompiler",
                "BlueprintGraph",
                "InputCore",
                "NansCommon",
                "NansDifficultySystemCore",
            }
            );
    }
}
