#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorSpec,
    "Nans.FactorsFactory.Core.Factor.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FactorSpec)
void FactorSpec::Define()
{
    Describe("How to use factor", [this]() {
        It("should get an unique ID", [this]() {
            TArray<NFactor*, TInlineAllocator<50>> Factors;
            TArray<uint32, TInlineAllocator<50>> Ids;
            for (int32 Index = 0; Index < 50; Index++)
            {
                NFactor* Factor = new NFactor(0, new NNullOperator(), 0, FName("Oreason"));
                // need to stay in life to ensure unique ID
                Factors.Add(Factor);
                Ids.AddUnique(Factor->GetUID());
            }

            Factors.Empty();

            TEST_EQUAL("Test uniqueID", (uint32) Ids.Num(), (uint32) 50);

            Ids.Empty();
        });

        // not useful now, but keep in mind how to use try catch block
        // It("should triggered an error if try to call function before initialized correctly", [this]() {
        //     NFactor* Factor = new NFactor(0, new NNullOperator(), 0, FName("Oreason"));
        //     try
        //     {
        //         Factor->IsActivate();
        //         TEST_TRUE("Should not be called", false);
        //     }
        //     catch (const TCHAR* e)
        //     {
        //         TEST_EQUAL("Error has been triggered: Operator != nullptr", e, TEXT("Operator != nullptr"));
        //     }
        // });

        It("should deactivate when his duration is exceeded", [this]() {
            INFactorInterface* Factor = new NFactor(2, new NMultiplyOperator(), 2, FName("Exhausted"));
            TEST_TRUE("Should be activate", Factor->IsActivate());
            Factor->AddTime(2.1f);
            TEST_FALSE("Should not be activate", Factor->IsActivate());
            TEST_NOT_NULL("Should return a NullOperator", static_cast<NNullOperator*>(Factor->GetOperator()));
            TEST_EQUAL("Should return value of 0.f", Factor->GetFactorValue(), 0.f);
        });

        It("should works infinitely if his duration initializer is 0", [this]() {
            INFactorInterface* Factor = new NFactor(2, new NMultiplyOperator(), 0, FName("Exhausted"));

            TEST_TRUE("Should be activate", Factor->IsActivate());
            TEST_EQUAL("Should get a factor value to 2.f", Factor->GetFactorValue(), 2.f);
            Factor->AddTime(10000000.f);
            TEST_TRUE("Should still be activated", Factor->IsActivate());
            TEST_EQUAL("Should still get a factor value to 2.f", Factor->GetFactorValue(), 2.f);
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS
