
// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

using UnrealBuildTool;

public class NansFactorsFactoryUE4 : ModuleRules
{
    public NansFactorsFactoryUE4(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

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
                "NansCoreHelpers",
                "NansTimelineSystemCore",
                "NansFactorsFactoryCore",
                "NansTimelineSystemUE4",
                "NansUE4TestsHelpers"
            }
            );
    }
}
