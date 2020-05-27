
using UnrealBuildTool;

public class NansFactorsFactoryUE4 : ModuleRules
{
    public NansFactorsFactoryUE4(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        // TODO remove this when all CORE tests are made with GG tests
        // This to allow dynamic_cast
        // https://answers.unrealengine.com/questions/477792/how-do-i-cast-between-polymorphic-classes-that-don.html?sort=oldest
        bUseRTTI = true;

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
                "UnrealEd",
                "BlueprintGraph",
                "GraphEditor",
                "PropertyEditor",
                "SlateCore",
                "Slate",
                "EditorStyle",
                "Kismet",
                "KismetCompiler",
                "InputCore",
                "NansTimelineSystemCore",
                "NansFactorsFactoryCore",
                "NansTimelineSystemUE4",
                "NansUE4TestsHelpers"
            }
            );
    }
}
