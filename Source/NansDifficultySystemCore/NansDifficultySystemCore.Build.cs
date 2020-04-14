
using UnrealBuildTool;

public class NansDifficultySystemCore : ModuleRules
{
    public NansDifficultySystemCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        // This to allow dynamic_cast
        // https://answers.unrealengine.com/questions/477792/how-do-i-cast-between-polymorphic-classes-that-don.html?sort=oldest
        bUseRTTI = true;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "NansCoreHelpers"
            }
            );
    }
}
