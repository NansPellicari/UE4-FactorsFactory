# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`UnrealBuildTool::Rules`](#namespaceUnrealBuildTool_1_1Rules) | 
`class `[`FakeFactor`](#classFakeFactor) | 
`class `[`FakeTimelineManager`](#classFakeTimelineManager) | 
`class `[`FNansFactorsFactoryCoreModule`](#classFNansFactorsFactoryCoreModule) | 
`class `[`FNansFactorsFactoryEdModule`](#classFNansFactorsFactoryEdModule) | 
`class `[`FNansFactorsFactoryUE4Module`](#classFNansFactorsFactoryUE4Module) | 
`class `[`FNFactorAttributeCustomization`](#classFNFactorAttributeCustomization) | 
`class `[`FNFactorSettingsPinFactory`](#classFNFactorSettingsPinFactory) | 
`class `[`INFactorsFactoryGameInstance`](#classINFactorsFactoryGameInstance) | 
`class `[`NAddOperator`](#classNAddOperator) | 
`class `[`NansFactorsFactoryCore`](#classNansFactorsFactoryCore) | 
`class `[`NansFactorsFactoryUE4`](#classNansFactorsFactoryUE4) | 
`class `[`NCleanerOperator`](#classNCleanerOperator) | This operator is raw! It removes every previous operator set in the factor's units queue. For the [Compute()](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6) method, it returns the value set at the Rh parameter (means that the factor Unit value associated replace every previous value).
`class `[`NDividerOperator`](#classNDividerOperator) | 
`class `[`NFactor`](#classNFactor) | 
`class `[`NFactorInterface`](#classNFactorInterface) | 
`class `[`NFactorOperatorBreakerInterface`](#classNFactorOperatorBreakerInterface) | 
`class `[`NFactorOperatorInterface`](#classNFactorOperatorInterface) | 
`class `[`NFactorOperatorPersistentInterface`](#classNFactorOperatorPersistentInterface) | 
`class `[`NFactorOperatorStopperInterface`](#classNFactorOperatorStopperInterface) | 
`class `[`NFactorOperatorWithFactorInterface`](#classNFactorOperatorWithFactorInterface) | 
`class `[`NFactorsFactoryClient`](#classNFactorsFactoryClient) | 
`class `[`NFactorsFactoryClientInterface`](#classNFactorsFactoryClientInterface) | 
`class `[`NFactorState`](#classNFactorState) | 
`class `[`NFactorStateInterface`](#classNFactorStateInterface) | 
`class `[`NFactorUnit`](#classNFactorUnit) | 
`class `[`NFactorUnitInterface`](#classNFactorUnitInterface) | 
`class `[`NIncreasersCleanerOperator`](#classNIncreasersCleanerOperator) | This operator is raw! It removes every previous operator set in the factor's units queue. It cleans only factor's unit which implies factor amount increase. The Rh parameter of the [Compute()](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6) method determines the amount of FactorUnit removed (0 = all). For the [Compute()](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6) method it doesn't make any computation by returning the Lh parameter.
`class `[`NIncreasersCleanerPersistentOperator`](#classNIncreasersCleanerPersistentOperator) | This operator is raw! It removes every previous operator set in the factor's units queue. It cleans only factor's unit which implies factor amount increase. The Rh parameter of the [Compute()](#classNIncreasersCleanerPersistentOperator_1af2f61cf4d96ea081ba35ee09dfa1bcf8) method determines the amount of FactorUnit removed (0 = all). For the [Compute()](#classNIncreasersCleanerPersistentOperator_1af2f61cf4d96ea081ba35ee09dfa1bcf8) method it doesn't make any computation by returning the Lh parameter. It removes also next Increasers set.
`class `[`NMultiplyOperator`](#classNMultiplyOperator) | 
`class `[`NNullFactorUnit`](#classNNullFactorUnit) | 
`class `[`NNullOperator`](#classNNullOperator) | 
`class `[`NOperatorUtils`](#classNOperatorUtils) | 
`class `[`NReducersCleanerOperator`](#classNReducersCleanerOperator) | This operator is raw! It removes every previous operator set in the factor's units queue. It cleans only factor's unit which implies factor amount reduction. The Rh parameter of the [Compute()](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6) method determines the amount of FactorUnit removed (0 = all). For the [Compute()](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6) method it doesn't make any computation by returning the Lh parameter.
`class `[`NReducersCleanerPersistentOperator`](#classNReducersCleanerPersistentOperator) | This operator is raw! It removes every previous operator set in the factor's units queue. It cleans only factor's unit which implies factor amount reduction. The Rh parameter of the [Compute()](#classNReducersCleanerPersistentOperator_1a378e8aef2e4db7ff7a085ee18baba7f9) method determines the amount of FactorUnit removed (0 = all). For the [Compute()](#classNReducersCleanerPersistentOperator_1a378e8aef2e4db7ff7a085ee18baba7f9) method it doesn't make any computation by returning the Lh parameter. It removes also next Reducers set.
`class `[`NReplacerOperator`](#classNReplacerOperator) | This operator replace the value from the previous operators list (It doesn't care of the Lh parameter of the method Compute). For the [Compute()](#classNReplacerOperator_1acc351a22cc2268269e0a2c531bf4be46) method, it returns the value set at the Rh parameter.
`class `[`NResetOperator`](#classNResetOperator) | This class find a previous FactorUnit and try to reset it. The Rh parameter of the [Compute()](#classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e) method determines the previous position (The Index of the FactorUnit which embeds this Operator - Rh) of the FactorUnit you want to reset.
`class `[`NResetOperatorBase`](#classNResetOperatorBase) | 
`class `[`NSubtractOperator`](#classNSubtractOperator) | 
`class `[`NUnrealFactorProxy`](#classNUnrealFactorProxy) | 
`class `[`NUnrealFactorUnitProxy`](#classNUnrealFactorUnitProxy) | 
`class `[`SNFactorSettingsPin`](#classSNFactorSettingsPin) | 
`class `[`UFactorSettings`](#classUFactorSettings) | This allow to
`class `[`UK2Node_FactorUnit`](#classUK2Node__FactorUnit) | TODO: This class needs to be cleaned, refactored and documented
`class `[`UNFactorDecorator`](#classUNFactorDecorator) | 
`class `[`UNFactorsFactoryBlueprintHelpers`](#classUNFactorsFactoryBlueprintHelpers) | 
`class `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter) | 
`class `[`UNFactorsFactoryGameInstance`](#classUNFactorsFactoryGameInstance) | 
`class `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter) | 
`class `[`UNOperatorCleaners`](#classUNOperatorCleaners) | 
`class `[`UNOperatorProviderBase`](#classUNOperatorProviderBase) | 
`class `[`UNOperatorSimpleOperations`](#classUNOperatorSimpleOperations) | 
`class `[`UNResetOperatorProvider`](#classUNResetOperatorProvider) | 
`struct `[`FFactorAttribute`](#structFFactorAttribute) | 
`struct `[`FFactorUnitUtilities`](#structFFactorUnitUtilities) | This utility class is made to helps the [UK2Node_FactorUnit::ExpandNode()](#classUK2Node__FactorUnit_1a2e5e0b8e6114590dc36d9fa471d0055f).
`struct `[`FNFactorSettings`](#structFNFactorSettings) | 
`struct `[`FNFactorStateOperator`](#structFNFactorStateOperator) | 
`struct `[`FNFactorStateResult`](#structFNFactorStateResult) | 
`struct `[`FNFactorUnitRecord`](#structFNFactorUnitRecord) | This struct is a record object used for savegame or get user feedbacks

# namespace `UnrealBuildTool::Rules` <a id="namespaceUnrealBuildTool_1_1Rules"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`UnrealBuildTool::Rules::NansFactorsFactoryEd`](#classUnrealBuildTool_1_1Rules_1_1NansFactorsFactoryEd) | 

# class `UnrealBuildTool::Rules::NansFactorsFactoryEd` <a id="classUnrealBuildTool_1_1Rules_1_1NansFactorsFactoryEd"></a>

```
class UnrealBuildTool::Rules::NansFactorsFactoryEd
  : public ModuleRules
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NansFactorsFactoryEd`](#classUnrealBuildTool_1_1Rules_1_1NansFactorsFactoryEd_1a9d17074a7ce540e7a3349779ad316185)`(ReadOnlyTargetRules Target)` | 

## Members

#### `public inline  `[`NansFactorsFactoryEd`](#classUnrealBuildTool_1_1Rules_1_1NansFactorsFactoryEd_1a9d17074a7ce540e7a3349779ad316185)`(ReadOnlyTargetRules Target)` <a id="classUnrealBuildTool_1_1Rules_1_1NansFactorsFactoryEd_1a9d17074a7ce540e7a3349779ad316185"></a>

# class `FakeFactor` <a id="classFakeFactor"></a>

```
class FakeFactor
  : public NFactor
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`FakeFactor`](#classFakeFactor_1a5b231e44be3dcdb7b2b09798fb4e97ec)`(FName _Name,TSharedPtr< NTimeline > _Timeline)` | 
`public inline virtual void `[`SupplyStateWithCurrentData`](#classFakeFactor_1a98a6309bc5ce9dda9293ee333eb22425)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` | 

## Members

#### `public inline  `[`FakeFactor`](#classFakeFactor_1a5b231e44be3dcdb7b2b09798fb4e97ec)`(FName _Name,TSharedPtr< NTimeline > _Timeline)` <a id="classFakeFactor_1a5b231e44be3dcdb7b2b09798fb4e97ec"></a>

#### `public inline virtual void `[`SupplyStateWithCurrentData`](#classFakeFactor_1a98a6309bc5ce9dda9293ee333eb22425)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` <a id="classFakeFactor_1a98a6309bc5ce9dda9293ee333eb22425"></a>

# class `FakeTimelineManager` <a id="classFakeTimelineManager"></a>

```
class FakeTimelineManager
  : public NTimelineManager
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `FNansFactorsFactoryCoreModule` <a id="classFNansFactorsFactoryCoreModule"></a>

```
class FNansFactorsFactoryCoreModule
  : public IModuleInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`StartupModule`](#classFNansFactorsFactoryCoreModule_1a5a0a42186b2bdc12820bff0f79be38ae)`()` | IModuleInterface implementation
`public virtual void `[`ShutdownModule`](#classFNansFactorsFactoryCoreModule_1a030ed9a6a6cded0f22258aebc2cef7f4)`()` | 

## Members

#### `public virtual void `[`StartupModule`](#classFNansFactorsFactoryCoreModule_1a5a0a42186b2bdc12820bff0f79be38ae)`()` <a id="classFNansFactorsFactoryCoreModule_1a5a0a42186b2bdc12820bff0f79be38ae"></a>

IModuleInterface implementation

#### `public virtual void `[`ShutdownModule`](#classFNansFactorsFactoryCoreModule_1a030ed9a6a6cded0f22258aebc2cef7f4)`()` <a id="classFNansFactorsFactoryCoreModule_1a030ed9a6a6cded0f22258aebc2cef7f4"></a>

# class `FNansFactorsFactoryEdModule` <a id="classFNansFactorsFactoryEdModule"></a>

```
class FNansFactorsFactoryEdModule
  : public IModuleInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`StartupModule`](#classFNansFactorsFactoryEdModule_1af5570f4b64671e7fe140a0c1a286e878)`()` | IModuleInterface implementation
`public virtual void `[`ShutdownModule`](#classFNansFactorsFactoryEdModule_1a7c5551eacc713ea274b191f2b8870767)`()` | 
`protected TSharedPtr< `[`FNFactorSettingsPinFactory`](#classFNFactorSettingsPinFactory)` > `[`FactorSettingsPinFactory`](#classFNansFactorsFactoryEdModule_1af945e3d047a1be9cc1b2e80e1dc6bd4b) | 

## Members

#### `public virtual void `[`StartupModule`](#classFNansFactorsFactoryEdModule_1af5570f4b64671e7fe140a0c1a286e878)`()` <a id="classFNansFactorsFactoryEdModule_1af5570f4b64671e7fe140a0c1a286e878"></a>

IModuleInterface implementation

#### `public virtual void `[`ShutdownModule`](#classFNansFactorsFactoryEdModule_1a7c5551eacc713ea274b191f2b8870767)`()` <a id="classFNansFactorsFactoryEdModule_1a7c5551eacc713ea274b191f2b8870767"></a>

#### `protected TSharedPtr< `[`FNFactorSettingsPinFactory`](#classFNFactorSettingsPinFactory)` > `[`FactorSettingsPinFactory`](#classFNansFactorsFactoryEdModule_1af945e3d047a1be9cc1b2e80e1dc6bd4b) <a id="classFNansFactorsFactoryEdModule_1af945e3d047a1be9cc1b2e80e1dc6bd4b"></a>

# class `FNansFactorsFactoryUE4Module` <a id="classFNansFactorsFactoryUE4Module"></a>

```
class FNansFactorsFactoryUE4Module
  : public IModuleInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`StartupModule`](#classFNansFactorsFactoryUE4Module_1ac697d536a09d235c2d001ff038930457)`()` | IModuleInterface implementation
`public virtual void `[`ShutdownModule`](#classFNansFactorsFactoryUE4Module_1abbbd4accea0843010d6a5ba3683889f2)`()` | 

## Members

#### `public virtual void `[`StartupModule`](#classFNansFactorsFactoryUE4Module_1ac697d536a09d235c2d001ff038930457)`()` <a id="classFNansFactorsFactoryUE4Module_1ac697d536a09d235c2d001ff038930457"></a>

IModuleInterface implementation

#### `public virtual void `[`ShutdownModule`](#classFNansFactorsFactoryUE4Module_1abbbd4accea0843010d6a5ba3683889f2)`()` <a id="classFNansFactorsFactoryUE4Module_1abbbd4accea0843010d6a5ba3683889f2"></a>

# class `FNFactorAttributeCustomization` <a id="classFNFactorAttributeCustomization"></a>

```
class FNFactorAttributeCustomization
  : public IPropertyTypeCustomization
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`CustomizeHeader`](#classFNFactorAttributeCustomization_1a92d0211294a919375b2ae86294936467)`(TSharedRef< IPropertyHandle > StructPropertyHandle,class FDetailWidgetRow & HeaderRow,IPropertyTypeCustomizationUtils & StructCustomizationUtils)` | IPropertyTypeCustomization interface
`public virtual void `[`CustomizeChildren`](#classFNFactorAttributeCustomization_1adeccb7de892b27ab665435a3d5c3ca60)`(TSharedRef< IPropertyHandle > StructPropertyHandle,class IDetailChildrenBuilder & StructBuilder,IPropertyTypeCustomizationUtils & StructCustomizationUtils)` | 
`protected void `[`OnAttributeSelected`](#classFNFactorAttributeCustomization_1ac8ff12f86a95a99a4a2b62db616c9c0c)`(TSharedPtr< FName > Selection,ESelectInfo::Type SelectInfo)` | 

## Members

#### `public virtual void `[`CustomizeHeader`](#classFNFactorAttributeCustomization_1a92d0211294a919375b2ae86294936467)`(TSharedRef< IPropertyHandle > StructPropertyHandle,class FDetailWidgetRow & HeaderRow,IPropertyTypeCustomizationUtils & StructCustomizationUtils)` <a id="classFNFactorAttributeCustomization_1a92d0211294a919375b2ae86294936467"></a>

IPropertyTypeCustomization interface

#### `public virtual void `[`CustomizeChildren`](#classFNFactorAttributeCustomization_1adeccb7de892b27ab665435a3d5c3ca60)`(TSharedRef< IPropertyHandle > StructPropertyHandle,class IDetailChildrenBuilder & StructBuilder,IPropertyTypeCustomizationUtils & StructCustomizationUtils)` <a id="classFNFactorAttributeCustomization_1adeccb7de892b27ab665435a3d5c3ca60"></a>

#### `protected void `[`OnAttributeSelected`](#classFNFactorAttributeCustomization_1ac8ff12f86a95a99a4a2b62db616c9c0c)`(TSharedPtr< FName > Selection,ESelectInfo::Type SelectInfo)` <a id="classFNFactorAttributeCustomization_1ac8ff12f86a95a99a4a2b62db616c9c0c"></a>

# class `FNFactorSettingsPinFactory` <a id="classFNFactorSettingsPinFactory"></a>

```
class FNFactorSettingsPinFactory
  : public FGraphPanelPinFactory
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `INFactorsFactoryGameInstance` <a id="classINFactorsFactoryGameInstance"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`UFUNCTION`](#classINFactorsFactoryGameInstance_1a19952e47bedbb4723a23450e33f4a032)`(BlueprintCallable,BlueprintNativeEvent,meta,Category) const` | A blueprint overridable fn to get the Actual [UNFactorsFactoryClientAdapter](#classUNFactorsFactoryClientAdapter)

## Members

#### `public  `[`UFUNCTION`](#classINFactorsFactoryGameInstance_1a19952e47bedbb4723a23450e33f4a032)`(BlueprintCallable,BlueprintNativeEvent,meta,Category) const` <a id="classINFactorsFactoryGameInstance_1a19952e47bedbb4723a23450e33f4a032"></a>

A blueprint overridable fn to get the Actual [UNFactorsFactoryClientAdapter](#classUNFactorsFactoryClientAdapter)

# class `NAddOperator` <a id="classNAddOperator"></a>

```
class NAddOperator
  : public NFactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNAddOperator_1a5de4bacf334d15d62cc758944938dead)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNAddOperator_1a6b726fdb2141b38c9fc3be2cc899e1bc)`()` | 
`public inline virtual const FName `[`GetName`](#classNAddOperator_1a53a8a7c8fb4e8f3f1787d933a05a8c4d)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNAddOperator_1a5de4bacf334d15d62cc758944938dead)`(float Lh,float Rh)` <a id="classNAddOperator_1a5de4bacf334d15d62cc758944938dead"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNAddOperator_1a6b726fdb2141b38c9fc3be2cc899e1bc)`()` <a id="classNAddOperator_1a6b726fdb2141b38c9fc3be2cc899e1bc"></a>

#### `public inline virtual const FName `[`GetName`](#classNAddOperator_1a53a8a7c8fb4e8f3f1787d933a05a8c4d)`()` <a id="classNAddOperator_1a53a8a7c8fb4e8f3f1787d933a05a8c4d"></a>

# class `NansFactorsFactoryCore` <a id="classNansFactorsFactoryCore"></a>

```
class NansFactorsFactoryCore
  : public ModuleRules
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NansFactorsFactoryCore`](#classNansFactorsFactoryCore_1ad1a8a46a6da600f7cea3282f328b3f48)`(ReadOnlyTargetRules Target)` | 

## Members

#### `public inline  `[`NansFactorsFactoryCore`](#classNansFactorsFactoryCore_1ad1a8a46a6da600f7cea3282f328b3f48)`(ReadOnlyTargetRules Target)` <a id="classNansFactorsFactoryCore_1ad1a8a46a6da600f7cea3282f328b3f48"></a>

# class `NansFactorsFactoryUE4` <a id="classNansFactorsFactoryUE4"></a>

```
class NansFactorsFactoryUE4
  : public ModuleRules
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NansFactorsFactoryUE4`](#classNansFactorsFactoryUE4_1a36b5cb9753eef7c9f78f9f4c1f80ee3c)`(ReadOnlyTargetRules Target)` | 

## Members

#### `public inline  `[`NansFactorsFactoryUE4`](#classNansFactorsFactoryUE4_1a36b5cb9753eef7c9f78f9f4c1f80ee3c)`(ReadOnlyTargetRules Target)` <a id="classNansFactorsFactoryUE4_1a36b5cb9753eef7c9f78f9f4c1f80ee3c"></a>

# class `NCleanerOperator` <a id="classNCleanerOperator"></a>

```
class NCleanerOperator
  : public NResetOperatorBase
  : public NFactorOperatorWithFactorInterface
```  

This operator is raw! It removes every previous operator set in the factor's units queue. For the [Compute()](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6) method, it returns the value set at the Rh parameter (means that the factor Unit value associated replace every previous value).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual const FName `[`GetName`](#classNCleanerOperator_1a1acba394dd146e0854c07b8a7cc87464)`()` | 
`public virtual float `[`Compute`](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNCleanerOperator_1a7e4a297e0963fe95427310eec21cebae)`()` | 
`public virtual void `[`SetFactor`](#classNCleanerOperator_1a29062bd5e5562ba19e72267b9558929e)`(`[`NFactorInterface`](#classNFactorInterface)` * Factor)` | 
`public virtual void `[`SetKeyInFactor`](#classNCleanerOperator_1a74addade5011c190bd303719baac27aa)`(uint32 Key)` | 
`protected `[`NFactorInterface`](#classNFactorInterface)` * `[`MyFactor`](#classNCleanerOperator_1ad9ba044ba7b75bdc0a41a5814cb8fe1b) | 
`protected uint32 `[`KeyInFactor`](#classNCleanerOperator_1af8cc3d1f239bed565352263d6c9c8e5a) | 
`protected int32 `[`FactorUnitsNumber`](#classNCleanerOperator_1a61ae3070b503a1029f14ef7fb6e906cd) | 
`protected virtual bool `[`IsShouldClean`](#classNCleanerOperator_1ad083350719def073dfd321996a5bade5)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit) const` | 
`protected virtual float `[`Clean`](#classNCleanerOperator_1a7094e3e3b05f8aec60dacfcb4a1e0103)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit,float Lh)` | 

## Members

#### `public inline virtual const FName `[`GetName`](#classNCleanerOperator_1a1acba394dd146e0854c07b8a7cc87464)`()` <a id="classNCleanerOperator_1a1acba394dd146e0854c07b8a7cc87464"></a>

#### `public virtual float `[`Compute`](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6)`(float Lh,float Rh)` <a id="classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNCleanerOperator_1a7e4a297e0963fe95427310eec21cebae)`()` <a id="classNCleanerOperator_1a7e4a297e0963fe95427310eec21cebae"></a>

#### `public virtual void `[`SetFactor`](#classNCleanerOperator_1a29062bd5e5562ba19e72267b9558929e)`(`[`NFactorInterface`](#classNFactorInterface)` * Factor)` <a id="classNCleanerOperator_1a29062bd5e5562ba19e72267b9558929e"></a>

#### `public virtual void `[`SetKeyInFactor`](#classNCleanerOperator_1a74addade5011c190bd303719baac27aa)`(uint32 Key)` <a id="classNCleanerOperator_1a74addade5011c190bd303719baac27aa"></a>

#### `protected `[`NFactorInterface`](#classNFactorInterface)` * `[`MyFactor`](#classNCleanerOperator_1ad9ba044ba7b75bdc0a41a5814cb8fe1b) <a id="classNCleanerOperator_1ad9ba044ba7b75bdc0a41a5814cb8fe1b"></a>

#### `protected uint32 `[`KeyInFactor`](#classNCleanerOperator_1af8cc3d1f239bed565352263d6c9c8e5a) <a id="classNCleanerOperator_1af8cc3d1f239bed565352263d6c9c8e5a"></a>

#### `protected int32 `[`FactorUnitsNumber`](#classNCleanerOperator_1a61ae3070b503a1029f14ef7fb6e906cd) <a id="classNCleanerOperator_1a61ae3070b503a1029f14ef7fb6e906cd"></a>

#### `protected virtual bool `[`IsShouldClean`](#classNCleanerOperator_1ad083350719def073dfd321996a5bade5)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit) const` <a id="classNCleanerOperator_1ad083350719def073dfd321996a5bade5"></a>

#### `protected virtual float `[`Clean`](#classNCleanerOperator_1a7094e3e3b05f8aec60dacfcb4a1e0103)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit,float Lh)` <a id="classNCleanerOperator_1a7094e3e3b05f8aec60dacfcb4a1e0103"></a>

# class `NDividerOperator` <a id="classNDividerOperator"></a>

```
class NDividerOperator
  : public NFactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNDividerOperator_1aba31fb472867515a6a554ea528aee149)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNDividerOperator_1aa52f68ab08be9709095f8b75744fd5e4)`()` | 
`public inline virtual const FName `[`GetName`](#classNDividerOperator_1a22f6ea3308e67ae0c65d97f90f6dd414)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNDividerOperator_1aba31fb472867515a6a554ea528aee149)`(float Lh,float Rh)` <a id="classNDividerOperator_1aba31fb472867515a6a554ea528aee149"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNDividerOperator_1aa52f68ab08be9709095f8b75744fd5e4)`()` <a id="classNDividerOperator_1aa52f68ab08be9709095f8b75744fd5e4"></a>

#### `public inline virtual const FName `[`GetName`](#classNDividerOperator_1a22f6ea3308e67ae0c65d97f90f6dd414)`()` <a id="classNDividerOperator_1a22f6ea3308e67ae0c65d97f90f6dd414"></a>

# class `NFactor` <a id="classNFactor"></a>

```
class NFactor
  : public NFactorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NFactor`](#classNFactor_1a8ff702dcf5312530829e533c7e76efe1)`(FName _Name,TSharedPtr< NTimelineInterface > _Timeline)` | 
`public void `[`OnTimelineEventExpired`](#classNFactor_1acf6e44345a7ae229012a4eaa714e7488)`(TSharedPtr< NEventInterface > Event,const float & ExpiredTime,const int32 & Index)` | 
`public virtual  `[`~NFactor`](#classNFactor_1ad236413a6b0e2169d13e8910d1cba2e3)`()` | 
`public virtual void `[`Clear`](#classNFactor_1a4eec7590f7b5aa6a0e0a1351c4c2b0ad)`()` | 
`public virtual void `[`SetName`](#classNFactor_1a94cdca997de0e32331dd2b7ff504cdb1)`(FName _Name)` | 
`public virtual FName `[`GetName`](#classNFactor_1aad1ee98c8f37d17677126dd987178098)`() const` | 
`public virtual TSharedPtr< NTimelineInterface > `[`GetTimeline`](#classNFactor_1a258339f2bbf428006b90747da0ac7767)`() const` | 
`public virtual float `[`GetTime`](#classNFactor_1a65760fa5995f54bfd67527d136928a34)`() const` | 
`public virtual TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classNFactor_1a06b0541872396fd135a29c27bca69cbb)`(uint32 Key) const` | 
`public virtual int32 `[`AddFactorUnit`](#classNFactor_1ae0a1727389b62538d79052a78ba6b23b)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` | 
`public virtual bool `[`HasStateFlag`](#classNFactor_1ad32258ae8f95fae47c21a089b5c38344)`(FString Flag) const` | 
`public virtual bool `[`GetStateFlag`](#classNFactor_1aee02d9f87783b98796abb4d3044fb179)`(FString Flag) const` | 
`public virtual void `[`SetStateFlag`](#classNFactor_1ac780703e09cc012efb42fc2b776cf249)`(FString Flag,bool Value)` | 
`public virtual void `[`RemoveStateFlag`](#classNFactor_1a4677b2d80dc31e4f702749380c892b6d)`(FString Flag)` | 
`public virtual TArray< TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > > `[`GetFactors`](#classNFactor_1a883f26734c9356e2dfd637ea7db7ee44)`() const` | 
`public virtual void `[`SupplyStateWithCurrentData`](#classNFactor_1a9841dad0ab989f48cd659292b0d81d01)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` | 
`public virtual void `[`Debug`](#classNFactor_1a66dedee6a114423b83af232f4a491923)`(bool _bDebug)` | 
`public virtual void `[`AddFlag`](#classNFactor_1af1a0a37a6512b04fcb0ac2ed3e387e87)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` | 
`public virtual bool `[`HasFlag`](#classNFactor_1a5de5108d06f49eaf0b32b48aac1f0f0b)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag) const` | 
`public virtual void `[`RemoveFlag`](#classNFactor_1a07d856c96c4106e626c3bb3a7c6017c5)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` | 
`protected bool `[`bDebug`](#classNFactor_1af3f3aa1a0a8de9d0ac9b7a1dbbabe007) | 
`protected TMap< FString, bool > `[`IterationFlags`](#classNFactor_1ad99643576e9929158fb9ac9df7caef4d) | 
`protected TArray< `[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` > `[`OwnFlags`](#classNFactor_1aed2b9181e841461726af766f93f7aef1) | 
`protected TSharedPtr< NTimelineInterface > `[`Timeline`](#classNFactor_1ad92f86775473a330e973a3a60fc6ae22) | 
`protected TArray< TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > > `[`Factors`](#classNFactor_1ab217aeb59d451d1b23256e1753fafcd1) | 
`protected FName `[`Name`](#classNFactor_1a44e3980574bed89aaf6add01c35ffcde) | 
`protected void `[`AddFactorsToState`](#classNFactor_1adc71be7e3ab9860b664bc3cb2c4d20d2)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` | 
`protected void `[`OnStopperStart`](#classNFactor_1a0ea6d3b05889b5299057b6430e629749)`(NEventInterface * Event,const float & StartTime)` | This is use as a delegate attached to a NEventInterface::OnStart of the FactorUnit's event when its FactorOperator is an implementation of [NFactorOperatorStopperInterface](#classNFactorOperatorStopperInterface).

## Members

#### `public  `[`NFactor`](#classNFactor_1a8ff702dcf5312530829e533c7e76efe1)`(FName _Name,TSharedPtr< NTimelineInterface > _Timeline)` <a id="classNFactor_1a8ff702dcf5312530829e533c7e76efe1"></a>

#### `public void `[`OnTimelineEventExpired`](#classNFactor_1acf6e44345a7ae229012a4eaa714e7488)`(TSharedPtr< NEventInterface > Event,const float & ExpiredTime,const int32 & Index)` <a id="classNFactor_1acf6e44345a7ae229012a4eaa714e7488"></a>

#### `public virtual  `[`~NFactor`](#classNFactor_1ad236413a6b0e2169d13e8910d1cba2e3)`()` <a id="classNFactor_1ad236413a6b0e2169d13e8910d1cba2e3"></a>

#### `public virtual void `[`Clear`](#classNFactor_1a4eec7590f7b5aa6a0e0a1351c4c2b0ad)`()` <a id="classNFactor_1a4eec7590f7b5aa6a0e0a1351c4c2b0ad"></a>

#### `public virtual void `[`SetName`](#classNFactor_1a94cdca997de0e32331dd2b7ff504cdb1)`(FName _Name)` <a id="classNFactor_1a94cdca997de0e32331dd2b7ff504cdb1"></a>

#### `public virtual FName `[`GetName`](#classNFactor_1aad1ee98c8f37d17677126dd987178098)`() const` <a id="classNFactor_1aad1ee98c8f37d17677126dd987178098"></a>

#### `public virtual TSharedPtr< NTimelineInterface > `[`GetTimeline`](#classNFactor_1a258339f2bbf428006b90747da0ac7767)`() const` <a id="classNFactor_1a258339f2bbf428006b90747da0ac7767"></a>

#### `public virtual float `[`GetTime`](#classNFactor_1a65760fa5995f54bfd67527d136928a34)`() const` <a id="classNFactor_1a65760fa5995f54bfd67527d136928a34"></a>

#### `public virtual TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classNFactor_1a06b0541872396fd135a29c27bca69cbb)`(uint32 Key) const` <a id="classNFactor_1a06b0541872396fd135a29c27bca69cbb"></a>

#### `public virtual int32 `[`AddFactorUnit`](#classNFactor_1ae0a1727389b62538d79052a78ba6b23b)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` <a id="classNFactor_1ae0a1727389b62538d79052a78ba6b23b"></a>

#### `public virtual bool `[`HasStateFlag`](#classNFactor_1ad32258ae8f95fae47c21a089b5c38344)`(FString Flag) const` <a id="classNFactor_1ad32258ae8f95fae47c21a089b5c38344"></a>

#### `public virtual bool `[`GetStateFlag`](#classNFactor_1aee02d9f87783b98796abb4d3044fb179)`(FString Flag) const` <a id="classNFactor_1aee02d9f87783b98796abb4d3044fb179"></a>

#### `public virtual void `[`SetStateFlag`](#classNFactor_1ac780703e09cc012efb42fc2b776cf249)`(FString Flag,bool Value)` <a id="classNFactor_1ac780703e09cc012efb42fc2b776cf249"></a>

#### `public virtual void `[`RemoveStateFlag`](#classNFactor_1a4677b2d80dc31e4f702749380c892b6d)`(FString Flag)` <a id="classNFactor_1a4677b2d80dc31e4f702749380c892b6d"></a>

#### `public virtual TArray< TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > > `[`GetFactors`](#classNFactor_1a883f26734c9356e2dfd637ea7db7ee44)`() const` <a id="classNFactor_1a883f26734c9356e2dfd637ea7db7ee44"></a>

#### `public virtual void `[`SupplyStateWithCurrentData`](#classNFactor_1a9841dad0ab989f48cd659292b0d81d01)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` <a id="classNFactor_1a9841dad0ab989f48cd659292b0d81d01"></a>

#### `public virtual void `[`Debug`](#classNFactor_1a66dedee6a114423b83af232f4a491923)`(bool _bDebug)` <a id="classNFactor_1a66dedee6a114423b83af232f4a491923"></a>

#### `public virtual void `[`AddFlag`](#classNFactor_1af1a0a37a6512b04fcb0ac2ed3e387e87)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` <a id="classNFactor_1af1a0a37a6512b04fcb0ac2ed3e387e87"></a>

#### `public virtual bool `[`HasFlag`](#classNFactor_1a5de5108d06f49eaf0b32b48aac1f0f0b)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag) const` <a id="classNFactor_1a5de5108d06f49eaf0b32b48aac1f0f0b"></a>

#### `public virtual void `[`RemoveFlag`](#classNFactor_1a07d856c96c4106e626c3bb3a7c6017c5)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` <a id="classNFactor_1a07d856c96c4106e626c3bb3a7c6017c5"></a>

#### `protected bool `[`bDebug`](#classNFactor_1af3f3aa1a0a8de9d0ac9b7a1dbbabe007) <a id="classNFactor_1af3f3aa1a0a8de9d0ac9b7a1dbbabe007"></a>

#### `protected TMap< FString, bool > `[`IterationFlags`](#classNFactor_1ad99643576e9929158fb9ac9df7caef4d) <a id="classNFactor_1ad99643576e9929158fb9ac9df7caef4d"></a>

#### `protected TArray< `[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` > `[`OwnFlags`](#classNFactor_1aed2b9181e841461726af766f93f7aef1) <a id="classNFactor_1aed2b9181e841461726af766f93f7aef1"></a>

#### `protected TSharedPtr< NTimelineInterface > `[`Timeline`](#classNFactor_1ad92f86775473a330e973a3a60fc6ae22) <a id="classNFactor_1ad92f86775473a330e973a3a60fc6ae22"></a>

#### `protected TArray< TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > > `[`Factors`](#classNFactor_1ab217aeb59d451d1b23256e1753fafcd1) <a id="classNFactor_1ab217aeb59d451d1b23256e1753fafcd1"></a>

#### `protected FName `[`Name`](#classNFactor_1a44e3980574bed89aaf6add01c35ffcde) <a id="classNFactor_1a44e3980574bed89aaf6add01c35ffcde"></a>

#### `protected void `[`AddFactorsToState`](#classNFactor_1adc71be7e3ab9860b664bc3cb2c4d20d2)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` <a id="classNFactor_1adc71be7e3ab9860b664bc3cb2c4d20d2"></a>

#### `protected void `[`OnStopperStart`](#classNFactor_1a0ea6d3b05889b5299057b6430e629749)`(NEventInterface * Event,const float & StartTime)` <a id="classNFactor_1a0ea6d3b05889b5299057b6430e629749"></a>

This is use as a delegate attached to a NEventInterface::OnStart of the FactorUnit's event when its FactorOperator is an implementation of [NFactorOperatorStopperInterface](#classNFactorOperatorStopperInterface).

# class `NFactorInterface` <a id="classNFactorInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`Clear`](#classNFactorInterface_1af024837961bc536b63bc464f3f894516)`()` | 
`public void `[`SetName`](#classNFactorInterface_1a00c8b14fc220156b3872acac8dc9206c)`(FName _Name)` | 
`public FName `[`GetName`](#classNFactorInterface_1aa6d806dfbde602a5bc1087490b98b086)`() const` | 
`public TSharedPtr< NTimelineInterface > `[`GetTimeline`](#classNFactorInterface_1a2cbbeae6a891e84976055369c4c89bc5)`() const` | 
`public float `[`GetTime`](#classNFactorInterface_1a5dffa6febdd15622467d18b054b1d7a1)`() const` | 
`public TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classNFactorInterface_1ac2ebf1708a85eb0ff0d6a358426004a8)`(uint32 Key) const` | 
`public TArray< TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > > `[`GetFactors`](#classNFactorInterface_1a51d80b31ba732d9476a709a3424aa7dd)`() const` | 
`public int32 `[`AddFactorUnit`](#classNFactorInterface_1a8f34e5a5468d9d7746612c9d9752ef61)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` | 
`public bool `[`HasStateFlag`](#classNFactorInterface_1a5e476f34c9cc8ee8441ff1620b401037)`(FString Flag) const` | 
`public bool `[`GetStateFlag`](#classNFactorInterface_1aac748f28ce1c1e6eb8f70b7d510d5269)`(FString Flag) const` | 
`public void `[`SetStateFlag`](#classNFactorInterface_1a22302bd97f493d9a47e8817cb2b5645c)`(FString Flag,bool Value)` | 
`public void `[`RemoveStateFlag`](#classNFactorInterface_1a637f374194a219f7ffef5251277578ee)`(FString Flag)` | 
`public void `[`AddFlag`](#classNFactorInterface_1a121f9a151f81e006bd0d281dc2fde1c6)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` | 
`public bool `[`HasFlag`](#classNFactorInterface_1adf709bd32e99c93024bc6aabb4b9f86d)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag) const` | 
`public void `[`RemoveFlag`](#classNFactorInterface_1a4aaac880d5593e64afe86a4490cd609b)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` | 
`public void `[`Debug`](#classNFactorInterface_1a9a0698b3d77202918d60a565c8962f56)`(bool _bDebug)` | 
`public void `[`SupplyStateWithCurrentData`](#classNFactorInterface_1a09b4ac44820dd2eb16f9f684753f0bb3)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` | 

## Members

#### `public void `[`Clear`](#classNFactorInterface_1af024837961bc536b63bc464f3f894516)`()` <a id="classNFactorInterface_1af024837961bc536b63bc464f3f894516"></a>

#### `public void `[`SetName`](#classNFactorInterface_1a00c8b14fc220156b3872acac8dc9206c)`(FName _Name)` <a id="classNFactorInterface_1a00c8b14fc220156b3872acac8dc9206c"></a>

#### `public FName `[`GetName`](#classNFactorInterface_1aa6d806dfbde602a5bc1087490b98b086)`() const` <a id="classNFactorInterface_1aa6d806dfbde602a5bc1087490b98b086"></a>

#### `public TSharedPtr< NTimelineInterface > `[`GetTimeline`](#classNFactorInterface_1a2cbbeae6a891e84976055369c4c89bc5)`() const` <a id="classNFactorInterface_1a2cbbeae6a891e84976055369c4c89bc5"></a>

#### `public float `[`GetTime`](#classNFactorInterface_1a5dffa6febdd15622467d18b054b1d7a1)`() const` <a id="classNFactorInterface_1a5dffa6febdd15622467d18b054b1d7a1"></a>

#### `public TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classNFactorInterface_1ac2ebf1708a85eb0ff0d6a358426004a8)`(uint32 Key) const` <a id="classNFactorInterface_1ac2ebf1708a85eb0ff0d6a358426004a8"></a>

#### `public TArray< TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > > `[`GetFactors`](#classNFactorInterface_1a51d80b31ba732d9476a709a3424aa7dd)`() const` <a id="classNFactorInterface_1a51d80b31ba732d9476a709a3424aa7dd"></a>

#### `public int32 `[`AddFactorUnit`](#classNFactorInterface_1a8f34e5a5468d9d7746612c9d9752ef61)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` <a id="classNFactorInterface_1a8f34e5a5468d9d7746612c9d9752ef61"></a>

#### `public bool `[`HasStateFlag`](#classNFactorInterface_1a5e476f34c9cc8ee8441ff1620b401037)`(FString Flag) const` <a id="classNFactorInterface_1a5e476f34c9cc8ee8441ff1620b401037"></a>

#### `public bool `[`GetStateFlag`](#classNFactorInterface_1aac748f28ce1c1e6eb8f70b7d510d5269)`(FString Flag) const` <a id="classNFactorInterface_1aac748f28ce1c1e6eb8f70b7d510d5269"></a>

#### `public void `[`SetStateFlag`](#classNFactorInterface_1a22302bd97f493d9a47e8817cb2b5645c)`(FString Flag,bool Value)` <a id="classNFactorInterface_1a22302bd97f493d9a47e8817cb2b5645c"></a>

#### `public void `[`RemoveStateFlag`](#classNFactorInterface_1a637f374194a219f7ffef5251277578ee)`(FString Flag)` <a id="classNFactorInterface_1a637f374194a219f7ffef5251277578ee"></a>

#### `public void `[`AddFlag`](#classNFactorInterface_1a121f9a151f81e006bd0d281dc2fde1c6)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` <a id="classNFactorInterface_1a121f9a151f81e006bd0d281dc2fde1c6"></a>

#### `public bool `[`HasFlag`](#classNFactorInterface_1adf709bd32e99c93024bc6aabb4b9f86d)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag) const` <a id="classNFactorInterface_1adf709bd32e99c93024bc6aabb4b9f86d"></a>

#### `public void `[`RemoveFlag`](#classNFactorInterface_1a4aaac880d5593e64afe86a4490cd609b)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` <a id="classNFactorInterface_1a4aaac880d5593e64afe86a4490cd609b"></a>

#### `public void `[`Debug`](#classNFactorInterface_1a9a0698b3d77202918d60a565c8962f56)`(bool _bDebug)` <a id="classNFactorInterface_1a9a0698b3d77202918d60a565c8962f56"></a>

#### `public void `[`SupplyStateWithCurrentData`](#classNFactorInterface_1a09b4ac44820dd2eb16f9f684753f0bb3)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` <a id="classNFactorInterface_1a09b4ac44820dd2eb16f9f684753f0bb3"></a>

# class `NFactorOperatorBreakerInterface` <a id="classNFactorOperatorBreakerInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`IsBreaking`](#classNFactorOperatorBreakerInterface_1a88d5dadc90a73e7441421612cc53410c)`()` | 

## Members

#### `public bool `[`IsBreaking`](#classNFactorOperatorBreakerInterface_1a88d5dadc90a73e7441421612cc53410c)`()` <a id="classNFactorOperatorBreakerInterface_1a88d5dadc90a73e7441421612cc53410c"></a>

# class `NFactorOperatorInterface` <a id="classNFactorOperatorInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`Compute`](#classNFactorOperatorInterface_1af9177c889e9dd45816885223c18519e0)`(float Lh,float Rh)` | 
`public TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNFactorOperatorInterface_1a96ebd0931b175e04dedf64188ebf846a)`()` | 
`public const FName `[`GetName`](#classNFactorOperatorInterface_1a31563b058466848c2cf1d9f299607aee)`()` | 

## Members

#### `public float `[`Compute`](#classNFactorOperatorInterface_1af9177c889e9dd45816885223c18519e0)`(float Lh,float Rh)` <a id="classNFactorOperatorInterface_1af9177c889e9dd45816885223c18519e0"></a>

#### `public TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNFactorOperatorInterface_1a96ebd0931b175e04dedf64188ebf846a)`()` <a id="classNFactorOperatorInterface_1a96ebd0931b175e04dedf64188ebf846a"></a>

#### `public const FName `[`GetName`](#classNFactorOperatorInterface_1a31563b058466848c2cf1d9f299607aee)`()` <a id="classNFactorOperatorInterface_1a31563b058466848c2cf1d9f299607aee"></a>

# class `NFactorOperatorPersistentInterface` <a id="classNFactorOperatorPersistentInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`Compute`](#classNFactorOperatorPersistentInterface_1ab36cff2e9cd5ee2dde33c99694866f5a)`(float Lh,float Rh,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > ActualUnit)` | 

## Members

#### `public float `[`Compute`](#classNFactorOperatorPersistentInterface_1ab36cff2e9cd5ee2dde33c99694866f5a)`(float Lh,float Rh,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > ActualUnit)` <a id="classNFactorOperatorPersistentInterface_1ab36cff2e9cd5ee2dde33c99694866f5a"></a>

# class `NFactorOperatorStopperInterface` <a id="classNFactorOperatorStopperInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `NFactorOperatorWithFactorInterface` <a id="classNFactorOperatorWithFactorInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`SetFactor`](#classNFactorOperatorWithFactorInterface_1ad923fa3872e1becfa9ee1b356d083207)`(`[`NFactorInterface`](#classNFactorInterface)` * Factor)` | 
`public void `[`SetKeyInFactor`](#classNFactorOperatorWithFactorInterface_1aa92b49b9f27cbc8dedff51d8a324214e)`(uint32 Key)` | 

## Members

#### `public void `[`SetFactor`](#classNFactorOperatorWithFactorInterface_1ad923fa3872e1becfa9ee1b356d083207)`(`[`NFactorInterface`](#classNFactorInterface)` * Factor)` <a id="classNFactorOperatorWithFactorInterface_1ad923fa3872e1becfa9ee1b356d083207"></a>

#### `public void `[`SetKeyInFactor`](#classNFactorOperatorWithFactorInterface_1aa92b49b9f27cbc8dedff51d8a324214e)`(uint32 Key)` <a id="classNFactorOperatorWithFactorInterface_1aa92b49b9f27cbc8dedff51d8a324214e"></a>

# class `NFactorsFactoryClient` <a id="classNFactorsFactoryClient"></a>

```
class NFactorsFactoryClient
  : public NFactorsFactoryClientInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual  `[`~NFactorsFactoryClient`](#classNFactorsFactoryClient_1a1bf0a0ad559e6e449ebc9eb293d8cb9a)`()` | 
`public virtual void `[`CreateFactor`](#classNFactorsFactoryClient_1adfa39c429d14d5e7d9b311719baf1bb1)`(FName FactorName,TSharedPtr< NTimelineInterface > Timeline)` | 
`public virtual void `[`CreateFactor`](#classNFactorsFactoryClient_1a563903bf013bb4777731740b3e301db8)`(TArray< FName > FactorNames,TSharedPtr< NTimelineInterface > Timeline)` | 
`public virtual void `[`AddFactor`](#classNFactorsFactoryClient_1a2c8546a5be73e3f654df7e14a25c60fb)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public virtual void `[`RemoveFactor`](#classNFactorsFactoryClient_1aa549b5112428bb65d7940857f5507c9e)`(FName FactorName)` | 
`public virtual void `[`GetState`](#classNFactorsFactoryClient_1a5400825c037467168b8716d7c0832049)`(FName FactorName,`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` | 
`public virtual TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classNFactorsFactoryClient_1aea8eac9ec51a24acf7dd92d5bd68ad40)`(TArray< FName > FactorNames,`[`NFactorStateInterface`](#classNFactorStateInterface)` * StateTemplate)` | 
`public virtual int32 `[`AddFactorUnit`](#classNFactorsFactoryClient_1af11ce2475f872f980cab8a9801c079ae)`(FName FactorName,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` | 
`public virtual TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classNFactorsFactoryClient_1a74c18d413f1a55ca3fa5e5b0b2d43d48)`(FName FactorName,int32 Key)` | 
`public virtual void `[`SetDebug`](#classNFactorsFactoryClient_1a9f7d7733c07a31d33b62d40ea7601d71)`(const TArray< FName > FactorNames,bool bDebug)` | 
`protected TMap< FName, TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`FactorsList`](#classNFactorsFactoryClient_1aa87323e3850e42fcd9cba23497c669c1) | 

## Members

#### `public inline virtual  `[`~NFactorsFactoryClient`](#classNFactorsFactoryClient_1a1bf0a0ad559e6e449ebc9eb293d8cb9a)`()` <a id="classNFactorsFactoryClient_1a1bf0a0ad559e6e449ebc9eb293d8cb9a"></a>

#### `public virtual void `[`CreateFactor`](#classNFactorsFactoryClient_1adfa39c429d14d5e7d9b311719baf1bb1)`(FName FactorName,TSharedPtr< NTimelineInterface > Timeline)` <a id="classNFactorsFactoryClient_1adfa39c429d14d5e7d9b311719baf1bb1"></a>

#### `public virtual void `[`CreateFactor`](#classNFactorsFactoryClient_1a563903bf013bb4777731740b3e301db8)`(TArray< FName > FactorNames,TSharedPtr< NTimelineInterface > Timeline)` <a id="classNFactorsFactoryClient_1a563903bf013bb4777731740b3e301db8"></a>

#### `public virtual void `[`AddFactor`](#classNFactorsFactoryClient_1a2c8546a5be73e3f654df7e14a25c60fb)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNFactorsFactoryClient_1a2c8546a5be73e3f654df7e14a25c60fb"></a>

#### `public virtual void `[`RemoveFactor`](#classNFactorsFactoryClient_1aa549b5112428bb65d7940857f5507c9e)`(FName FactorName)` <a id="classNFactorsFactoryClient_1aa549b5112428bb65d7940857f5507c9e"></a>

#### `public virtual void `[`GetState`](#classNFactorsFactoryClient_1a5400825c037467168b8716d7c0832049)`(FName FactorName,`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` <a id="classNFactorsFactoryClient_1a5400825c037467168b8716d7c0832049"></a>

#### `public virtual TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classNFactorsFactoryClient_1aea8eac9ec51a24acf7dd92d5bd68ad40)`(TArray< FName > FactorNames,`[`NFactorStateInterface`](#classNFactorStateInterface)` * StateTemplate)` <a id="classNFactorsFactoryClient_1aea8eac9ec51a24acf7dd92d5bd68ad40"></a>

#### `public virtual int32 `[`AddFactorUnit`](#classNFactorsFactoryClient_1af11ce2475f872f980cab8a9801c079ae)`(FName FactorName,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` <a id="classNFactorsFactoryClient_1af11ce2475f872f980cab8a9801c079ae"></a>

#### `public virtual TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classNFactorsFactoryClient_1a74c18d413f1a55ca3fa5e5b0b2d43d48)`(FName FactorName,int32 Key)` <a id="classNFactorsFactoryClient_1a74c18d413f1a55ca3fa5e5b0b2d43d48"></a>

#### `public virtual void `[`SetDebug`](#classNFactorsFactoryClient_1a9f7d7733c07a31d33b62d40ea7601d71)`(const TArray< FName > FactorNames,bool bDebug)` <a id="classNFactorsFactoryClient_1a9f7d7733c07a31d33b62d40ea7601d71"></a>

#### `protected TMap< FName, TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`FactorsList`](#classNFactorsFactoryClient_1aa87323e3850e42fcd9cba23497c669c1) <a id="classNFactorsFactoryClient_1aa87323e3850e42fcd9cba23497c669c1"></a>

# class `NFactorsFactoryClientInterface` <a id="classNFactorsFactoryClientInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`CreateFactor`](#classNFactorsFactoryClientInterface_1a0920cc1f517abfee8f0377c119a1abdd)`(FName FactorName,TSharedPtr< NTimelineInterface > Timeline)` | 
`public void `[`CreateFactor`](#classNFactorsFactoryClientInterface_1a64a215decfea0ad7b55cf2ce8f5d3f95)`(TArray< FName > FactorNames,TSharedPtr< NTimelineInterface > Timeline)` | 
`public void `[`AddFactor`](#classNFactorsFactoryClientInterface_1a626484da7ef6c89f92fe3f90f832113b)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public void `[`RemoveFactor`](#classNFactorsFactoryClientInterface_1ac12dc0bfcb4f4f0d49364aeb87e9f725)`(FName FactorName)` | 
`public void `[`GetState`](#classNFactorsFactoryClientInterface_1a7b8f7a3d6543dc917190221056b3c9a0)`(FName FactorName,`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` | 
`public TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classNFactorsFactoryClientInterface_1a0886aef695c58dd82a552cb3a6b67e82)`(TArray< FName > FactorNames,`[`NFactorStateInterface`](#classNFactorStateInterface)` * StateTemplate)` | 
`public int32 `[`AddFactorUnit`](#classNFactorsFactoryClientInterface_1a1552ab1748e1a3f74d5eb5182dd87821)`(FName FactorName,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` | 
`public TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classNFactorsFactoryClientInterface_1a75c66f4fbdd8c71a25eee53cdded95d7)`(FName FactorName,int32 Key)` | 
`public void `[`SetDebug`](#classNFactorsFactoryClientInterface_1aa2c4c5102105c999aecc28ca1c16228a)`(const TArray< FName > FactorNames,bool bDebug)` | 

## Members

#### `public void `[`CreateFactor`](#classNFactorsFactoryClientInterface_1a0920cc1f517abfee8f0377c119a1abdd)`(FName FactorName,TSharedPtr< NTimelineInterface > Timeline)` <a id="classNFactorsFactoryClientInterface_1a0920cc1f517abfee8f0377c119a1abdd"></a>

#### `public void `[`CreateFactor`](#classNFactorsFactoryClientInterface_1a64a215decfea0ad7b55cf2ce8f5d3f95)`(TArray< FName > FactorNames,TSharedPtr< NTimelineInterface > Timeline)` <a id="classNFactorsFactoryClientInterface_1a64a215decfea0ad7b55cf2ce8f5d3f95"></a>

#### `public void `[`AddFactor`](#classNFactorsFactoryClientInterface_1a626484da7ef6c89f92fe3f90f832113b)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNFactorsFactoryClientInterface_1a626484da7ef6c89f92fe3f90f832113b"></a>

#### `public void `[`RemoveFactor`](#classNFactorsFactoryClientInterface_1ac12dc0bfcb4f4f0d49364aeb87e9f725)`(FName FactorName)` <a id="classNFactorsFactoryClientInterface_1ac12dc0bfcb4f4f0d49364aeb87e9f725"></a>

#### `public void `[`GetState`](#classNFactorsFactoryClientInterface_1a7b8f7a3d6543dc917190221056b3c9a0)`(FName FactorName,`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` <a id="classNFactorsFactoryClientInterface_1a7b8f7a3d6543dc917190221056b3c9a0"></a>

#### `public TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classNFactorsFactoryClientInterface_1a0886aef695c58dd82a552cb3a6b67e82)`(TArray< FName > FactorNames,`[`NFactorStateInterface`](#classNFactorStateInterface)` * StateTemplate)` <a id="classNFactorsFactoryClientInterface_1a0886aef695c58dd82a552cb3a6b67e82"></a>

#### `public int32 `[`AddFactorUnit`](#classNFactorsFactoryClientInterface_1a1552ab1748e1a3f74d5eb5182dd87821)`(FName FactorName,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` <a id="classNFactorsFactoryClientInterface_1a1552ab1748e1a3f74d5eb5182dd87821"></a>

#### `public TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classNFactorsFactoryClientInterface_1a75c66f4fbdd8c71a25eee53cdded95d7)`(FName FactorName,int32 Key)` <a id="classNFactorsFactoryClientInterface_1a75c66f4fbdd8c71a25eee53cdded95d7"></a>

#### `public void `[`SetDebug`](#classNFactorsFactoryClientInterface_1aa2c4c5102105c999aecc28ca1c16228a)`(const TArray< FName > FactorNames,bool bDebug)` <a id="classNFactorsFactoryClientInterface_1aa2c4c5102105c999aecc28ca1c16228a"></a>

# class `NFactorState` <a id="classNFactorState"></a>

```
class NFactorState
  : public NFactorStateInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`bDebug`](#classNFactorState_1ac1565797048a0259d71bad1cb4995604) | 
`public inline virtual  `[`~NFactorState`](#classNFactorState_1a11c5c3b35724ddba3db601ff3d2574e9)`()` | 
`public inline  `[`NFactorState`](#classNFactorState_1a64392bc5f25117da90683127f38b3d61)`()` | 
`public virtual int32 `[`AddFactorUnit`](#classNFactorState_1a15d4e746901cee60f0152e6e227c953a)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` | 
`public virtual float `[`GetTime`](#classNFactorState_1aa4ab3543a7bb44e9a9763f544366fa84)`() const` | 
`public virtual void `[`SetTime`](#classNFactorState_1abc83a57624e48afdd5223cb3b1aefe52)`(float _Time)` | 
`public virtual float `[`Compute`](#classNFactorState_1a95f00f47091e4c1ab6d1e4cba3421e5a)`()` | 
`public virtual void `[`Clear`](#classNFactorState_1a771c1b03cf365dcbab563f5afcd6a18c)`()` | 
`public virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`Clone`](#classNFactorState_1a4b10802cf058fac577ba15f53ddaeae2)`()` | 
`public virtual void `[`Debug`](#classNFactorState_1a30fba76e979ccc5f32482e512f31e805)`(bool _bDebug)` | 
`public virtual const TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`GetOperators`](#classNFactorState_1a16096dbc1357e7723fa7388b887d46cb)`() const` | 
`protected TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`Operators`](#classNFactorState_1a31de6655fee5eabd18207e137b7e34c0) | 

## Members

#### `public bool `[`bDebug`](#classNFactorState_1ac1565797048a0259d71bad1cb4995604) <a id="classNFactorState_1ac1565797048a0259d71bad1cb4995604"></a>

#### `public inline virtual  `[`~NFactorState`](#classNFactorState_1a11c5c3b35724ddba3db601ff3d2574e9)`()` <a id="classNFactorState_1a11c5c3b35724ddba3db601ff3d2574e9"></a>

#### `public inline  `[`NFactorState`](#classNFactorState_1a64392bc5f25117da90683127f38b3d61)`()` <a id="classNFactorState_1a64392bc5f25117da90683127f38b3d61"></a>

#### `public virtual int32 `[`AddFactorUnit`](#classNFactorState_1a15d4e746901cee60f0152e6e227c953a)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` <a id="classNFactorState_1a15d4e746901cee60f0152e6e227c953a"></a>

#### `public virtual float `[`GetTime`](#classNFactorState_1aa4ab3543a7bb44e9a9763f544366fa84)`() const` <a id="classNFactorState_1aa4ab3543a7bb44e9a9763f544366fa84"></a>

#### `public virtual void `[`SetTime`](#classNFactorState_1abc83a57624e48afdd5223cb3b1aefe52)`(float _Time)` <a id="classNFactorState_1abc83a57624e48afdd5223cb3b1aefe52"></a>

#### `public virtual float `[`Compute`](#classNFactorState_1a95f00f47091e4c1ab6d1e4cba3421e5a)`()` <a id="classNFactorState_1a95f00f47091e4c1ab6d1e4cba3421e5a"></a>

#### `public virtual void `[`Clear`](#classNFactorState_1a771c1b03cf365dcbab563f5afcd6a18c)`()` <a id="classNFactorState_1a771c1b03cf365dcbab563f5afcd6a18c"></a>

#### `public virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`Clone`](#classNFactorState_1a4b10802cf058fac577ba15f53ddaeae2)`()` <a id="classNFactorState_1a4b10802cf058fac577ba15f53ddaeae2"></a>

#### `public virtual void `[`Debug`](#classNFactorState_1a30fba76e979ccc5f32482e512f31e805)`(bool _bDebug)` <a id="classNFactorState_1a30fba76e979ccc5f32482e512f31e805"></a>

#### `public virtual const TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`GetOperators`](#classNFactorState_1a16096dbc1357e7723fa7388b887d46cb)`() const` <a id="classNFactorState_1a16096dbc1357e7723fa7388b887d46cb"></a>

#### `protected TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`Operators`](#classNFactorState_1a31de6655fee5eabd18207e137b7e34c0) <a id="classNFactorState_1a31de6655fee5eabd18207e137b7e34c0"></a>

# class `NFactorStateInterface` <a id="classNFactorStateInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int32 `[`AddFactorUnit`](#classNFactorStateInterface_1a6f2f63ad2dd29f5296646ea03b0ad949)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` | 
`public void `[`SetTime`](#classNFactorStateInterface_1a9b2deabbcd3cb647804979c63ac8874f)`(float _Time)` | 
`public float `[`GetTime`](#classNFactorStateInterface_1a0db01ef0d3940a9ff8aa49df01d9368a)`() const` | 
`public float `[`Compute`](#classNFactorStateInterface_1a612d26366bf252a9772d8edaa9deb1ee)`()` | 
`public void `[`Clear`](#classNFactorStateInterface_1abe39d7de9f313f485f93d81ccf926fc8)`()` | 
`public `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`Clone`](#classNFactorStateInterface_1a6a1adafbaf2963839d3c89c1ec459b0d)`()` | 
`public void `[`Debug`](#classNFactorStateInterface_1a0da2fc0ac04e1d121dece2c20b4a9df9)`(bool _bDebug)` | 
`public const TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`GetOperators`](#classNFactorStateInterface_1a69be6ed66d3ce8da4310169c24ba11f3)`() const` | 

## Members

#### `public int32 `[`AddFactorUnit`](#classNFactorStateInterface_1a6f2f63ad2dd29f5296646ea03b0ad949)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` <a id="classNFactorStateInterface_1a6f2f63ad2dd29f5296646ea03b0ad949"></a>

#### `public void `[`SetTime`](#classNFactorStateInterface_1a9b2deabbcd3cb647804979c63ac8874f)`(float _Time)` <a id="classNFactorStateInterface_1a9b2deabbcd3cb647804979c63ac8874f"></a>

#### `public float `[`GetTime`](#classNFactorStateInterface_1a0db01ef0d3940a9ff8aa49df01d9368a)`() const` <a id="classNFactorStateInterface_1a0db01ef0d3940a9ff8aa49df01d9368a"></a>

#### `public float `[`Compute`](#classNFactorStateInterface_1a612d26366bf252a9772d8edaa9deb1ee)`()` <a id="classNFactorStateInterface_1a612d26366bf252a9772d8edaa9deb1ee"></a>

#### `public void `[`Clear`](#classNFactorStateInterface_1abe39d7de9f313f485f93d81ccf926fc8)`()` <a id="classNFactorStateInterface_1abe39d7de9f313f485f93d81ccf926fc8"></a>

#### `public `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`Clone`](#classNFactorStateInterface_1a6a1adafbaf2963839d3c89c1ec459b0d)`()` <a id="classNFactorStateInterface_1a6a1adafbaf2963839d3c89c1ec459b0d"></a>

#### `public void `[`Debug`](#classNFactorStateInterface_1a0da2fc0ac04e1d121dece2c20b4a9df9)`(bool _bDebug)` <a id="classNFactorStateInterface_1a0da2fc0ac04e1d121dece2c20b4a9df9"></a>

#### `public const TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`GetOperators`](#classNFactorStateInterface_1a69be6ed66d3ce8da4310169c24ba11f3)`() const` <a id="classNFactorStateInterface_1a69be6ed66d3ce8da4310169c24ba11f3"></a>

# class `NFactorUnit` <a id="classNFactorUnit"></a>

```
class NFactorUnit
  : public NFactorUnitInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NFactorUnit`](#classNFactorUnit_1ae0878628b74493764a76f2a3cb11e2c7)`(float _FactorUnitValue,TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator,float _Duration,FName Reason,float _Delay,TSharedPtr< NEventInterface > _Event)` | 
`public  `[`NFactorUnit`](#classNFactorUnit_1a6ef07f52996d142d945ba72887d38331)`(float _FactorUnitValue,TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator,TSharedPtr< NEventInterface > _Event)` | 
`public virtual  `[`~NFactorUnit`](#classNFactorUnit_1a9342f38ff4ed498100d047bb36ed1c6b)`()` | 
`public virtual bool `[`IsActivated`](#classNFactorUnit_1a42b1bfceb8954494b7c6b934bb813d48)`() const` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classNFactorUnit_1a5f0789816a95eb7d556e4521808ba580)`() const` | 
`public virtual void `[`SetOperator`](#classNFactorUnit_1a1f39030872afde4d7cf26ff82f6764f0)`(TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator)` | 
`public virtual float `[`GetFactorUnitValue`](#classNFactorUnit_1a624220422a6bf79d08bd48da694f7dba)`() const` | 
`public virtual FName `[`GetReason`](#classNFactorUnit_1a99ea12a5ebda8e0bfa715b244e07673f)`() const` | 
`public virtual void `[`SetFactorUnitValue`](#classNFactorUnit_1afb92cfc6e060c603f76b0866af59b4d8)`(float _Value)` | 
`public virtual const FString `[`GetUID`](#classNFactorUnit_1a4ea14c7c9d56ddf6a9d67f62c644bebc)`() const` | 
`public virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classNFactorUnit_1a02eff08ce993e49cccd988d5ef132efe)`()` | 
`public virtual void `[`Activate`](#classNFactorUnit_1a07f052db4deb77dce4ced7b5c4c7a901)`(bool _bIsActivated)` | 
`protected TSharedPtr< NEventInterface > `[`Event`](#classNFactorUnit_1a49722915624b6e0a86fc8d8572a80891) | 
`protected bool `[`bIsActivated`](#classNFactorUnit_1ab9923883cce13ff910b06c958c8a9c43) | 
`protected float `[`FactorUnitValue`](#classNFactorUnit_1aca9c10ab53aa8ae78628fb9940f27cdf) | 
`protected TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`Operator`](#classNFactorUnit_1a17b670f04a054b2776523314073235e8) | 

## Members

#### `public  `[`NFactorUnit`](#classNFactorUnit_1ae0878628b74493764a76f2a3cb11e2c7)`(float _FactorUnitValue,TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator,float _Duration,FName Reason,float _Delay,TSharedPtr< NEventInterface > _Event)` <a id="classNFactorUnit_1ae0878628b74493764a76f2a3cb11e2c7"></a>

#### `public  `[`NFactorUnit`](#classNFactorUnit_1a6ef07f52996d142d945ba72887d38331)`(float _FactorUnitValue,TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator,TSharedPtr< NEventInterface > _Event)` <a id="classNFactorUnit_1a6ef07f52996d142d945ba72887d38331"></a>

#### `public virtual  `[`~NFactorUnit`](#classNFactorUnit_1a9342f38ff4ed498100d047bb36ed1c6b)`()` <a id="classNFactorUnit_1a9342f38ff4ed498100d047bb36ed1c6b"></a>

#### `public virtual bool `[`IsActivated`](#classNFactorUnit_1a42b1bfceb8954494b7c6b934bb813d48)`() const` <a id="classNFactorUnit_1a42b1bfceb8954494b7c6b934bb813d48"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classNFactorUnit_1a5f0789816a95eb7d556e4521808ba580)`() const` <a id="classNFactorUnit_1a5f0789816a95eb7d556e4521808ba580"></a>

#### `public virtual void `[`SetOperator`](#classNFactorUnit_1a1f39030872afde4d7cf26ff82f6764f0)`(TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator)` <a id="classNFactorUnit_1a1f39030872afde4d7cf26ff82f6764f0"></a>

#### `public virtual float `[`GetFactorUnitValue`](#classNFactorUnit_1a624220422a6bf79d08bd48da694f7dba)`() const` <a id="classNFactorUnit_1a624220422a6bf79d08bd48da694f7dba"></a>

#### `public virtual FName `[`GetReason`](#classNFactorUnit_1a99ea12a5ebda8e0bfa715b244e07673f)`() const` <a id="classNFactorUnit_1a99ea12a5ebda8e0bfa715b244e07673f"></a>

#### `public virtual void `[`SetFactorUnitValue`](#classNFactorUnit_1afb92cfc6e060c603f76b0866af59b4d8)`(float _Value)` <a id="classNFactorUnit_1afb92cfc6e060c603f76b0866af59b4d8"></a>

#### `public virtual const FString `[`GetUID`](#classNFactorUnit_1a4ea14c7c9d56ddf6a9d67f62c644bebc)`() const` <a id="classNFactorUnit_1a4ea14c7c9d56ddf6a9d67f62c644bebc"></a>

#### `public virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classNFactorUnit_1a02eff08ce993e49cccd988d5ef132efe)`()` <a id="classNFactorUnit_1a02eff08ce993e49cccd988d5ef132efe"></a>

#### `public virtual void `[`Activate`](#classNFactorUnit_1a07f052db4deb77dce4ced7b5c4c7a901)`(bool _bIsActivated)` <a id="classNFactorUnit_1a07f052db4deb77dce4ced7b5c4c7a901"></a>

#### `protected TSharedPtr< NEventInterface > `[`Event`](#classNFactorUnit_1a49722915624b6e0a86fc8d8572a80891) <a id="classNFactorUnit_1a49722915624b6e0a86fc8d8572a80891"></a>

#### `protected bool `[`bIsActivated`](#classNFactorUnit_1ab9923883cce13ff910b06c958c8a9c43) <a id="classNFactorUnit_1ab9923883cce13ff910b06c958c8a9c43"></a>

#### `protected float `[`FactorUnitValue`](#classNFactorUnit_1aca9c10ab53aa8ae78628fb9940f27cdf) <a id="classNFactorUnit_1aca9c10ab53aa8ae78628fb9940f27cdf"></a>

#### `protected TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`Operator`](#classNFactorUnit_1a17b670f04a054b2776523314073235e8) <a id="classNFactorUnit_1a17b670f04a054b2776523314073235e8"></a>

# class `NFactorUnitInterface` <a id="classNFactorUnitInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classNFactorUnitInterface_1a4c5a87bbc020b8e8e3f5a3557816b89b)`() const` | 
`public void `[`SetOperator`](#classNFactorUnitInterface_1a7818539d20dac8c6344bb0b388dbac2c)`(TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator)` | 
`public float `[`GetFactorUnitValue`](#classNFactorUnitInterface_1a0ebeec0d94d92fcd531f947ab9fffc96)`() const` | 
`public FName `[`GetReason`](#classNFactorUnitInterface_1ad3f53361e2b64401d0751e74a19516f3)`() const` | 
`public void `[`SetFactorUnitValue`](#classNFactorUnitInterface_1a1ca2efe862af56fdc56a86aff04253d3)`(float _Value)` | 
`public bool `[`IsActivated`](#classNFactorUnitInterface_1a587651b5d8ca573d39ecb68b79a738d9)`() const` | 
`public const FString `[`GetUID`](#classNFactorUnitInterface_1a7d8efaac45af07e09210589e4f55d0cd)`() const` | 
`public TSharedPtr< NEventInterface > `[`GetEvent`](#classNFactorUnitInterface_1aab0f6b86947f1c788a01cbd15894e00d)`()` | 
`public void `[`Activate`](#classNFactorUnitInterface_1a365d67a3a2b5bf3dba02298af92fef93)`(bool _bIsActivated)` | 

## Members

#### `public TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classNFactorUnitInterface_1a4c5a87bbc020b8e8e3f5a3557816b89b)`() const` <a id="classNFactorUnitInterface_1a4c5a87bbc020b8e8e3f5a3557816b89b"></a>

#### `public void `[`SetOperator`](#classNFactorUnitInterface_1a7818539d20dac8c6344bb0b388dbac2c)`(TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator)` <a id="classNFactorUnitInterface_1a7818539d20dac8c6344bb0b388dbac2c"></a>

#### `public float `[`GetFactorUnitValue`](#classNFactorUnitInterface_1a0ebeec0d94d92fcd531f947ab9fffc96)`() const` <a id="classNFactorUnitInterface_1a0ebeec0d94d92fcd531f947ab9fffc96"></a>

#### `public FName `[`GetReason`](#classNFactorUnitInterface_1ad3f53361e2b64401d0751e74a19516f3)`() const` <a id="classNFactorUnitInterface_1ad3f53361e2b64401d0751e74a19516f3"></a>

#### `public void `[`SetFactorUnitValue`](#classNFactorUnitInterface_1a1ca2efe862af56fdc56a86aff04253d3)`(float _Value)` <a id="classNFactorUnitInterface_1a1ca2efe862af56fdc56a86aff04253d3"></a>

#### `public bool `[`IsActivated`](#classNFactorUnitInterface_1a587651b5d8ca573d39ecb68b79a738d9)`() const` <a id="classNFactorUnitInterface_1a587651b5d8ca573d39ecb68b79a738d9"></a>

#### `public const FString `[`GetUID`](#classNFactorUnitInterface_1a7d8efaac45af07e09210589e4f55d0cd)`() const` <a id="classNFactorUnitInterface_1a7d8efaac45af07e09210589e4f55d0cd"></a>

#### `public TSharedPtr< NEventInterface > `[`GetEvent`](#classNFactorUnitInterface_1aab0f6b86947f1c788a01cbd15894e00d)`()` <a id="classNFactorUnitInterface_1aab0f6b86947f1c788a01cbd15894e00d"></a>

#### `public void `[`Activate`](#classNFactorUnitInterface_1a365d67a3a2b5bf3dba02298af92fef93)`(bool _bIsActivated)` <a id="classNFactorUnitInterface_1a365d67a3a2b5bf3dba02298af92fef93"></a>

# class `NIncreasersCleanerOperator` <a id="classNIncreasersCleanerOperator"></a>

```
class NIncreasersCleanerOperator
  : public NCleanerOperator
```  

This operator is raw! It removes every previous operator set in the factor's units queue. It cleans only factor's unit which implies factor amount increase. The Rh parameter of the [Compute()](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6) method determines the amount of FactorUnit removed (0 = all). For the [Compute()](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6) method it doesn't make any computation by returning the Lh parameter.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual bool `[`IsShouldClean`](#classNIncreasersCleanerOperator_1a7d45c66c9e6cc1530fdfa3cc652df1d3)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit) const` | 

## Members

#### `public virtual bool `[`IsShouldClean`](#classNIncreasersCleanerOperator_1a7d45c66c9e6cc1530fdfa3cc652df1d3)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit) const` <a id="classNIncreasersCleanerOperator_1a7d45c66c9e6cc1530fdfa3cc652df1d3"></a>

# class `NIncreasersCleanerPersistentOperator` <a id="classNIncreasersCleanerPersistentOperator"></a>

```
class NIncreasersCleanerPersistentOperator
  : public NIncreasersCleanerOperator
  : public NFactorOperatorPersistentInterface
```  

This operator is raw! It removes every previous operator set in the factor's units queue. It cleans only factor's unit which implies factor amount increase. The Rh parameter of the [Compute()](#classNIncreasersCleanerPersistentOperator_1af2f61cf4d96ea081ba35ee09dfa1bcf8) method determines the amount of FactorUnit removed (0 = all). For the [Compute()](#classNIncreasersCleanerPersistentOperator_1af2f61cf4d96ea081ba35ee09dfa1bcf8) method it doesn't make any computation by returning the Lh parameter. It removes also next Increasers set.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNIncreasersCleanerPersistentOperator_1af2f61cf4d96ea081ba35ee09dfa1bcf8)`(float Lh,float Rh,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > ActualUnit)` | 

## Members

#### `public virtual float `[`Compute`](#classNIncreasersCleanerPersistentOperator_1af2f61cf4d96ea081ba35ee09dfa1bcf8)`(float Lh,float Rh,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > ActualUnit)` <a id="classNIncreasersCleanerPersistentOperator_1af2f61cf4d96ea081ba35ee09dfa1bcf8"></a>

# class `NMultiplyOperator` <a id="classNMultiplyOperator"></a>

```
class NMultiplyOperator
  : public NFactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNMultiplyOperator_1a13ed17ab0b1d7f45afb34bbb869a24fb)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNMultiplyOperator_1acf0372081affa406cc136af55c02e77d)`()` | 
`public inline virtual const FName `[`GetName`](#classNMultiplyOperator_1a78841a13d056a1d79ca82d35db1f26d2)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNMultiplyOperator_1a13ed17ab0b1d7f45afb34bbb869a24fb)`(float Lh,float Rh)` <a id="classNMultiplyOperator_1a13ed17ab0b1d7f45afb34bbb869a24fb"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNMultiplyOperator_1acf0372081affa406cc136af55c02e77d)`()` <a id="classNMultiplyOperator_1acf0372081affa406cc136af55c02e77d"></a>

#### `public inline virtual const FName `[`GetName`](#classNMultiplyOperator_1a78841a13d056a1d79ca82d35db1f26d2)`()` <a id="classNMultiplyOperator_1a78841a13d056a1d79ca82d35db1f26d2"></a>

# class `NNullFactorUnit` <a id="classNNullFactorUnit"></a>

```
class NNullFactorUnit
  : public NFactorUnitInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NNullFactorUnit`](#classNNullFactorUnit_1abf274f92f6a2c0a41e1033d700d77a32)`()` | 
`public virtual  `[`~NNullFactorUnit`](#classNNullFactorUnit_1a46ff2bad7050c1331e51355282f35341)`()` | 
`public virtual bool `[`IsActivated`](#classNNullFactorUnit_1ad8b8c977a97a2ce7b4cccc982f60577c)`() const` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classNNullFactorUnit_1a0ff56b79e17b14406298671e4bf87169)`() const` | 
`public virtual void `[`SetOperator`](#classNNullFactorUnit_1a5ae79b4624bf6412654572906afa51e7)`(TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator)` | 
`public virtual float `[`GetFactorUnitValue`](#classNNullFactorUnit_1a46ffbab26d9d18773ba5a01ef85eb6f8)`() const` | 
`public virtual void `[`SetFactorUnitValue`](#classNNullFactorUnit_1a025584a2c473ab4f755c4f7ea0d1a768)`(float _Value)` | 
`public virtual FName `[`GetReason`](#classNNullFactorUnit_1a7c78dd5dd524f4d163afbecd817fd9c2)`() const` | 
`public virtual const FString `[`GetUID`](#classNNullFactorUnit_1a30f07497a8fe7fe403383084597ec9bc)`() const` | 
`public virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classNNullFactorUnit_1a23c5b7aec16c55fa725cf0ad5e04242b)`()` | 
`public virtual void `[`Activate`](#classNNullFactorUnit_1ad100123e9b29b3fcc362a4bb9a46f508)`(bool _bIsActivated)` | 

## Members

#### `public  `[`NNullFactorUnit`](#classNNullFactorUnit_1abf274f92f6a2c0a41e1033d700d77a32)`()` <a id="classNNullFactorUnit_1abf274f92f6a2c0a41e1033d700d77a32"></a>

#### `public virtual  `[`~NNullFactorUnit`](#classNNullFactorUnit_1a46ff2bad7050c1331e51355282f35341)`()` <a id="classNNullFactorUnit_1a46ff2bad7050c1331e51355282f35341"></a>

#### `public virtual bool `[`IsActivated`](#classNNullFactorUnit_1ad8b8c977a97a2ce7b4cccc982f60577c)`() const` <a id="classNNullFactorUnit_1ad8b8c977a97a2ce7b4cccc982f60577c"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classNNullFactorUnit_1a0ff56b79e17b14406298671e4bf87169)`() const` <a id="classNNullFactorUnit_1a0ff56b79e17b14406298671e4bf87169"></a>

#### `public virtual void `[`SetOperator`](#classNNullFactorUnit_1a5ae79b4624bf6412654572906afa51e7)`(TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator)` <a id="classNNullFactorUnit_1a5ae79b4624bf6412654572906afa51e7"></a>

#### `public virtual float `[`GetFactorUnitValue`](#classNNullFactorUnit_1a46ffbab26d9d18773ba5a01ef85eb6f8)`() const` <a id="classNNullFactorUnit_1a46ffbab26d9d18773ba5a01ef85eb6f8"></a>

#### `public virtual void `[`SetFactorUnitValue`](#classNNullFactorUnit_1a025584a2c473ab4f755c4f7ea0d1a768)`(float _Value)` <a id="classNNullFactorUnit_1a025584a2c473ab4f755c4f7ea0d1a768"></a>

#### `public virtual FName `[`GetReason`](#classNNullFactorUnit_1a7c78dd5dd524f4d163afbecd817fd9c2)`() const` <a id="classNNullFactorUnit_1a7c78dd5dd524f4d163afbecd817fd9c2"></a>

#### `public virtual const FString `[`GetUID`](#classNNullFactorUnit_1a30f07497a8fe7fe403383084597ec9bc)`() const` <a id="classNNullFactorUnit_1a30f07497a8fe7fe403383084597ec9bc"></a>

#### `public virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classNNullFactorUnit_1a23c5b7aec16c55fa725cf0ad5e04242b)`()` <a id="classNNullFactorUnit_1a23c5b7aec16c55fa725cf0ad5e04242b"></a>

#### `public virtual void `[`Activate`](#classNNullFactorUnit_1ad100123e9b29b3fcc362a4bb9a46f508)`(bool _bIsActivated)` <a id="classNNullFactorUnit_1ad100123e9b29b3fcc362a4bb9a46f508"></a>

# class `NNullOperator` <a id="classNNullOperator"></a>

```
class NNullOperator
  : public NFactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNNullOperator_1a74b252e0b045e0867b283668c0776956)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNNullOperator_1a134eb23923d2abfbd5278e80302a63fe)`()` | 
`public inline virtual const FName `[`GetName`](#classNNullOperator_1a5bab46d063f6b81227aa6925a34b1ea3)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNNullOperator_1a74b252e0b045e0867b283668c0776956)`(float Lh,float Rh)` <a id="classNNullOperator_1a74b252e0b045e0867b283668c0776956"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNNullOperator_1a134eb23923d2abfbd5278e80302a63fe)`()` <a id="classNNullOperator_1a134eb23923d2abfbd5278e80302a63fe"></a>

#### `public inline virtual const FName `[`GetName`](#classNNullOperator_1a5bab46d063f6b81227aa6925a34b1ea3)`()` <a id="classNNullOperator_1a5bab46d063f6b81227aa6925a34b1ea3"></a>

# class `NOperatorUtils` <a id="classNOperatorUtils"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `NReducersCleanerOperator` <a id="classNReducersCleanerOperator"></a>

```
class NReducersCleanerOperator
  : public NCleanerOperator
```  

This operator is raw! It removes every previous operator set in the factor's units queue. It cleans only factor's unit which implies factor amount reduction. The Rh parameter of the [Compute()](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6) method determines the amount of FactorUnit removed (0 = all). For the [Compute()](#classNCleanerOperator_1ab819ffc37a28d9d0e3cf6c885c0fd5d6) method it doesn't make any computation by returning the Lh parameter.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual bool `[`IsShouldClean`](#classNReducersCleanerOperator_1a4eb2a1b4a45557d75e84b6c553ffd05c)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit) const` | 

## Members

#### `public virtual bool `[`IsShouldClean`](#classNReducersCleanerOperator_1a4eb2a1b4a45557d75e84b6c553ffd05c)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit) const` <a id="classNReducersCleanerOperator_1a4eb2a1b4a45557d75e84b6c553ffd05c"></a>

# class `NReducersCleanerPersistentOperator` <a id="classNReducersCleanerPersistentOperator"></a>

```
class NReducersCleanerPersistentOperator
  : public NReducersCleanerOperator
  : public NFactorOperatorPersistentInterface
```  

This operator is raw! It removes every previous operator set in the factor's units queue. It cleans only factor's unit which implies factor amount reduction. The Rh parameter of the [Compute()](#classNReducersCleanerPersistentOperator_1a378e8aef2e4db7ff7a085ee18baba7f9) method determines the amount of FactorUnit removed (0 = all). For the [Compute()](#classNReducersCleanerPersistentOperator_1a378e8aef2e4db7ff7a085ee18baba7f9) method it doesn't make any computation by returning the Lh parameter. It removes also next Reducers set.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNReducersCleanerPersistentOperator_1a378e8aef2e4db7ff7a085ee18baba7f9)`(float Lh,float Rh,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > ActualUnit)` | 

## Members

#### `public virtual float `[`Compute`](#classNReducersCleanerPersistentOperator_1a378e8aef2e4db7ff7a085ee18baba7f9)`(float Lh,float Rh,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > ActualUnit)` <a id="classNReducersCleanerPersistentOperator_1a378e8aef2e4db7ff7a085ee18baba7f9"></a>

# class `NReplacerOperator` <a id="classNReplacerOperator"></a>

```
class NReplacerOperator
  : public NFactorOperatorStopperInterface
  : public NFactorOperatorInterface
```  

This operator replace the value from the previous operators list (It doesn't care of the Lh parameter of the method Compute). For the [Compute()](#classNReplacerOperator_1acc351a22cc2268269e0a2c531bf4be46) method, it returns the value set at the Rh parameter.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual const FName `[`GetName`](#classNReplacerOperator_1a90a05de757299fd8a148fc20eea18b19)`()` | 
`public virtual float `[`Compute`](#classNReplacerOperator_1acc351a22cc2268269e0a2c531bf4be46)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNReplacerOperator_1ad4e34d60c99dbaa94f2b6cac1d8bdcce)`()` | 

## Members

#### `public inline virtual const FName `[`GetName`](#classNReplacerOperator_1a90a05de757299fd8a148fc20eea18b19)`()` <a id="classNReplacerOperator_1a90a05de757299fd8a148fc20eea18b19"></a>

#### `public virtual float `[`Compute`](#classNReplacerOperator_1acc351a22cc2268269e0a2c531bf4be46)`(float Lh,float Rh)` <a id="classNReplacerOperator_1acc351a22cc2268269e0a2c531bf4be46"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNReplacerOperator_1ad4e34d60c99dbaa94f2b6cac1d8bdcce)`()` <a id="classNReplacerOperator_1ad4e34d60c99dbaa94f2b6cac1d8bdcce"></a>

# class `NResetOperator` <a id="classNResetOperator"></a>

```
class NResetOperator
  : public NResetOperatorBase
  : public NFactorOperatorWithFactorInterface
```  

This class find a previous FactorUnit and try to reset it. The Rh parameter of the [Compute()](#classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e) method determines the previous position (The Index of the FactorUnit which embeds this Operator - Rh) of the FactorUnit you want to reset.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~NResetOperator`](#classNResetOperator_1af776191fda9671ac0431ee6b0b668dce)`()` | 
`public inline virtual const FName `[`GetName`](#classNResetOperator_1a2a588aed7287ebf233d15d215970683f)`()` | 
`public virtual float `[`Compute`](#classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNResetOperator_1ac2d2f6d2a8046d58da2008c64c47abaa)`()` | 
`public virtual void `[`SetFactor`](#classNResetOperator_1a840a21d353d3af58c739da5c39b2d992)`(`[`NFactorInterface`](#classNFactorInterface)` * Factor)` | 
`public virtual void `[`SetKeyInFactor`](#classNResetOperator_1ae4e1b7d217cdcbabb22eaef7b04f0179)`(uint32 Key)` | 
`protected `[`NFactorInterface`](#classNFactorInterface)` * `[`MyFactor`](#classNResetOperator_1a5d438c4409ad63b3cdb3a8c2941f7f86) | 
`protected uint32 `[`KeyInFactor`](#classNResetOperator_1a1c9bef20770300e8662f188f8c52fe26) | 

## Members

#### `public virtual  `[`~NResetOperator`](#classNResetOperator_1af776191fda9671ac0431ee6b0b668dce)`()` <a id="classNResetOperator_1af776191fda9671ac0431ee6b0b668dce"></a>

#### `public inline virtual const FName `[`GetName`](#classNResetOperator_1a2a588aed7287ebf233d15d215970683f)`()` <a id="classNResetOperator_1a2a588aed7287ebf233d15d215970683f"></a>

#### `public virtual float `[`Compute`](#classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e)`(float Lh,float Rh)` <a id="classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNResetOperator_1ac2d2f6d2a8046d58da2008c64c47abaa)`()` <a id="classNResetOperator_1ac2d2f6d2a8046d58da2008c64c47abaa"></a>

#### `public virtual void `[`SetFactor`](#classNResetOperator_1a840a21d353d3af58c739da5c39b2d992)`(`[`NFactorInterface`](#classNFactorInterface)` * Factor)` <a id="classNResetOperator_1a840a21d353d3af58c739da5c39b2d992"></a>

#### `public virtual void `[`SetKeyInFactor`](#classNResetOperator_1ae4e1b7d217cdcbabb22eaef7b04f0179)`(uint32 Key)` <a id="classNResetOperator_1ae4e1b7d217cdcbabb22eaef7b04f0179"></a>

#### `protected `[`NFactorInterface`](#classNFactorInterface)` * `[`MyFactor`](#classNResetOperator_1a5d438c4409ad63b3cdb3a8c2941f7f86) <a id="classNResetOperator_1a5d438c4409ad63b3cdb3a8c2941f7f86"></a>

#### `protected uint32 `[`KeyInFactor`](#classNResetOperator_1a1c9bef20770300e8662f188f8c52fe26) <a id="classNResetOperator_1a1c9bef20770300e8662f188f8c52fe26"></a>

# class `NResetOperatorBase` <a id="classNResetOperatorBase"></a>

```
class NResetOperatorBase
  : public NFactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNResetOperatorBase_1af30c5155df50e0b709eeb5f6fc889428)`()` | 

## Members

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNResetOperatorBase_1af30c5155df50e0b709eeb5f6fc889428)`()` <a id="classNResetOperatorBase_1af30c5155df50e0b709eeb5f6fc889428"></a>

# class `NSubtractOperator` <a id="classNSubtractOperator"></a>

```
class NSubtractOperator
  : public NFactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNSubtractOperator_1a3e2ee7cd12d97cab09b52a59ad2580e3)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNSubtractOperator_1a2f65d299922c617578eacf465a977204)`()` | 
`public inline virtual const FName `[`GetName`](#classNSubtractOperator_1a78c46b462f7fd4a3993f5d8c3266da65)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNSubtractOperator_1a3e2ee7cd12d97cab09b52a59ad2580e3)`(float Lh,float Rh)` <a id="classNSubtractOperator_1a3e2ee7cd12d97cab09b52a59ad2580e3"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetInverse`](#classNSubtractOperator_1a2f65d299922c617578eacf465a977204)`()` <a id="classNSubtractOperator_1a2f65d299922c617578eacf465a977204"></a>

#### `public inline virtual const FName `[`GetName`](#classNSubtractOperator_1a78c46b462f7fd4a3993f5d8c3266da65)`()` <a id="classNSubtractOperator_1a78c46b462f7fd4a3993f5d8c3266da65"></a>

# class `NUnrealFactorProxy` <a id="classNUnrealFactorProxy"></a>

```
class NUnrealFactorProxy
  : public NFactorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNFactorDecorator`](#classUNFactorDecorator)` & `[`Factor`](#classNUnrealFactorProxy_1ac0d4e9b2c781c6a3aa96cbf70bc7a4e4) | 
`public inline  `[`NUnrealFactorProxy`](#classNUnrealFactorProxy_1a73fb25c3ec10e83539591932272a2dbe)`(`[`UNFactorDecorator`](#classUNFactorDecorator)` & _Factor)` | 
`public virtual void `[`Clear`](#classNUnrealFactorProxy_1a493535d9183c0ee4096fa98c77d7c546)`()` | 
`public virtual void `[`SetName`](#classNUnrealFactorProxy_1a95d8bdc6d20c999817d6de30072ef878)`(FName _Name)` | 
`public virtual FName `[`GetName`](#classNUnrealFactorProxy_1a6c61a479db7afa0805fd880eede88aca)`() const` | 
`public virtual TSharedPtr< NTimelineInterface > `[`GetTimeline`](#classNUnrealFactorProxy_1a2c0276ac93171db220a209996823112f)`() const` | 
`public virtual float `[`GetTime`](#classNUnrealFactorProxy_1a835793be01ba3f24ed3a6c884f10446f)`() const` | 
`public virtual TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classNUnrealFactorProxy_1ab2a00c614f9684ed391375ba1b000a74)`(uint32 Key) const` | 
`public virtual TArray< TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > > `[`GetFactors`](#classNUnrealFactorProxy_1a446893ac332e4f98694fc3360df0159c)`() const` | 
`public virtual int32 `[`AddFactorUnit`](#classNUnrealFactorProxy_1a9e3a613acaef37f167a11fa96593217d)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` | 
`public virtual bool `[`HasStateFlag`](#classNUnrealFactorProxy_1a377f1cafbd99f1fe0374075e016c9c58)`(FString Flag) const` | 
`public virtual bool `[`GetStateFlag`](#classNUnrealFactorProxy_1a42aa779d4ab737ecf9c213abde80cad5)`(FString Flag) const` | 
`public virtual void `[`SetStateFlag`](#classNUnrealFactorProxy_1a93f384aefe60aedd01fccf05fda7bb4c)`(FString Flag,bool Value)` | 
`public virtual void `[`RemoveStateFlag`](#classNUnrealFactorProxy_1ac89d496882b27f596cb65ee859e526d5)`(FString Flag)` | 
`public virtual void `[`AddFlag`](#classNUnrealFactorProxy_1a92c800933de8b489f8b739594a952570)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` | 
`public virtual bool `[`HasFlag`](#classNUnrealFactorProxy_1a6aec220f10e951435b7a9a9771cf210b)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag) const` | 
`public virtual void `[`RemoveFlag`](#classNUnrealFactorProxy_1a65745a8ac24c90440f79202e6bc6b448)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` | 
`public virtual void `[`Debug`](#classNUnrealFactorProxy_1a0c11e6af6776d8d8a9ef4e372e8d3906)`(bool _bDebug)` | 
`public virtual void `[`SupplyStateWithCurrentData`](#classNUnrealFactorProxy_1ab3e71d6372845d4bbed0f8681df60a2a)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` | 
`public virtual `[`UNFactorDecorator`](#classUNFactorDecorator)` * `[`GetUnrealObject`](#classNUnrealFactorProxy_1a9de3b199a932a3233f3b4c33708683b4)`() const` | 

## Members

#### `public `[`UNFactorDecorator`](#classUNFactorDecorator)` & `[`Factor`](#classNUnrealFactorProxy_1ac0d4e9b2c781c6a3aa96cbf70bc7a4e4) <a id="classNUnrealFactorProxy_1ac0d4e9b2c781c6a3aa96cbf70bc7a4e4"></a>

#### `public inline  `[`NUnrealFactorProxy`](#classNUnrealFactorProxy_1a73fb25c3ec10e83539591932272a2dbe)`(`[`UNFactorDecorator`](#classUNFactorDecorator)` & _Factor)` <a id="classNUnrealFactorProxy_1a73fb25c3ec10e83539591932272a2dbe"></a>

#### `public virtual void `[`Clear`](#classNUnrealFactorProxy_1a493535d9183c0ee4096fa98c77d7c546)`()` <a id="classNUnrealFactorProxy_1a493535d9183c0ee4096fa98c77d7c546"></a>

#### `public virtual void `[`SetName`](#classNUnrealFactorProxy_1a95d8bdc6d20c999817d6de30072ef878)`(FName _Name)` <a id="classNUnrealFactorProxy_1a95d8bdc6d20c999817d6de30072ef878"></a>

#### `public virtual FName `[`GetName`](#classNUnrealFactorProxy_1a6c61a479db7afa0805fd880eede88aca)`() const` <a id="classNUnrealFactorProxy_1a6c61a479db7afa0805fd880eede88aca"></a>

#### `public virtual TSharedPtr< NTimelineInterface > `[`GetTimeline`](#classNUnrealFactorProxy_1a2c0276ac93171db220a209996823112f)`() const` <a id="classNUnrealFactorProxy_1a2c0276ac93171db220a209996823112f"></a>

#### `public virtual float `[`GetTime`](#classNUnrealFactorProxy_1a835793be01ba3f24ed3a6c884f10446f)`() const` <a id="classNUnrealFactorProxy_1a835793be01ba3f24ed3a6c884f10446f"></a>

#### `public virtual TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classNUnrealFactorProxy_1ab2a00c614f9684ed391375ba1b000a74)`(uint32 Key) const` <a id="classNUnrealFactorProxy_1ab2a00c614f9684ed391375ba1b000a74"></a>

#### `public virtual TArray< TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > > `[`GetFactors`](#classNUnrealFactorProxy_1a446893ac332e4f98694fc3360df0159c)`() const` <a id="classNUnrealFactorProxy_1a446893ac332e4f98694fc3360df0159c"></a>

#### `public virtual int32 `[`AddFactorUnit`](#classNUnrealFactorProxy_1a9e3a613acaef37f167a11fa96593217d)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` <a id="classNUnrealFactorProxy_1a9e3a613acaef37f167a11fa96593217d"></a>

#### `public virtual bool `[`HasStateFlag`](#classNUnrealFactorProxy_1a377f1cafbd99f1fe0374075e016c9c58)`(FString Flag) const` <a id="classNUnrealFactorProxy_1a377f1cafbd99f1fe0374075e016c9c58"></a>

#### `public virtual bool `[`GetStateFlag`](#classNUnrealFactorProxy_1a42aa779d4ab737ecf9c213abde80cad5)`(FString Flag) const` <a id="classNUnrealFactorProxy_1a42aa779d4ab737ecf9c213abde80cad5"></a>

#### `public virtual void `[`SetStateFlag`](#classNUnrealFactorProxy_1a93f384aefe60aedd01fccf05fda7bb4c)`(FString Flag,bool Value)` <a id="classNUnrealFactorProxy_1a93f384aefe60aedd01fccf05fda7bb4c"></a>

#### `public virtual void `[`RemoveStateFlag`](#classNUnrealFactorProxy_1ac89d496882b27f596cb65ee859e526d5)`(FString Flag)` <a id="classNUnrealFactorProxy_1ac89d496882b27f596cb65ee859e526d5"></a>

#### `public virtual void `[`AddFlag`](#classNUnrealFactorProxy_1a92c800933de8b489f8b739594a952570)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` <a id="classNUnrealFactorProxy_1a92c800933de8b489f8b739594a952570"></a>

#### `public virtual bool `[`HasFlag`](#classNUnrealFactorProxy_1a6aec220f10e951435b7a9a9771cf210b)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag) const` <a id="classNUnrealFactorProxy_1a6aec220f10e951435b7a9a9771cf210b"></a>

#### `public virtual void `[`RemoveFlag`](#classNUnrealFactorProxy_1a65745a8ac24c90440f79202e6bc6b448)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` <a id="classNUnrealFactorProxy_1a65745a8ac24c90440f79202e6bc6b448"></a>

#### `public virtual void `[`Debug`](#classNUnrealFactorProxy_1a0c11e6af6776d8d8a9ef4e372e8d3906)`(bool _bDebug)` <a id="classNUnrealFactorProxy_1a0c11e6af6776d8d8a9ef4e372e8d3906"></a>

#### `public virtual void `[`SupplyStateWithCurrentData`](#classNUnrealFactorProxy_1ab3e71d6372845d4bbed0f8681df60a2a)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` <a id="classNUnrealFactorProxy_1ab3e71d6372845d4bbed0f8681df60a2a"></a>

#### `public virtual `[`UNFactorDecorator`](#classUNFactorDecorator)` * `[`GetUnrealObject`](#classNUnrealFactorProxy_1a9de3b199a932a3233f3b4c33708683b4)`() const` <a id="classNUnrealFactorProxy_1a9de3b199a932a3233f3b4c33708683b4"></a>

# class `NUnrealFactorUnitProxy` <a id="classNUnrealFactorUnitProxy"></a>

```
class NUnrealFactorUnitProxy
  : public NFactorUnitInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * `[`FactorUnit`](#classNUnrealFactorUnitProxy_1a02427b72567f5d134334d86e017038ff) | 
`public inline  `[`NUnrealFactorUnitProxy`](#classNUnrealFactorUnitProxy_1abd1f79022911318861793ba0216044c4)`(`[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * _FactorUnit)` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classNUnrealFactorUnitProxy_1a6b0443ff2d2ad592d35d3f0436847122)`() const` | 
`public virtual void `[`SetOperator`](#classNUnrealFactorUnitProxy_1a762f634df2b0f567dd77147021042caf)`(TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator)` | 
`public virtual float `[`GetFactorUnitValue`](#classNUnrealFactorUnitProxy_1aa62c653a47165b6d8709d351447b389f)`() const` | 
`public virtual void `[`SetFactorUnitValue`](#classNUnrealFactorUnitProxy_1a0392d77e457cb12dc5499258cbba4bb0)`(float _Value)` | 
`public virtual FName `[`GetReason`](#classNUnrealFactorUnitProxy_1adcd53d6f9614ccb63ab4713d220cfbc1)`() const` | 
`public virtual bool `[`IsActivated`](#classNUnrealFactorUnitProxy_1abbdfd8dce8631d8d8bbdfc91c799228b)`() const` | 
`public virtual const FString `[`GetUID`](#classNUnrealFactorUnitProxy_1a91858cd0e1fcf04681e8481105b484ae)`() const` | 
`public virtual void `[`Activate`](#classNUnrealFactorUnitProxy_1a7288e953010eb1395f2a3e2e3e0ca3e0)`(bool _bIsActivated)` | 
`public virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classNUnrealFactorUnitProxy_1aa96f37e135760b63f28b329b8b34dcb4)`()` | 
`public virtual `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * `[`GetUnrealObject`](#classNUnrealFactorUnitProxy_1ad1c8a88092efb1487596559e32fe3990)`()` | 

## Members

#### `public `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * `[`FactorUnit`](#classNUnrealFactorUnitProxy_1a02427b72567f5d134334d86e017038ff) <a id="classNUnrealFactorUnitProxy_1a02427b72567f5d134334d86e017038ff"></a>

#### `public inline  `[`NUnrealFactorUnitProxy`](#classNUnrealFactorUnitProxy_1abd1f79022911318861793ba0216044c4)`(`[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * _FactorUnit)` <a id="classNUnrealFactorUnitProxy_1abd1f79022911318861793ba0216044c4"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classNUnrealFactorUnitProxy_1a6b0443ff2d2ad592d35d3f0436847122)`() const` <a id="classNUnrealFactorUnitProxy_1a6b0443ff2d2ad592d35d3f0436847122"></a>

#### `public virtual void `[`SetOperator`](#classNUnrealFactorUnitProxy_1a762f634df2b0f567dd77147021042caf)`(TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator)` <a id="classNUnrealFactorUnitProxy_1a762f634df2b0f567dd77147021042caf"></a>

#### `public virtual float `[`GetFactorUnitValue`](#classNUnrealFactorUnitProxy_1aa62c653a47165b6d8709d351447b389f)`() const` <a id="classNUnrealFactorUnitProxy_1aa62c653a47165b6d8709d351447b389f"></a>

#### `public virtual void `[`SetFactorUnitValue`](#classNUnrealFactorUnitProxy_1a0392d77e457cb12dc5499258cbba4bb0)`(float _Value)` <a id="classNUnrealFactorUnitProxy_1a0392d77e457cb12dc5499258cbba4bb0"></a>

#### `public virtual FName `[`GetReason`](#classNUnrealFactorUnitProxy_1adcd53d6f9614ccb63ab4713d220cfbc1)`() const` <a id="classNUnrealFactorUnitProxy_1adcd53d6f9614ccb63ab4713d220cfbc1"></a>

#### `public virtual bool `[`IsActivated`](#classNUnrealFactorUnitProxy_1abbdfd8dce8631d8d8bbdfc91c799228b)`() const` <a id="classNUnrealFactorUnitProxy_1abbdfd8dce8631d8d8bbdfc91c799228b"></a>

#### `public virtual const FString `[`GetUID`](#classNUnrealFactorUnitProxy_1a91858cd0e1fcf04681e8481105b484ae)`() const` <a id="classNUnrealFactorUnitProxy_1a91858cd0e1fcf04681e8481105b484ae"></a>

#### `public virtual void `[`Activate`](#classNUnrealFactorUnitProxy_1a7288e953010eb1395f2a3e2e3e0ca3e0)`(bool _bIsActivated)` <a id="classNUnrealFactorUnitProxy_1a7288e953010eb1395f2a3e2e3e0ca3e0"></a>

#### `public virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classNUnrealFactorUnitProxy_1aa96f37e135760b63f28b329b8b34dcb4)`()` <a id="classNUnrealFactorUnitProxy_1aa96f37e135760b63f28b329b8b34dcb4"></a>

#### `public virtual `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * `[`GetUnrealObject`](#classNUnrealFactorUnitProxy_1ad1c8a88092efb1487596559e32fe3990)`()` <a id="classNUnrealFactorUnitProxy_1ad1c8a88092efb1487596559e32fe3990"></a>

# class `SNFactorSettingsPin` <a id="classSNFactorSettingsPin"></a>

```
class SNFactorSettingsPin
  : public SGraphPin
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`SLATE_BEGIN_ARGS`](#classSNFactorSettingsPin_1afc074c2155bddfd3d64e12ba3c239548)`(`[`SNFactorSettingsPin`](#classSNFactorSettingsPin)`)` | 
`public void `[`Construct`](#classSNFactorSettingsPin_1a0aac041c949913111d20f31953efb59a)`(const FArguments & InArgs,UEdGraphPin * InGraphPinObj)` | 
`protected virtual TSharedRef< SWidget > `[`GetDefaultValueWidget`](#classSNFactorSettingsPin_1a9b560b990ec7cc79e8c839e47f9ec453)`()` | 
`protected void `[`OnAttributeSelected`](#classSNFactorSettingsPin_1a8fe7bd5cdeda13d3624d45e42374b926)`(TSharedPtr< FName > ItemSelected,ESelectInfo::Type SelectInfo)` | 
`protected void `[`OnComboBoxOpening`](#classSNFactorSettingsPin_1a96442988394334c9de18082669fcd4fd)`()` | 
`protected TSharedPtr< FName > `[`GetSelectedName`](#classSNFactorSettingsPin_1a056eb131f65ec2acdfc095f681efc676)`() const` | 
`protected void `[`SetPropertyWithName`](#classSNFactorSettingsPin_1a74e665b1c736f47317836dd7b53facd7)`(const FName & Name)` | 
`protected void `[`GetPropertyAsName`](#classSNFactorSettingsPin_1a871c4df19487070baf998598078db9f6)`(FName & OutName) const` | 

## Members

#### `public inline  `[`SLATE_BEGIN_ARGS`](#classSNFactorSettingsPin_1afc074c2155bddfd3d64e12ba3c239548)`(`[`SNFactorSettingsPin`](#classSNFactorSettingsPin)`)` <a id="classSNFactorSettingsPin_1afc074c2155bddfd3d64e12ba3c239548"></a>

#### `public void `[`Construct`](#classSNFactorSettingsPin_1a0aac041c949913111d20f31953efb59a)`(const FArguments & InArgs,UEdGraphPin * InGraphPinObj)` <a id="classSNFactorSettingsPin_1a0aac041c949913111d20f31953efb59a"></a>

#### `protected virtual TSharedRef< SWidget > `[`GetDefaultValueWidget`](#classSNFactorSettingsPin_1a9b560b990ec7cc79e8c839e47f9ec453)`()` <a id="classSNFactorSettingsPin_1a9b560b990ec7cc79e8c839e47f9ec453"></a>

#### `protected void `[`OnAttributeSelected`](#classSNFactorSettingsPin_1a8fe7bd5cdeda13d3624d45e42374b926)`(TSharedPtr< FName > ItemSelected,ESelectInfo::Type SelectInfo)` <a id="classSNFactorSettingsPin_1a8fe7bd5cdeda13d3624d45e42374b926"></a>

#### `protected void `[`OnComboBoxOpening`](#classSNFactorSettingsPin_1a96442988394334c9de18082669fcd4fd)`()` <a id="classSNFactorSettingsPin_1a96442988394334c9de18082669fcd4fd"></a>

#### `protected TSharedPtr< FName > `[`GetSelectedName`](#classSNFactorSettingsPin_1a056eb131f65ec2acdfc095f681efc676)`() const` <a id="classSNFactorSettingsPin_1a056eb131f65ec2acdfc095f681efc676"></a>

#### `protected void `[`SetPropertyWithName`](#classSNFactorSettingsPin_1a74e665b1c736f47317836dd7b53facd7)`(const FName & Name)` <a id="classSNFactorSettingsPin_1a74e665b1c736f47317836dd7b53facd7"></a>

#### `protected void `[`GetPropertyAsName`](#classSNFactorSettingsPin_1a871c4df19487070baf998598078db9f6)`(FName & OutName) const` <a id="classSNFactorSettingsPin_1a871c4df19487070baf998598078db9f6"></a>

# class `UFactorSettings` <a id="classUFactorSettings"></a>

```
class UFactorSettings
  : public UDeveloperSettings
```  

This allow to

Thanks to: [https://forums.unrealengine.com/development-discussion/c-gameplay-programming/1503868-adding-a-custom-ini-file](https://forums.unrealengine.com/development-discussion/c-gameplay-programming/1503868-adding-a-custom-ini-file)

**See also**: [https://github.com/NansPellicari/UE4-HowTo-CustomPin](https://github.com/NansPellicari/UE4-HowTo-CustomPin) to get more examples.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TArray< `[`FNFactorSettings`](#structFNFactorSettings)` > `[`CategoryNames`](#classUFactorSettings_1aa3e82d4ec785fb841541eaacabc904c3) | 

## Members

#### `public TArray< `[`FNFactorSettings`](#structFNFactorSettings)` > `[`CategoryNames`](#classUFactorSettings_1aa3e82d4ec785fb841541eaacabc904c3) <a id="classUFactorSettings_1aa3e82d4ec785fb841541eaacabc904c3"></a>

# class `UK2Node_FactorUnit` <a id="classUK2Node__FactorUnit"></a>

```
class UK2Node_FactorUnit
  : public UK2Node
```  

TODO: This class needs to be cleaned, refactored and documented

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`BeginDestroy`](#classUK2Node__FactorUnit_1a81c836c7347d7c7794f905506300a5b6)`()` | 
`public virtual void `[`PostEditChangeProperty`](#classUK2Node__FactorUnit_1ad506d88fcaf4dd41ae9759d9c900d1f1)`(struct FPropertyChangedEvent & PropertyChangedEvent)` | 
`public virtual void `[`PreEditChange`](#classUK2Node__FactorUnit_1a3bf81b59c73f02025937e2c8b4e19ba7)`(UProperty * PropertyAboutToChange)` | 
`public virtual FText `[`GetNodeTitle`](#classUK2Node__FactorUnit_1a60801166ba25be9afc815515c91fb989)`(ENodeTitleType::Type TitleType) const` | 
`public virtual FText `[`GetTooltipText`](#classUK2Node__FactorUnit_1a6b96d80b1066e8dfb7d82762c49bb5d1)`() const` | 
`public virtual void `[`AllocateDefaultPins`](#classUK2Node__FactorUnit_1a0d3be5d50d3234e0b1426757f4db3ef8)`()` | 
`public virtual void `[`PostPlacedNewNode`](#classUK2Node__FactorUnit_1af82261abd70183df239caafafc4f366c)`()` | 
`public virtual void `[`PinDefaultValueChanged`](#classUK2Node__FactorUnit_1aff6537a6054aeb4cd12fac44893925f6)`(UEdGraphPin * Pin)` | 
`public virtual void `[`PinConnectionListChanged`](#classUK2Node__FactorUnit_1a1c182d9f7feca6ec962005ef4e07bc4c)`(UEdGraphPin * Pin)` | 
`public virtual void `[`ValidateNodeDuringCompilation`](#classUK2Node__FactorUnit_1a960ec7e2bb2d95969e0d011be7adbca5)`(class FCompilerResultsLog & MessageLog) const` | 
`public inline virtual bool `[`ShouldShowNodeProperties`](#classUK2Node__FactorUnit_1a43b3d5d9b744502fbc7cde7923dc86c4)`() const` | 
`public virtual void `[`ReallocatePinsDuringReconstruction`](#classUK2Node__FactorUnit_1af8e49d77d879ed3f3c8c3b984cf9607e)`(TArray< UEdGraphPin * > & OldPins)` | 
`public virtual bool `[`HasExternalDependencies`](#classUK2Node__FactorUnit_1a4a63d00ddeaf125df6c66546f73c14d7)`(TArray< class UStruct * > * OptionalOutput) const` | 
`public virtual class FNodeHandlingFunctor * `[`CreateNodeHandler`](#classUK2Node__FactorUnit_1a551dbd176f60eb3069dccb31ba524461)`(class FKismetCompilerContext & CompilerContext) const` | 
`public virtual void `[`ExpandNode`](#classUK2Node__FactorUnit_1a2e5e0b8e6114590dc36d9fa471d0055f)`(class FKismetCompilerContext & CompilerContext,UEdGraph * SourceGraph)` | 
`public virtual void `[`GetMenuActions`](#classUK2Node__FactorUnit_1aec517d36a7578ea0067a28198c840788)`(FBlueprintActionDatabaseRegistrar & ActionRegistrar) const` | 
`public virtual FText `[`GetMenuCategory`](#classUK2Node__FactorUnit_1a6461f2f87642397004aae08e5faa4c7b)`() const` | 
`public UEdGraphPin * `[`FindClassPin`](#classUK2Node__FactorUnit_1a4ffb25e6bd7900ca50961ce59df5612b)`() const` | Finds and returns the class input pin from the current set of pins.
`public UEdGraphPin * `[`FindFactorPin`](#classUK2Node__FactorUnit_1aee2299b4a7d4e451e42254abd3db99fd)`() const` | 
`public UEdGraphPin * `[`FindOperatorPin`](#classUK2Node__FactorUnit_1a912d4d7c7f43b16750065c6ef0c4fe75)`() const` | 
`public UEdGraphPin * `[`GetResultPin`](#classUK2Node__FactorUnit_1a6d8f4261dc9d176d79995e160a1593a9)`() const` | 
`public UEdGraphPin * `[`GetThenPin`](#classUK2Node__FactorUnit_1a1f970cb823a3453b3b09018f7379e9a4)`() const` | 
`public UEdGraphPin * `[`GetOuterPin`](#classUK2Node__FactorUnit_1a306c1b2361f7bc71835a0da7eb9d1f9d)`() const` | 
`public UClass * `[`GetInputClass`](#classUK2Node__FactorUnit_1a8a86283041c0c174970a4bbc55cb3dfa)`() const` | Retrieves the current input class type.
`public UClass * `[`GetInputOperatorClass`](#classUK2Node__FactorUnit_1a7731286605c2e7c5990fc46fc520587d)`() const` | Retrieves the current input operator class type.
`public void `[`OnBlueprintClassModified`](#classUK2Node__FactorUnit_1a6f884e91e77f6cc633c667632ee8b124)`(UBlueprint * TargetBlueprint)` | 
`public void `[`ClearDelegates`](#classUK2Node__FactorUnit_1a563cb61adc2033d2be4c20dd957830ad)`(FString InClassName)` | 
`protected UEdGraphPin * `[`FindClassPin`](#classUK2Node__FactorUnit_1acbbea8ac79812d971aa2b1d17923b0b7)`(const TArray< UEdGraphPin * > & FromPins) const` | Finds and returns the class input pin.
`protected UEdGraphPin * `[`FindFactorPin`](#classUK2Node__FactorUnit_1a3c346385e3100bba0d6bb8abebab48db)`(const TArray< UEdGraphPin * > & FromPins) const` | Finds and returns the factor input pin.
`protected UEdGraphPin * `[`FindOperatorPin`](#classUK2Node__FactorUnit_1a3b1c1ad4c215434934b557585d913c19)`(const TArray< UEdGraphPin * > & FromPins) const` | Finds and returns the opearator provider input pin.
`protected UClass * `[`GetInputClass`](#classUK2Node__FactorUnit_1a52e4320f505f4a74abf9beadcff32a36)`(const UEdGraphPin * FromPin) const` | Determines the input class type from the given pin.
`protected UClass * `[`GetInputOperatorClass`](#classUK2Node__FactorUnit_1a953580996631360f7c72490691bdf174)`(const UEdGraphPin * FromPin) const` | Determines the input operator class type from the given pin.
`protected void `[`CreateNewPins`](#classUK2Node__FactorUnit_1a8039ee6de899d3d23f9ec5d816a80d15)`(UClass * InClass,bool bOuputPin)` | Creates the full set of pins (properties) from the given input class.
`protected void `[`OnClassPinChanged`](#classUK2Node__FactorUnit_1a2ab3ac66a08fc41b225743a53b460493)`()` | Will be called whenever the class pin selector changes its value.

## Members

#### `public virtual void `[`BeginDestroy`](#classUK2Node__FactorUnit_1a81c836c7347d7c7794f905506300a5b6)`()` <a id="classUK2Node__FactorUnit_1a81c836c7347d7c7794f905506300a5b6"></a>

#### `public virtual void `[`PostEditChangeProperty`](#classUK2Node__FactorUnit_1ad506d88fcaf4dd41ae9759d9c900d1f1)`(struct FPropertyChangedEvent & PropertyChangedEvent)` <a id="classUK2Node__FactorUnit_1ad506d88fcaf4dd41ae9759d9c900d1f1"></a>

#### `public virtual void `[`PreEditChange`](#classUK2Node__FactorUnit_1a3bf81b59c73f02025937e2c8b4e19ba7)`(UProperty * PropertyAboutToChange)` <a id="classUK2Node__FactorUnit_1a3bf81b59c73f02025937e2c8b4e19ba7"></a>

#### `public virtual FText `[`GetNodeTitle`](#classUK2Node__FactorUnit_1a60801166ba25be9afc815515c91fb989)`(ENodeTitleType::Type TitleType) const` <a id="classUK2Node__FactorUnit_1a60801166ba25be9afc815515c91fb989"></a>

#### `public virtual FText `[`GetTooltipText`](#classUK2Node__FactorUnit_1a6b96d80b1066e8dfb7d82762c49bb5d1)`() const` <a id="classUK2Node__FactorUnit_1a6b96d80b1066e8dfb7d82762c49bb5d1"></a>

#### `public virtual void `[`AllocateDefaultPins`](#classUK2Node__FactorUnit_1a0d3be5d50d3234e0b1426757f4db3ef8)`()` <a id="classUK2Node__FactorUnit_1a0d3be5d50d3234e0b1426757f4db3ef8"></a>

#### `public virtual void `[`PostPlacedNewNode`](#classUK2Node__FactorUnit_1af82261abd70183df239caafafc4f366c)`()` <a id="classUK2Node__FactorUnit_1af82261abd70183df239caafafc4f366c"></a>

#### `public virtual void `[`PinDefaultValueChanged`](#classUK2Node__FactorUnit_1aff6537a6054aeb4cd12fac44893925f6)`(UEdGraphPin * Pin)` <a id="classUK2Node__FactorUnit_1aff6537a6054aeb4cd12fac44893925f6"></a>

#### `public virtual void `[`PinConnectionListChanged`](#classUK2Node__FactorUnit_1a1c182d9f7feca6ec962005ef4e07bc4c)`(UEdGraphPin * Pin)` <a id="classUK2Node__FactorUnit_1a1c182d9f7feca6ec962005ef4e07bc4c"></a>

#### `public virtual void `[`ValidateNodeDuringCompilation`](#classUK2Node__FactorUnit_1a960ec7e2bb2d95969e0d011be7adbca5)`(class FCompilerResultsLog & MessageLog) const` <a id="classUK2Node__FactorUnit_1a960ec7e2bb2d95969e0d011be7adbca5"></a>

#### `public inline virtual bool `[`ShouldShowNodeProperties`](#classUK2Node__FactorUnit_1a43b3d5d9b744502fbc7cde7923dc86c4)`() const` <a id="classUK2Node__FactorUnit_1a43b3d5d9b744502fbc7cde7923dc86c4"></a>

#### `public virtual void `[`ReallocatePinsDuringReconstruction`](#classUK2Node__FactorUnit_1af8e49d77d879ed3f3c8c3b984cf9607e)`(TArray< UEdGraphPin * > & OldPins)` <a id="classUK2Node__FactorUnit_1af8e49d77d879ed3f3c8c3b984cf9607e"></a>

#### `public virtual bool `[`HasExternalDependencies`](#classUK2Node__FactorUnit_1a4a63d00ddeaf125df6c66546f73c14d7)`(TArray< class UStruct * > * OptionalOutput) const` <a id="classUK2Node__FactorUnit_1a4a63d00ddeaf125df6c66546f73c14d7"></a>

#### `public virtual class FNodeHandlingFunctor * `[`CreateNodeHandler`](#classUK2Node__FactorUnit_1a551dbd176f60eb3069dccb31ba524461)`(class FKismetCompilerContext & CompilerContext) const` <a id="classUK2Node__FactorUnit_1a551dbd176f60eb3069dccb31ba524461"></a>

#### `public virtual void `[`ExpandNode`](#classUK2Node__FactorUnit_1a2e5e0b8e6114590dc36d9fa471d0055f)`(class FKismetCompilerContext & CompilerContext,UEdGraph * SourceGraph)` <a id="classUK2Node__FactorUnit_1a2e5e0b8e6114590dc36d9fa471d0055f"></a>

#### `public virtual void `[`GetMenuActions`](#classUK2Node__FactorUnit_1aec517d36a7578ea0067a28198c840788)`(FBlueprintActionDatabaseRegistrar & ActionRegistrar) const` <a id="classUK2Node__FactorUnit_1aec517d36a7578ea0067a28198c840788"></a>

#### `public virtual FText `[`GetMenuCategory`](#classUK2Node__FactorUnit_1a6461f2f87642397004aae08e5faa4c7b)`() const` <a id="classUK2Node__FactorUnit_1a6461f2f87642397004aae08e5faa4c7b"></a>

#### `public UEdGraphPin * `[`FindClassPin`](#classUK2Node__FactorUnit_1a4ffb25e6bd7900ca50961ce59df5612b)`() const` <a id="classUK2Node__FactorUnit_1a4ffb25e6bd7900ca50961ce59df5612b"></a>

Finds and returns the class input pin from the current set of pins.

#### `public UEdGraphPin * `[`FindFactorPin`](#classUK2Node__FactorUnit_1aee2299b4a7d4e451e42254abd3db99fd)`() const` <a id="classUK2Node__FactorUnit_1aee2299b4a7d4e451e42254abd3db99fd"></a>

#### `public UEdGraphPin * `[`FindOperatorPin`](#classUK2Node__FactorUnit_1a912d4d7c7f43b16750065c6ef0c4fe75)`() const` <a id="classUK2Node__FactorUnit_1a912d4d7c7f43b16750065c6ef0c4fe75"></a>

#### `public UEdGraphPin * `[`GetResultPin`](#classUK2Node__FactorUnit_1a6d8f4261dc9d176d79995e160a1593a9)`() const` <a id="classUK2Node__FactorUnit_1a6d8f4261dc9d176d79995e160a1593a9"></a>

#### `public UEdGraphPin * `[`GetThenPin`](#classUK2Node__FactorUnit_1a1f970cb823a3453b3b09018f7379e9a4)`() const` <a id="classUK2Node__FactorUnit_1a1f970cb823a3453b3b09018f7379e9a4"></a>

#### `public UEdGraphPin * `[`GetOuterPin`](#classUK2Node__FactorUnit_1a306c1b2361f7bc71835a0da7eb9d1f9d)`() const` <a id="classUK2Node__FactorUnit_1a306c1b2361f7bc71835a0da7eb9d1f9d"></a>

#### `public UClass * `[`GetInputClass`](#classUK2Node__FactorUnit_1a8a86283041c0c174970a4bbc55cb3dfa)`() const` <a id="classUK2Node__FactorUnit_1a8a86283041c0c174970a4bbc55cb3dfa"></a>

Retrieves the current input class type.

#### `public UClass * `[`GetInputOperatorClass`](#classUK2Node__FactorUnit_1a7731286605c2e7c5990fc46fc520587d)`() const` <a id="classUK2Node__FactorUnit_1a7731286605c2e7c5990fc46fc520587d"></a>

Retrieves the current input operator class type.

#### `public void `[`OnBlueprintClassModified`](#classUK2Node__FactorUnit_1a6f884e91e77f6cc633c667632ee8b124)`(UBlueprint * TargetBlueprint)` <a id="classUK2Node__FactorUnit_1a6f884e91e77f6cc633c667632ee8b124"></a>

#### `public void `[`ClearDelegates`](#classUK2Node__FactorUnit_1a563cb61adc2033d2be4c20dd957830ad)`(FString InClassName)` <a id="classUK2Node__FactorUnit_1a563cb61adc2033d2be4c20dd957830ad"></a>

#### `protected UEdGraphPin * `[`FindClassPin`](#classUK2Node__FactorUnit_1acbbea8ac79812d971aa2b1d17923b0b7)`(const TArray< UEdGraphPin * > & FromPins) const` <a id="classUK2Node__FactorUnit_1acbbea8ac79812d971aa2b1d17923b0b7"></a>

Finds and returns the class input pin.

#### Parameters
* `FromPins` A list of pins to search.

#### `protected UEdGraphPin * `[`FindFactorPin`](#classUK2Node__FactorUnit_1a3c346385e3100bba0d6bb8abebab48db)`(const TArray< UEdGraphPin * > & FromPins) const` <a id="classUK2Node__FactorUnit_1a3c346385e3100bba0d6bb8abebab48db"></a>

Finds and returns the factor input pin.

#### Parameters
* `FromPins` A list of pins to search.

#### `protected UEdGraphPin * `[`FindOperatorPin`](#classUK2Node__FactorUnit_1a3b1c1ad4c215434934b557585d913c19)`(const TArray< UEdGraphPin * > & FromPins) const` <a id="classUK2Node__FactorUnit_1a3b1c1ad4c215434934b557585d913c19"></a>

Finds and returns the opearator provider input pin.

#### Parameters
* `FromPins` A list of pins to search.

#### `protected UClass * `[`GetInputClass`](#classUK2Node__FactorUnit_1a52e4320f505f4a74abf9beadcff32a36)`(const UEdGraphPin * FromPin) const` <a id="classUK2Node__FactorUnit_1a52e4320f505f4a74abf9beadcff32a36"></a>

Determines the input class type from the given pin.

#### Parameters
* `FromPin` Input class pin.

#### `protected UClass * `[`GetInputOperatorClass`](#classUK2Node__FactorUnit_1a953580996631360f7c72490691bdf174)`(const UEdGraphPin * FromPin) const` <a id="classUK2Node__FactorUnit_1a953580996631360f7c72490691bdf174"></a>

Determines the input operator class type from the given pin.

#### Parameters
* `FromPin` Input class pin.

#### `protected void `[`CreateNewPins`](#classUK2Node__FactorUnit_1a8039ee6de899d3d23f9ec5d816a80d15)`(UClass * InClass,bool bOuputPin)` <a id="classUK2Node__FactorUnit_1a8039ee6de899d3d23f9ec5d816a80d15"></a>

Creates the full set of pins (properties) from the given input class.

#### Parameters
* `InClass` Input class type.

#### `protected void `[`OnClassPinChanged`](#classUK2Node__FactorUnit_1a2ab3ac66a08fc41b225743a53b460493)`()` <a id="classUK2Node__FactorUnit_1a2ab3ac66a08fc41b225743a53b460493"></a>

Will be called whenever the class pin selector changes its value.

# class `UNFactorDecorator` <a id="classUNFactorDecorator"></a>

```
class UNFactorDecorator
  : public UObject
  : public NFactorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UNFactorDecorator`](#classUNFactorDecorator_1a85c700d5382b6b57355f04d3122c8e4c)`()` | 
`public void `[`Init`](#classUNFactorDecorator_1a5c1ec700ce04c8d8f127f284af627deb)`(FName _Name,TSharedPtr< NTimelineInterface > _Timeline)` | 
`public `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * `[`CreateFactorUnit`](#classUNFactorDecorator_1aab633c751f383cf552de3fbd13e6ea00)`(const UClass * Class)` | 
`public TArray< `[`FNFactorUnitRecord`](#structFNFactorUnitRecord)` > `[`GetFactorUnitStore`](#classUNFactorDecorator_1aac4ba4dd040c4a6ce7b4051b34f10c69)`() const` | 
`public void `[`OnInit`](#classUNFactorDecorator_1a5a1301646573c17b62286b19557f7221)`()` | 
`public void `[`OnAddFactorUnit`](#classUNFactorDecorator_1ab451ec4a1814b3a9ce594ade5477ba52)`(`[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * FactorUnit,int32 key)` | 
`public void `[`OnFactorUnitExpired`](#classUNFactorDecorator_1ae37a5998d879fc76d722ff1369207df0)`(`[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * FactorUnit)` | The FactorUnit pointer is immediatly removed after this method is called.
`public virtual FName `[`GetName`](#classUNFactorDecorator_1aba3f6a0fc1b7b956d3e183c58a36fff6)`() const` | 
`public virtual float `[`GetTime`](#classUNFactorDecorator_1a1e5f17e044f128a5277b4f3d60a7dbb2)`() const` | 
`public virtual bool `[`HasStateFlag`](#classUNFactorDecorator_1aed9dd50882e13ea14e4608d11940c4f8)`(FString Flag) const` | 
`public virtual bool `[`GetStateFlag`](#classUNFactorDecorator_1a0cb6ebcb4b6b6361e2fae928a701d843)`(FString Flag) const` | 
`public virtual void `[`Debug`](#classUNFactorDecorator_1a7a7de1642931a4068df21a088b5f422d)`(bool _bDebug)` | 
`public virtual void `[`SetStateFlag`](#classUNFactorDecorator_1a0df1f19cd68399749a2995e04c8e5ac2)`(FString Flag,bool Value)` | 
`public virtual void `[`RemoveStateFlag`](#classUNFactorDecorator_1a29afe0df02753f6d227dc0f399807f72)`(FString Flag)` | 
`public virtual void `[`Clear`](#classUNFactorDecorator_1a512506f157c8492ae63b9493d3feb017)`()` | 
`public virtual void `[`SetName`](#classUNFactorDecorator_1a1e22d50f221aed52eadd6995a9668f92)`(FName _Name)` | 
`public virtual void `[`AddFlag`](#classUNFactorDecorator_1a5b74fc5bc722b995be2d68e15ffe6560)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` | 
`public virtual bool `[`HasFlag`](#classUNFactorDecorator_1a74a715688b890ae6fb5aca002a81d9fe)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag) const` | 
`public virtual void `[`RemoveFlag`](#classUNFactorDecorator_1afb62c3653327d57fdb0b65bba93e676e)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` | 
`public virtual TSharedPtr< NTimelineInterface > `[`GetTimeline`](#classUNFactorDecorator_1a084aa3d3f8f9e11b07d5f86f2c2afcb6)`() const` | 
`public virtual TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classUNFactorDecorator_1ae38da4342b5de1f4d74a6b05f26e6d92)`(uint32 Key) const` | 
`public virtual TArray< TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > > `[`GetFactors`](#classUNFactorDecorator_1a32fa9ff6f873fe213889e2e48df3441a)`() const` | 
`public virtual int32 `[`AddFactorUnit`](#classUNFactorDecorator_1a83f105577ed419d8ad4ec529cd58d1fa)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` | 
`public virtual void `[`SupplyStateWithCurrentData`](#classUNFactorDecorator_1ac47b6b12d173be3ceebd0d7da4d30364)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` | 
`public virtual void `[`Serialize`](#classUNFactorDecorator_1a3f62f9a90ff06645af714258c9b30a51)`(FArchive & Ar)` | 
`public virtual void `[`BeginDestroy`](#classUNFactorDecorator_1ade932b7be1ebc06e7df16684fb7a4e28)`()` | 
`protected TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > `[`Factor`](#classUNFactorDecorator_1ad611257e3120b1fe77c201d4208f49ef) | 
`protected TArray< `[`FNFactorUnitRecord`](#structFNFactorUnitRecord)` > `[`FactorUnitStore`](#classUNFactorDecorator_1a29eb11d3180482f0300946354d0f06ce) | 
`protected FName `[`SavedName`](#classUNFactorDecorator_1a9ae6a6ada9ca0eb6b6ca6333d583048a) | 
`protected UNTimelineDecorator * `[`GetUnrealTimeline`](#classUNFactorDecorator_1adcd125451de174c9cc6fa67c9d52e84f)`()` | 
`protected void `[`OnTimelineEventExpired`](#classUNFactorDecorator_1a75801cce123355d679d6ba3791003d6b)`(TSharedPtr< NEventInterface > Event,const float & ExpiredTime,const int32 & Index)` | 

## Members

#### `public inline  `[`UNFactorDecorator`](#classUNFactorDecorator_1a85c700d5382b6b57355f04d3122c8e4c)`()` <a id="classUNFactorDecorator_1a85c700d5382b6b57355f04d3122c8e4c"></a>

#### `public void `[`Init`](#classUNFactorDecorator_1a5c1ec700ce04c8d8f127f284af627deb)`(FName _Name,TSharedPtr< NTimelineInterface > _Timeline)` <a id="classUNFactorDecorator_1a5c1ec700ce04c8d8f127f284af627deb"></a>

#### `public `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * `[`CreateFactorUnit`](#classUNFactorDecorator_1aab633c751f383cf552de3fbd13e6ea00)`(const UClass * Class)` <a id="classUNFactorDecorator_1aab633c751f383cf552de3fbd13e6ea00"></a>

#### `public TArray< `[`FNFactorUnitRecord`](#structFNFactorUnitRecord)` > `[`GetFactorUnitStore`](#classUNFactorDecorator_1aac4ba4dd040c4a6ce7b4051b34f10c69)`() const` <a id="classUNFactorDecorator_1aac4ba4dd040c4a6ce7b4051b34f10c69"></a>

#### `public void `[`OnInit`](#classUNFactorDecorator_1a5a1301646573c17b62286b19557f7221)`()` <a id="classUNFactorDecorator_1a5a1301646573c17b62286b19557f7221"></a>

#### `public void `[`OnAddFactorUnit`](#classUNFactorDecorator_1ab451ec4a1814b3a9ce594ade5477ba52)`(`[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * FactorUnit,int32 key)` <a id="classUNFactorDecorator_1ab451ec4a1814b3a9ce594ade5477ba52"></a>

#### `public void `[`OnFactorUnitExpired`](#classUNFactorDecorator_1ae37a5998d879fc76d722ff1369207df0)`(`[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * FactorUnit)` <a id="classUNFactorDecorator_1ae37a5998d879fc76d722ff1369207df0"></a>

The FactorUnit pointer is immediatly removed after this method is called.

#### Parameters
* `FactorUnit` - A pointer to a factorUnit which end its lifetime.

#### `public virtual FName `[`GetName`](#classUNFactorDecorator_1aba3f6a0fc1b7b956d3e183c58a36fff6)`() const` <a id="classUNFactorDecorator_1aba3f6a0fc1b7b956d3e183c58a36fff6"></a>

#### `public virtual float `[`GetTime`](#classUNFactorDecorator_1a1e5f17e044f128a5277b4f3d60a7dbb2)`() const` <a id="classUNFactorDecorator_1a1e5f17e044f128a5277b4f3d60a7dbb2"></a>

#### `public virtual bool `[`HasStateFlag`](#classUNFactorDecorator_1aed9dd50882e13ea14e4608d11940c4f8)`(FString Flag) const` <a id="classUNFactorDecorator_1aed9dd50882e13ea14e4608d11940c4f8"></a>

#### `public virtual bool `[`GetStateFlag`](#classUNFactorDecorator_1a0cb6ebcb4b6b6361e2fae928a701d843)`(FString Flag) const` <a id="classUNFactorDecorator_1a0cb6ebcb4b6b6361e2fae928a701d843"></a>

#### `public virtual void `[`Debug`](#classUNFactorDecorator_1a7a7de1642931a4068df21a088b5f422d)`(bool _bDebug)` <a id="classUNFactorDecorator_1a7a7de1642931a4068df21a088b5f422d"></a>

#### `public virtual void `[`SetStateFlag`](#classUNFactorDecorator_1a0df1f19cd68399749a2995e04c8e5ac2)`(FString Flag,bool Value)` <a id="classUNFactorDecorator_1a0df1f19cd68399749a2995e04c8e5ac2"></a>

#### `public virtual void `[`RemoveStateFlag`](#classUNFactorDecorator_1a29afe0df02753f6d227dc0f399807f72)`(FString Flag)` <a id="classUNFactorDecorator_1a29afe0df02753f6d227dc0f399807f72"></a>

#### `public virtual void `[`Clear`](#classUNFactorDecorator_1a512506f157c8492ae63b9493d3feb017)`()` <a id="classUNFactorDecorator_1a512506f157c8492ae63b9493d3feb017"></a>

#### `public virtual void `[`SetName`](#classUNFactorDecorator_1a1e22d50f221aed52eadd6995a9668f92)`(FName _Name)` <a id="classUNFactorDecorator_1a1e22d50f221aed52eadd6995a9668f92"></a>

#### `public virtual void `[`AddFlag`](#classUNFactorDecorator_1a5b74fc5bc722b995be2d68e15ffe6560)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` <a id="classUNFactorDecorator_1a5b74fc5bc722b995be2d68e15ffe6560"></a>

#### `public virtual bool `[`HasFlag`](#classUNFactorDecorator_1a74a715688b890ae6fb5aca002a81d9fe)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag) const` <a id="classUNFactorDecorator_1a74a715688b890ae6fb5aca002a81d9fe"></a>

#### `public virtual void `[`RemoveFlag`](#classUNFactorDecorator_1afb62c3653327d57fdb0b65bba93e676e)`(`[`ENFactorFlag`](#FactorInterface_8h_1a5d036ca1b6eabfb89b51cbedcf9223fe)` Flag)` <a id="classUNFactorDecorator_1afb62c3653327d57fdb0b65bba93e676e"></a>

#### `public virtual TSharedPtr< NTimelineInterface > `[`GetTimeline`](#classUNFactorDecorator_1a084aa3d3f8f9e11b07d5f86f2c2afcb6)`() const` <a id="classUNFactorDecorator_1a084aa3d3f8f9e11b07d5f86f2c2afcb6"></a>

#### `public virtual TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classUNFactorDecorator_1ae38da4342b5de1f4d74a6b05f26e6d92)`(uint32 Key) const` <a id="classUNFactorDecorator_1ae38da4342b5de1f4d74a6b05f26e6d92"></a>

#### `public virtual TArray< TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > > `[`GetFactors`](#classUNFactorDecorator_1a32fa9ff6f873fe213889e2e48df3441a)`() const` <a id="classUNFactorDecorator_1a32fa9ff6f873fe213889e2e48df3441a"></a>

#### `public virtual int32 `[`AddFactorUnit`](#classUNFactorDecorator_1a83f105577ed419d8ad4ec529cd58d1fa)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` <a id="classUNFactorDecorator_1a83f105577ed419d8ad4ec529cd58d1fa"></a>

#### `public virtual void `[`SupplyStateWithCurrentData`](#classUNFactorDecorator_1ac47b6b12d173be3ceebd0d7da4d30364)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` <a id="classUNFactorDecorator_1ac47b6b12d173be3ceebd0d7da4d30364"></a>

#### `public virtual void `[`Serialize`](#classUNFactorDecorator_1a3f62f9a90ff06645af714258c9b30a51)`(FArchive & Ar)` <a id="classUNFactorDecorator_1a3f62f9a90ff06645af714258c9b30a51"></a>

#### `public virtual void `[`BeginDestroy`](#classUNFactorDecorator_1ade932b7be1ebc06e7df16684fb7a4e28)`()` <a id="classUNFactorDecorator_1ade932b7be1ebc06e7df16684fb7a4e28"></a>

#### `protected TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > `[`Factor`](#classUNFactorDecorator_1ad611257e3120b1fe77c201d4208f49ef) <a id="classUNFactorDecorator_1ad611257e3120b1fe77c201d4208f49ef"></a>

#### `protected TArray< `[`FNFactorUnitRecord`](#structFNFactorUnitRecord)` > `[`FactorUnitStore`](#classUNFactorDecorator_1a29eb11d3180482f0300946354d0f06ce) <a id="classUNFactorDecorator_1a29eb11d3180482f0300946354d0f06ce"></a>

#### `protected FName `[`SavedName`](#classUNFactorDecorator_1a9ae6a6ada9ca0eb6b6ca6333d583048a) <a id="classUNFactorDecorator_1a9ae6a6ada9ca0eb6b6ca6333d583048a"></a>

#### `protected UNTimelineDecorator * `[`GetUnrealTimeline`](#classUNFactorDecorator_1adcd125451de174c9cc6fa67c9d52e84f)`()` <a id="classUNFactorDecorator_1adcd125451de174c9cc6fa67c9d52e84f"></a>

#### `protected void `[`OnTimelineEventExpired`](#classUNFactorDecorator_1a75801cce123355d679d6ba3791003d6b)`(TSharedPtr< NEventInterface > Event,const float & ExpiredTime,const int32 & Index)` <a id="classUNFactorDecorator_1a75801cce123355d679d6ba3791003d6b"></a>

# class `UNFactorsFactoryBlueprintHelpers` <a id="classUNFactorsFactoryBlueprintHelpers"></a>

```
class UNFactorsFactoryBlueprintHelpers
  : public UBlueprintFunctionLibrary
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNFactorsFactoryClientAdapter` <a id="classUNFactorsFactoryClientAdapter"></a>

```
class UNFactorsFactoryClientAdapter
  : public UObject
  : public NFactorsFactoryClientInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter_1a9c56d9300d9ca48e9b5e8dd8456a1677)`()` | 
`public virtual void `[`Init`](#classUNFactorsFactoryClientAdapter_1ae232af08c5f91d5a428d09036e845c05)`()` | 
`public `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * `[`CreateFactorUnit`](#classUNFactorsFactoryClientAdapter_1a3044c3e0bb891a767378ed0a51a51bb3)`(const FName & FactorName,const UClass * Class)` | 
`public virtual void `[`CreateFactor`](#classUNFactorsFactoryClientAdapter_1a0167c59b39e43214f5738f26b046d255)`(FName FactorName,TSharedPtr< NTimelineInterface > Timeline,const UClass * FactorClass)` | 
`public virtual void `[`CreateFactor`](#classUNFactorsFactoryClientAdapter_1a5d30a363d4b3bbbf651712d9bd582f57)`(FName FactorName,TSharedPtr< NTimelineInterface > Timeline)` | 
`public virtual void `[`CreateFactor`](#classUNFactorsFactoryClientAdapter_1a00f761724f61f50c58aeba0096f33172)`(TArray< FName > FactorNames,TSharedPtr< NTimelineInterface > Timeline)` | 
`public virtual void `[`AddFactor`](#classUNFactorsFactoryClientAdapter_1a57627b4e52bfe29badcc817164a8f497)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public virtual void `[`RemoveFactor`](#classUNFactorsFactoryClientAdapter_1a35151237129ba6ff9f5574384527be28)`(FName FactorName)` | 
`public virtual void `[`GetState`](#classUNFactorsFactoryClientAdapter_1abf340f7c5b81c8d24f3a5eb2b07e9000)`(FName FactorName,`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` | 
`public virtual TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classUNFactorsFactoryClientAdapter_1afcc2a8680e36c12ee2ca0d0850fbdb67)`(TArray< FName > FactorNames,`[`NFactorStateInterface`](#classNFactorStateInterface)` * StateTemplate)` | 
`public virtual int32 `[`AddFactorUnit`](#classUNFactorsFactoryClientAdapter_1afb7be54139c7578e436e1607cc84ff47)`(FName FactorName,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` | 
`public virtual TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classUNFactorsFactoryClientAdapter_1a166371531ac797c6805989d94cfc29a7)`(FName FactorName,int32 Key)` | 
`public virtual void `[`SetDebug`](#classUNFactorsFactoryClientAdapter_1a34b21eadae82933f6f7420402b5dac3c)`(const TArray< FName > FactorNames,bool bDebug)` | 
`public virtual void `[`Serialize`](#classUNFactorsFactoryClientAdapter_1a2f064dec5e659ab6c2245478df757871)`(FArchive & Ar)` | 
`protected TSharedPtr< `[`NFactorsFactoryClientInterface`](#classNFactorsFactoryClientInterface)` > `[`Client`](#classUNFactorsFactoryClientAdapter_1a4c52e7da9a9094caaf10686dd2a5e6cc) | 
`protected TMap< FName, `[`UNFactorDecorator`](#classUNFactorDecorator)` * > `[`UEFactors`](#classUNFactorsFactoryClientAdapter_1a8276710d261dcba361d6e156f7750399) | 
`protected TArray< FName > `[`UEFactorsNames`](#classUNFactorsFactoryClientAdapter_1a33e62737840d00dde90ef919e9b91bf7) | This parameter is usefull only for serialization, it allows to keep the same factor list order for save & load to maintain data serialization's order consistency.

## Members

#### `public  `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter_1a9c56d9300d9ca48e9b5e8dd8456a1677)`()` <a id="classUNFactorsFactoryClientAdapter_1a9c56d9300d9ca48e9b5e8dd8456a1677"></a>

#### `public virtual void `[`Init`](#classUNFactorsFactoryClientAdapter_1ae232af08c5f91d5a428d09036e845c05)`()` <a id="classUNFactorsFactoryClientAdapter_1ae232af08c5f91d5a428d09036e845c05"></a>

#### `public `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * `[`CreateFactorUnit`](#classUNFactorsFactoryClientAdapter_1a3044c3e0bb891a767378ed0a51a51bb3)`(const FName & FactorName,const UClass * Class)` <a id="classUNFactorsFactoryClientAdapter_1a3044c3e0bb891a767378ed0a51a51bb3"></a>

#### `public virtual void `[`CreateFactor`](#classUNFactorsFactoryClientAdapter_1a0167c59b39e43214f5738f26b046d255)`(FName FactorName,TSharedPtr< NTimelineInterface > Timeline,const UClass * FactorClass)` <a id="classUNFactorsFactoryClientAdapter_1a0167c59b39e43214f5738f26b046d255"></a>

#### `public virtual void `[`CreateFactor`](#classUNFactorsFactoryClientAdapter_1a5d30a363d4b3bbbf651712d9bd582f57)`(FName FactorName,TSharedPtr< NTimelineInterface > Timeline)` <a id="classUNFactorsFactoryClientAdapter_1a5d30a363d4b3bbbf651712d9bd582f57"></a>

#### `public virtual void `[`CreateFactor`](#classUNFactorsFactoryClientAdapter_1a00f761724f61f50c58aeba0096f33172)`(TArray< FName > FactorNames,TSharedPtr< NTimelineInterface > Timeline)` <a id="classUNFactorsFactoryClientAdapter_1a00f761724f61f50c58aeba0096f33172"></a>

#### `public virtual void `[`AddFactor`](#classUNFactorsFactoryClientAdapter_1a57627b4e52bfe29badcc817164a8f497)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classUNFactorsFactoryClientAdapter_1a57627b4e52bfe29badcc817164a8f497"></a>

#### `public virtual void `[`RemoveFactor`](#classUNFactorsFactoryClientAdapter_1a35151237129ba6ff9f5574384527be28)`(FName FactorName)` <a id="classUNFactorsFactoryClientAdapter_1a35151237129ba6ff9f5574384527be28"></a>

#### `public virtual void `[`GetState`](#classUNFactorsFactoryClientAdapter_1abf340f7c5b81c8d24f3a5eb2b07e9000)`(FName FactorName,`[`NFactorStateInterface`](#classNFactorStateInterface)` & State)` <a id="classUNFactorsFactoryClientAdapter_1abf340f7c5b81c8d24f3a5eb2b07e9000"></a>

#### `public virtual TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classUNFactorsFactoryClientAdapter_1afcc2a8680e36c12ee2ca0d0850fbdb67)`(TArray< FName > FactorNames,`[`NFactorStateInterface`](#classNFactorStateInterface)` * StateTemplate)` <a id="classUNFactorsFactoryClientAdapter_1afcc2a8680e36c12ee2ca0d0850fbdb67"></a>

#### `public virtual int32 `[`AddFactorUnit`](#classUNFactorsFactoryClientAdapter_1afb7be54139c7578e436e1607cc84ff47)`(FName FactorName,TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > FactorUnit)` <a id="classUNFactorsFactoryClientAdapter_1afb7be54139c7578e436e1607cc84ff47"></a>

#### `public virtual TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`GetFactorUnit`](#classUNFactorsFactoryClientAdapter_1a166371531ac797c6805989d94cfc29a7)`(FName FactorName,int32 Key)` <a id="classUNFactorsFactoryClientAdapter_1a166371531ac797c6805989d94cfc29a7"></a>

#### `public virtual void `[`SetDebug`](#classUNFactorsFactoryClientAdapter_1a34b21eadae82933f6f7420402b5dac3c)`(const TArray< FName > FactorNames,bool bDebug)` <a id="classUNFactorsFactoryClientAdapter_1a34b21eadae82933f6f7420402b5dac3c"></a>

#### `public virtual void `[`Serialize`](#classUNFactorsFactoryClientAdapter_1a2f064dec5e659ab6c2245478df757871)`(FArchive & Ar)` <a id="classUNFactorsFactoryClientAdapter_1a2f064dec5e659ab6c2245478df757871"></a>

#### `protected TSharedPtr< `[`NFactorsFactoryClientInterface`](#classNFactorsFactoryClientInterface)` > `[`Client`](#classUNFactorsFactoryClientAdapter_1a4c52e7da9a9094caaf10686dd2a5e6cc) <a id="classUNFactorsFactoryClientAdapter_1a4c52e7da9a9094caaf10686dd2a5e6cc"></a>

#### `protected TMap< FName, `[`UNFactorDecorator`](#classUNFactorDecorator)` * > `[`UEFactors`](#classUNFactorsFactoryClientAdapter_1a8276710d261dcba361d6e156f7750399) <a id="classUNFactorsFactoryClientAdapter_1a8276710d261dcba361d6e156f7750399"></a>

#### `protected TArray< FName > `[`UEFactorsNames`](#classUNFactorsFactoryClientAdapter_1a33e62737840d00dde90ef919e9b91bf7) <a id="classUNFactorsFactoryClientAdapter_1a33e62737840d00dde90ef919e9b91bf7"></a>

This parameter is usefull only for serialization, it allows to keep the same factor list order for save & load to maintain data serialization's order consistency.

# class `UNFactorsFactoryGameInstance` <a id="classUNFactorsFactoryGameInstance"></a>

```
class UNFactorsFactoryGameInstance
  : public UInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNFactorUnitAdapter` <a id="classUNFactorUnitAdapter"></a>

```
class UNFactorUnitAdapter
  : public UObject
  : public NFactorUnitInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TSubclassOf< UNEventDecorator > `[`EventClass`](#classUNFactorUnitAdapter_1aceb16963ee911a4cb65b87d052ea1c30) | 
`public float `[`FactorUnitValue`](#classUNFactorUnitAdapter_1a6418185406b8b979ee8183e27490a235) | 
`public float `[`Duration`](#classUNFactorUnitAdapter_1aa2602d924e5c3a6ba5d27530c81fce1f) | 
`public float `[`Delay`](#classUNFactorUnitAdapter_1a3482448a4d225e1c7d6d002121b22c18) | 
`public FName `[`Reason`](#classUNFactorUnitAdapter_1a3f8df5827a4e4ff0ff1b3a62e49d9a45) | 
`public `[`UNOperatorProviderBase`](#classUNOperatorProviderBase)` * `[`OperatorProvider`](#classUNFactorUnitAdapter_1a571183a813ae3329956ad49bd27b3117) | 
`public inline  `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter_1a0902ad27ee68823011b6e586b5a0e6c4)`()` | 
`public virtual void `[`SetOperatorProvider`](#classUNFactorUnitAdapter_1ac371e1f21a2be4b83993555a5f2f6836)`(`[`UNOperatorProviderBase`](#classUNOperatorProviderBase)` * _OperatorProvider)` | 
`public virtual void `[`Init`](#classUNFactorUnitAdapter_1a1eff4f070ed57ddce68d0f898ee49eb2)`()` | 
`public virtual void `[`Init`](#classUNFactorUnitAdapter_1ab3dc4c826fc9fef24fc15ccdc595f228)`(UNEventDecorator * _Event)` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetConfiguredOperator`](#classUNFactorUnitAdapter_1a925a3f182e71ca3be110b86aa35499ac)`()` | 
`public virtual UNEventDecorator * `[`GetEventDecorator`](#classUNFactorUnitAdapter_1acda6a68b727947cd068d79b332b04d86)`()` | 
`public virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classUNFactorUnitAdapter_1a0b545d4574d049c209b1f96a03e72b05)`()` | 
`public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classUNFactorUnitAdapter_1aa05dbd64709c29c837d41a8d99bd93f5)`() const` | 
`public virtual void `[`SetOperator`](#classUNFactorUnitAdapter_1aeec48f6e58b83fb7d76319b0b60d2008)`(TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator)` | 
`public virtual float `[`GetFactorUnitValue`](#classUNFactorUnitAdapter_1ad0cf79ecd4e172ed9974cee83ee226e5)`() const` | 
`public virtual FName `[`GetReason`](#classUNFactorUnitAdapter_1ad0229fc149af8303d4b639f44298f4d7)`() const` | 
`public virtual bool `[`IsActivated`](#classUNFactorUnitAdapter_1a33139b699abf02f5e41bb3b5a39f43b4)`() const` | 
`public virtual void `[`SetFactorUnitValue`](#classUNFactorUnitAdapter_1a40c5bccf4f4aded0069f8db52747ffad)`(float _Value)` | 
`public virtual const FString `[`GetUID`](#classUNFactorUnitAdapter_1a671caeae42c9f9615eec495f36f16cc1)`() const` | 
`public virtual void `[`Activate`](#classUNFactorUnitAdapter_1a1ff46f054c4b746a6f7d6cdc0f7c4ab7)`(bool _bIsActivated)` | 
`public virtual void `[`Serialize`](#classUNFactorUnitAdapter_1a6a9e7d8f7f7cc8d857d9f08033e6d91d)`(FArchive & Ar)` | 
`protected TSharedPtr< `[`NFactorUnit`](#classNFactorUnit)` > `[`FactorUnit`](#classUNFactorUnitAdapter_1a5f74f8c2a4e4a283793e5516ab23c275) | 
`protected UNEventDecorator * `[`Event`](#classUNFactorUnitAdapter_1ae740964b60366a596c3b202bde715952) | 

## Members

#### `public TSubclassOf< UNEventDecorator > `[`EventClass`](#classUNFactorUnitAdapter_1aceb16963ee911a4cb65b87d052ea1c30) <a id="classUNFactorUnitAdapter_1aceb16963ee911a4cb65b87d052ea1c30"></a>

#### `public float `[`FactorUnitValue`](#classUNFactorUnitAdapter_1a6418185406b8b979ee8183e27490a235) <a id="classUNFactorUnitAdapter_1a6418185406b8b979ee8183e27490a235"></a>

#### `public float `[`Duration`](#classUNFactorUnitAdapter_1aa2602d924e5c3a6ba5d27530c81fce1f) <a id="classUNFactorUnitAdapter_1aa2602d924e5c3a6ba5d27530c81fce1f"></a>

#### `public float `[`Delay`](#classUNFactorUnitAdapter_1a3482448a4d225e1c7d6d002121b22c18) <a id="classUNFactorUnitAdapter_1a3482448a4d225e1c7d6d002121b22c18"></a>

#### `public FName `[`Reason`](#classUNFactorUnitAdapter_1a3f8df5827a4e4ff0ff1b3a62e49d9a45) <a id="classUNFactorUnitAdapter_1a3f8df5827a4e4ff0ff1b3a62e49d9a45"></a>

#### `public `[`UNOperatorProviderBase`](#classUNOperatorProviderBase)` * `[`OperatorProvider`](#classUNFactorUnitAdapter_1a571183a813ae3329956ad49bd27b3117) <a id="classUNFactorUnitAdapter_1a571183a813ae3329956ad49bd27b3117"></a>

#### `public inline  `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter_1a0902ad27ee68823011b6e586b5a0e6c4)`()` <a id="classUNFactorUnitAdapter_1a0902ad27ee68823011b6e586b5a0e6c4"></a>

#### `public virtual void `[`SetOperatorProvider`](#classUNFactorUnitAdapter_1ac371e1f21a2be4b83993555a5f2f6836)`(`[`UNOperatorProviderBase`](#classUNOperatorProviderBase)` * _OperatorProvider)` <a id="classUNFactorUnitAdapter_1ac371e1f21a2be4b83993555a5f2f6836"></a>

#### `public virtual void `[`Init`](#classUNFactorUnitAdapter_1a1eff4f070ed57ddce68d0f898ee49eb2)`()` <a id="classUNFactorUnitAdapter_1a1eff4f070ed57ddce68d0f898ee49eb2"></a>

#### `public virtual void `[`Init`](#classUNFactorUnitAdapter_1ab3dc4c826fc9fef24fc15ccdc595f228)`(UNEventDecorator * _Event)` <a id="classUNFactorUnitAdapter_1ab3dc4c826fc9fef24fc15ccdc595f228"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetConfiguredOperator`](#classUNFactorUnitAdapter_1a925a3f182e71ca3be110b86aa35499ac)`()` <a id="classUNFactorUnitAdapter_1a925a3f182e71ca3be110b86aa35499ac"></a>

#### `public virtual UNEventDecorator * `[`GetEventDecorator`](#classUNFactorUnitAdapter_1acda6a68b727947cd068d79b332b04d86)`()` <a id="classUNFactorUnitAdapter_1acda6a68b727947cd068d79b332b04d86"></a>

#### `public virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classUNFactorUnitAdapter_1a0b545d4574d049c209b1f96a03e72b05)`()` <a id="classUNFactorUnitAdapter_1a0b545d4574d049c209b1f96a03e72b05"></a>

#### `public virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classUNFactorUnitAdapter_1aa05dbd64709c29c837d41a8d99bd93f5)`() const` <a id="classUNFactorUnitAdapter_1aa05dbd64709c29c837d41a8d99bd93f5"></a>

#### `public virtual void `[`SetOperator`](#classUNFactorUnitAdapter_1aeec48f6e58b83fb7d76319b0b60d2008)`(TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > _Operator)` <a id="classUNFactorUnitAdapter_1aeec48f6e58b83fb7d76319b0b60d2008"></a>

#### `public virtual float `[`GetFactorUnitValue`](#classUNFactorUnitAdapter_1ad0cf79ecd4e172ed9974cee83ee226e5)`() const` <a id="classUNFactorUnitAdapter_1ad0cf79ecd4e172ed9974cee83ee226e5"></a>

#### `public virtual FName `[`GetReason`](#classUNFactorUnitAdapter_1ad0229fc149af8303d4b639f44298f4d7)`() const` <a id="classUNFactorUnitAdapter_1ad0229fc149af8303d4b639f44298f4d7"></a>

#### `public virtual bool `[`IsActivated`](#classUNFactorUnitAdapter_1a33139b699abf02f5e41bb3b5a39f43b4)`() const` <a id="classUNFactorUnitAdapter_1a33139b699abf02f5e41bb3b5a39f43b4"></a>

#### `public virtual void `[`SetFactorUnitValue`](#classUNFactorUnitAdapter_1a40c5bccf4f4aded0069f8db52747ffad)`(float _Value)` <a id="classUNFactorUnitAdapter_1a40c5bccf4f4aded0069f8db52747ffad"></a>

#### `public virtual const FString `[`GetUID`](#classUNFactorUnitAdapter_1a671caeae42c9f9615eec495f36f16cc1)`() const` <a id="classUNFactorUnitAdapter_1a671caeae42c9f9615eec495f36f16cc1"></a>

#### `public virtual void `[`Activate`](#classUNFactorUnitAdapter_1a1ff46f054c4b746a6f7d6cdc0f7c4ab7)`(bool _bIsActivated)` <a id="classUNFactorUnitAdapter_1a1ff46f054c4b746a6f7d6cdc0f7c4ab7"></a>

#### `public virtual void `[`Serialize`](#classUNFactorUnitAdapter_1a6a9e7d8f7f7cc8d857d9f08033e6d91d)`(FArchive & Ar)` <a id="classUNFactorUnitAdapter_1a6a9e7d8f7f7cc8d857d9f08033e6d91d"></a>

#### `protected TSharedPtr< `[`NFactorUnit`](#classNFactorUnit)` > `[`FactorUnit`](#classUNFactorUnitAdapter_1a5f74f8c2a4e4a283793e5516ab23c275) <a id="classUNFactorUnitAdapter_1a5f74f8c2a4e4a283793e5516ab23c275"></a>

#### `protected UNEventDecorator * `[`Event`](#classUNFactorUnitAdapter_1ae740964b60366a596c3b202bde715952) <a id="classUNFactorUnitAdapter_1ae740964b60366a596c3b202bde715952"></a>

# class `UNOperatorCleaners` <a id="classUNOperatorCleaners"></a>

```
class UNOperatorCleaners
  : public UNOperatorProviderBase
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`ENFactorCleaner`](#OperatorProviders_8h_1ab9a700a635483ac1b5ec9411cfcd361e)` `[`Type`](#classUNOperatorCleaners_1af81d115a3eaca8f2afdb2d1d36b414cf) | 
`public inline  `[`UNOperatorCleaners`](#classUNOperatorCleaners_1a78ee9e79e588ad8a89b0d414211d829d)`()` | 
`public inline virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classUNOperatorCleaners_1a662a7bd9fd2cf08ba4d41937d8d46968)`()` | 
`public inline virtual void `[`Serialize`](#classUNOperatorCleaners_1ad0f742c59dfc9a60de933e2a3e84af23)`(FArchive & Ar)` | 

## Members

#### `public `[`ENFactorCleaner`](#OperatorProviders_8h_1ab9a700a635483ac1b5ec9411cfcd361e)` `[`Type`](#classUNOperatorCleaners_1af81d115a3eaca8f2afdb2d1d36b414cf) <a id="classUNOperatorCleaners_1af81d115a3eaca8f2afdb2d1d36b414cf"></a>

#### `public inline  `[`UNOperatorCleaners`](#classUNOperatorCleaners_1a78ee9e79e588ad8a89b0d414211d829d)`()` <a id="classUNOperatorCleaners_1a78ee9e79e588ad8a89b0d414211d829d"></a>

#### `public inline virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classUNOperatorCleaners_1a662a7bd9fd2cf08ba4d41937d8d46968)`()` <a id="classUNOperatorCleaners_1a662a7bd9fd2cf08ba4d41937d8d46968"></a>

#### `public inline virtual void `[`Serialize`](#classUNOperatorCleaners_1ad0f742c59dfc9a60de933e2a3e84af23)`(FArchive & Ar)` <a id="classUNOperatorCleaners_1ad0f742c59dfc9a60de933e2a3e84af23"></a>

# class `UNOperatorProviderBase` <a id="classUNOperatorProviderBase"></a>

```
class UNOperatorProviderBase
  : public UObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classUNOperatorProviderBase_1a7817d05ffc11612cf4443d3d6c254ead) | 
`public inline  `[`UNOperatorProviderBase`](#classUNOperatorProviderBase_1afe6f702dad0c0a5a6f669cb162e1d892)`()` | 
`public inline virtual void `[`Serialize`](#classUNOperatorProviderBase_1aa821a0b64aa8a61346448816027e983f)`(FArchive & Ar)` | 

## Members

#### `public TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classUNOperatorProviderBase_1a7817d05ffc11612cf4443d3d6c254ead) <a id="classUNOperatorProviderBase_1a7817d05ffc11612cf4443d3d6c254ead"></a>

#### `public inline  `[`UNOperatorProviderBase`](#classUNOperatorProviderBase_1afe6f702dad0c0a5a6f669cb162e1d892)`()` <a id="classUNOperatorProviderBase_1afe6f702dad0c0a5a6f669cb162e1d892"></a>

#### `public inline virtual void `[`Serialize`](#classUNOperatorProviderBase_1aa821a0b64aa8a61346448816027e983f)`(FArchive & Ar)` <a id="classUNOperatorProviderBase_1aa821a0b64aa8a61346448816027e983f"></a>

# class `UNOperatorSimpleOperations` <a id="classUNOperatorSimpleOperations"></a>

```
class UNOperatorSimpleOperations
  : public UNOperatorProviderBase
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`ENFactorSimpleOperation`](#OperatorProviders_8h_1af732695b4c2077c8409ba91a35ad9891)` `[`Type`](#classUNOperatorSimpleOperations_1a4f67d2d11c7a1ba1e412c8f01eddf5c7) | 
`public inline  `[`UNOperatorSimpleOperations`](#classUNOperatorSimpleOperations_1aa8c418e1d97f38fb128a6f7c85810c52)`()` | 
`public inline virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classUNOperatorSimpleOperations_1a09bf1ecb7a7790777fd76f5c8a51a235)`()` | 
`public inline virtual void `[`Serialize`](#classUNOperatorSimpleOperations_1aff9dfeed0356a2a8ab3f5a46bfbf3e8f)`(FArchive & Ar)` | 

## Members

#### `public `[`ENFactorSimpleOperation`](#OperatorProviders_8h_1af732695b4c2077c8409ba91a35ad9891)` `[`Type`](#classUNOperatorSimpleOperations_1a4f67d2d11c7a1ba1e412c8f01eddf5c7) <a id="classUNOperatorSimpleOperations_1a4f67d2d11c7a1ba1e412c8f01eddf5c7"></a>

#### `public inline  `[`UNOperatorSimpleOperations`](#classUNOperatorSimpleOperations_1aa8c418e1d97f38fb128a6f7c85810c52)`()` <a id="classUNOperatorSimpleOperations_1aa8c418e1d97f38fb128a6f7c85810c52"></a>

#### `public inline virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classUNOperatorSimpleOperations_1a09bf1ecb7a7790777fd76f5c8a51a235)`()` <a id="classUNOperatorSimpleOperations_1a09bf1ecb7a7790777fd76f5c8a51a235"></a>

#### `public inline virtual void `[`Serialize`](#classUNOperatorSimpleOperations_1aff9dfeed0356a2a8ab3f5a46bfbf3e8f)`(FArchive & Ar)` <a id="classUNOperatorSimpleOperations_1aff9dfeed0356a2a8ab3f5a46bfbf3e8f"></a>

# class `UNResetOperatorProvider` <a id="classUNResetOperatorProvider"></a>

```
class UNResetOperatorProvider
  : public UNOperatorProviderBase
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UNResetOperatorProvider`](#classUNResetOperatorProvider_1a52546d82f27b46dd17a6439b04c0edc6)`()` | 
`public inline virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classUNResetOperatorProvider_1a1170d102f1b916ca126ef1edc264ef06)`()` | 

## Members

#### `public inline  `[`UNResetOperatorProvider`](#classUNResetOperatorProvider_1a52546d82f27b46dd17a6439b04c0edc6)`()` <a id="classUNResetOperatorProvider_1a52546d82f27b46dd17a6439b04c0edc6"></a>

#### `public inline virtual TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`GetOperator`](#classUNResetOperatorProvider_1a1170d102f1b916ca126ef1edc264ef06)`()` <a id="classUNResetOperatorProvider_1a1170d102f1b916ca126ef1edc264ef06"></a>

# struct `FFactorAttribute` <a id="structFFactorAttribute"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFFactorAttribute_1a6b224fdaa0056f61f4ce1e5229a118a9) | 
`public inline  `[`FFactorAttribute`](#structFFactorAttribute_1aab63ea5b158788a28eb6688853d03fab)`()` | 
`public inline  `[`FFactorAttribute`](#structFFactorAttribute_1a09a959a8c1dad0d0e1167a274b7a252a)`(FName _Name)` | 

## Members

#### `public FName `[`Name`](#structFFactorAttribute_1a6b224fdaa0056f61f4ce1e5229a118a9) <a id="structFFactorAttribute_1a6b224fdaa0056f61f4ce1e5229a118a9"></a>

#### `public inline  `[`FFactorAttribute`](#structFFactorAttribute_1aab63ea5b158788a28eb6688853d03fab)`()` <a id="structFFactorAttribute_1aab63ea5b158788a28eb6688853d03fab"></a>

#### `public inline  `[`FFactorAttribute`](#structFFactorAttribute_1a09a959a8c1dad0d0e1167a274b7a252a)`(FName _Name)` <a id="structFFactorAttribute_1a09a959a8c1dad0d0e1167a274b7a252a"></a>

# struct `FFactorUnitUtilities` <a id="structFFactorUnitUtilities"></a>

This utility class is made to helps the [UK2Node_FactorUnit::ExpandNode()](#classUK2Node__FactorUnit_1a2e5e0b8e6114590dc36d9fa471d0055f).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public UEdGraphNode * `[`SpawnNode`](#structFFactorUnitUtilities_1a61263a5d39e7766a48b039be4e3762c9) | 
`public class FKismetCompilerContext & `[`CompilerContext`](#structFFactorUnitUtilities_1a84f06846d875cbdd73fc06cf26189f08) | 
`public UEdGraph * `[`SourceGraph`](#structFFactorUnitUtilities_1a1fd0812051760e969a0cc710d52c8cb7) | 
`public bool `[`bDebug`](#structFFactorUnitUtilities_1af1811ac18fb32bf77c7fac4a6827cd25) | 
`public uint32 `[`DebugStep`](#structFFactorUnitUtilities_1aa8cfd023a89e8341f40153f041b1b659) | 
`public inline  `[`FFactorUnitUtilities`](#structFFactorUnitUtilities_1a238813c401b416707e6d1861506e759f)`(UEdGraphNode * _SpawnNode,class FKismetCompilerContext & _CompilerContext,UEdGraph * _SourceGraph,bool _bDebug)` | 
`public UEdGraphPin * `[`GetResultPin`](#structFFactorUnitUtilities_1a2dcb8e2bdb3db6d9c10a7670e343c04f)`() const` | 
`public bool `[`TryConnectPin`](#structFFactorUnitUtilities_1ab7cfc2aad14fdf9d4ef4379a4640a674)`(UEdGraphPin * PinA,UEdGraphPin * PinB)` | 
`public bool `[`MovePinLinks`](#structFFactorUnitUtilities_1a6fa711334050756e1e4082a1c10e5e24)`(UEdGraphPin * PinA,UEdGraphPin * PinB)` | 
`public UK2Node_CallFunction * `[`CreateUnitNode`](#structFFactorUnitUtilities_1ac23af204785597f49d0ab558f4d5edf5)`(UEdGraphPin * ClassPin,UEdGraphPin * TempFactorOutput)` | 
`public TTuple< UK2Node_CallFunction *, UK2Node_DynamicCast * > `[`CreateOperatorNode`](#structFFactorUnitUtilities_1a819c2442449d6b643b2bf39cec935bc9)`(UEdGraphPin * OperatorPin,UClass * OperatorClassType)` | 
`public UEdGraphPin * `[`ConnectPinsForObject`](#structFFactorUnitUtilities_1a14c4ea9af44fa990795f410d25513498)`(UClass * ClassType,UEdGraphPin * ObjectPin,UEdGraphPin * LastConnection,TArray< UEdGraphPin * > Pins,TArray< FName > ExcludedPinsName)` | 

## Members

#### `public UEdGraphNode * `[`SpawnNode`](#structFFactorUnitUtilities_1a61263a5d39e7766a48b039be4e3762c9) <a id="structFFactorUnitUtilities_1a61263a5d39e7766a48b039be4e3762c9"></a>

#### `public class FKismetCompilerContext & `[`CompilerContext`](#structFFactorUnitUtilities_1a84f06846d875cbdd73fc06cf26189f08) <a id="structFFactorUnitUtilities_1a84f06846d875cbdd73fc06cf26189f08"></a>

#### `public UEdGraph * `[`SourceGraph`](#structFFactorUnitUtilities_1a1fd0812051760e969a0cc710d52c8cb7) <a id="structFFactorUnitUtilities_1a1fd0812051760e969a0cc710d52c8cb7"></a>

#### `public bool `[`bDebug`](#structFFactorUnitUtilities_1af1811ac18fb32bf77c7fac4a6827cd25) <a id="structFFactorUnitUtilities_1af1811ac18fb32bf77c7fac4a6827cd25"></a>

#### `public uint32 `[`DebugStep`](#structFFactorUnitUtilities_1aa8cfd023a89e8341f40153f041b1b659) <a id="structFFactorUnitUtilities_1aa8cfd023a89e8341f40153f041b1b659"></a>

#### `public inline  `[`FFactorUnitUtilities`](#structFFactorUnitUtilities_1a238813c401b416707e6d1861506e759f)`(UEdGraphNode * _SpawnNode,class FKismetCompilerContext & _CompilerContext,UEdGraph * _SourceGraph,bool _bDebug)` <a id="structFFactorUnitUtilities_1a238813c401b416707e6d1861506e759f"></a>

#### `public UEdGraphPin * `[`GetResultPin`](#structFFactorUnitUtilities_1a2dcb8e2bdb3db6d9c10a7670e343c04f)`() const` <a id="structFFactorUnitUtilities_1a2dcb8e2bdb3db6d9c10a7670e343c04f"></a>

#### `public bool `[`TryConnectPin`](#structFFactorUnitUtilities_1ab7cfc2aad14fdf9d4ef4379a4640a674)`(UEdGraphPin * PinA,UEdGraphPin * PinB)` <a id="structFFactorUnitUtilities_1ab7cfc2aad14fdf9d4ef4379a4640a674"></a>

#### `public bool `[`MovePinLinks`](#structFFactorUnitUtilities_1a6fa711334050756e1e4082a1c10e5e24)`(UEdGraphPin * PinA,UEdGraphPin * PinB)` <a id="structFFactorUnitUtilities_1a6fa711334050756e1e4082a1c10e5e24"></a>

#### `public UK2Node_CallFunction * `[`CreateUnitNode`](#structFFactorUnitUtilities_1ac23af204785597f49d0ab558f4d5edf5)`(UEdGraphPin * ClassPin,UEdGraphPin * TempFactorOutput)` <a id="structFFactorUnitUtilities_1ac23af204785597f49d0ab558f4d5edf5"></a>

#### `public TTuple< UK2Node_CallFunction *, UK2Node_DynamicCast * > `[`CreateOperatorNode`](#structFFactorUnitUtilities_1a819c2442449d6b643b2bf39cec935bc9)`(UEdGraphPin * OperatorPin,UClass * OperatorClassType)` <a id="structFFactorUnitUtilities_1a819c2442449d6b643b2bf39cec935bc9"></a>

#### `public UEdGraphPin * `[`ConnectPinsForObject`](#structFFactorUnitUtilities_1a14c4ea9af44fa990795f410d25513498)`(UClass * ClassType,UEdGraphPin * ObjectPin,UEdGraphPin * LastConnection,TArray< UEdGraphPin * > Pins,TArray< FName > ExcludedPinsName)` <a id="structFFactorUnitUtilities_1a14c4ea9af44fa990795f410d25513498"></a>

# struct `FNFactorSettings` <a id="structFNFactorSettings"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFNFactorSettings_1acedd2d410195b0d363964dc2bc1e2e8c) | 
`public TSubclassOf< `[`UNFactorDecorator`](#classUNFactorDecorator)` > `[`FactorClass`](#structFNFactorSettings_1aa2a9d6fcfd712d1df3d4239fd7a5a5b5) | 
`public FConfiguredTimeline `[`Timeline`](#structFNFactorSettings_1a18510d42fc3456d34b424a5b284a046b) | 

## Members

#### `public FName `[`Name`](#structFNFactorSettings_1acedd2d410195b0d363964dc2bc1e2e8c) <a id="structFNFactorSettings_1acedd2d410195b0d363964dc2bc1e2e8c"></a>

#### `public TSubclassOf< `[`UNFactorDecorator`](#classUNFactorDecorator)` > `[`FactorClass`](#structFNFactorSettings_1aa2a9d6fcfd712d1df3d4239fd7a5a5b5) <a id="structFNFactorSettings_1aa2a9d6fcfd712d1df3d4239fd7a5a5b5"></a>

#### `public FConfiguredTimeline `[`Timeline`](#structFNFactorSettings_1a18510d42fc3456d34b424a5b284a046b) <a id="structFNFactorSettings_1a18510d42fc3456d34b424a5b284a046b"></a>

# struct `FNFactorStateOperator` <a id="structFNFactorStateOperator"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`FactorUnit`](#structFNFactorStateOperator_1a5e246925b78e8c3652438f557a93ae0d) | 
`public float `[`Value`](#structFNFactorStateOperator_1a3de7a16e2324002ed5f48741c69bc8fe) | 
`public FName `[`Reason`](#structFNFactorStateOperator_1af8c21a16835a0f2ab9cd94c48454824f) | 
`public bool `[`Activate`](#structFNFactorStateOperator_1af2d735e5c96ee54b8f90a30aa5213485) | 
`public TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`Operator`](#structFNFactorStateOperator_1afa8c48d3e7d92e0bb881733a15f6c9f3) | 
`public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1a62b4b9fcc006a27ce02977be4e0e066d)`()` | 
`public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1ad161fe43eadd89f4c9e9e000c80dd0b4)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > _FactorUnit)` | 

## Members

#### `public TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > `[`FactorUnit`](#structFNFactorStateOperator_1a5e246925b78e8c3652438f557a93ae0d) <a id="structFNFactorStateOperator_1a5e246925b78e8c3652438f557a93ae0d"></a>

#### `public float `[`Value`](#structFNFactorStateOperator_1a3de7a16e2324002ed5f48741c69bc8fe) <a id="structFNFactorStateOperator_1a3de7a16e2324002ed5f48741c69bc8fe"></a>

#### `public FName `[`Reason`](#structFNFactorStateOperator_1af8c21a16835a0f2ab9cd94c48454824f) <a id="structFNFactorStateOperator_1af8c21a16835a0f2ab9cd94c48454824f"></a>

#### `public bool `[`Activate`](#structFNFactorStateOperator_1af2d735e5c96ee54b8f90a30aa5213485) <a id="structFNFactorStateOperator_1af2d735e5c96ee54b8f90a30aa5213485"></a>

#### `public TSharedPtr< `[`NFactorOperatorInterface`](#classNFactorOperatorInterface)` > `[`Operator`](#structFNFactorStateOperator_1afa8c48d3e7d92e0bb881733a15f6c9f3) <a id="structFNFactorStateOperator_1afa8c48d3e7d92e0bb881733a15f6c9f3"></a>

#### `public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1a62b4b9fcc006a27ce02977be4e0e066d)`()` <a id="structFNFactorStateOperator_1a62b4b9fcc006a27ce02977be4e0e066d"></a>

#### `public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1ad161fe43eadd89f4c9e9e000c80dd0b4)`(TSharedPtr< `[`NFactorUnitInterface`](#classNFactorUnitInterface)` > _FactorUnit)` <a id="structFNFactorStateOperator_1ad161fe43eadd89f4c9e9e000c80dd0b4"></a>

# struct `FNFactorStateResult` <a id="structFNFactorStateResult"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`Amount`](#structFNFactorStateResult_1a24593c18df58e4fc6fa8146a5501d505) | 
`public TArray< FName > `[`Reasons`](#structFNFactorStateResult_1ae0e8fb1f6a8c43fe19f52ae049c04ffb) | 
`public float `[`Time`](#structFNFactorStateResult_1ad3425662aab745ca086e496fbe9e0392) | 
`public inline  `[`FNFactorStateResult`](#structFNFactorStateResult_1a6ec4cdb54c12cc6fece004fdf838224f)`()` | 
`public inline  `[`FNFactorStateResult`](#structFNFactorStateResult_1a853f1e443e84607884d6bb782f771f9b)`(float _Amount,TArray< FName > _Reasons,float _Time)` | 

## Members

#### `public float `[`Amount`](#structFNFactorStateResult_1a24593c18df58e4fc6fa8146a5501d505) <a id="structFNFactorStateResult_1a24593c18df58e4fc6fa8146a5501d505"></a>

#### `public TArray< FName > `[`Reasons`](#structFNFactorStateResult_1ae0e8fb1f6a8c43fe19f52ae049c04ffb) <a id="structFNFactorStateResult_1ae0e8fb1f6a8c43fe19f52ae049c04ffb"></a>

#### `public float `[`Time`](#structFNFactorStateResult_1ad3425662aab745ca086e496fbe9e0392) <a id="structFNFactorStateResult_1ad3425662aab745ca086e496fbe9e0392"></a>

#### `public inline  `[`FNFactorStateResult`](#structFNFactorStateResult_1a6ec4cdb54c12cc6fece004fdf838224f)`()` <a id="structFNFactorStateResult_1a6ec4cdb54c12cc6fece004fdf838224f"></a>

#### `public inline  `[`FNFactorStateResult`](#structFNFactorStateResult_1a853f1e443e84607884d6bb782f771f9b)`(float _Amount,TArray< FName > _Reasons,float _Time)` <a id="structFNFactorStateResult_1a853f1e443e84607884d6bb782f771f9b"></a>

# struct `FNFactorUnitRecord` <a id="structFNFactorUnitRecord"></a>

This struct is a record object used for savegame or get user feedbacks

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * `[`FactorUnit`](#structFNFactorUnitRecord_1ad53484c42e49e1e69d1ae8511a2f3178) | The [UNFactorUnitAdapter](#classUNFactorUnitAdapter) object
`public FString `[`UId`](#structFNFactorUnitRecord_1ab3be1f965e8b55590060263dbfdca863) | The time it as been attached to the timeline in secs (differ to UNEventDecorator::StartedAt)
`public FName `[`OperatorName`](#structFNFactorUnitRecord_1a5bf65e78fc8a54be2a609f49bc5eccbe) | This value to keep trace of what happens, usefull for
`public float `[`Value`](#structFNFactorUnitRecord_1a260fbb276a68c4bea47ea0a54b7ed7b1) | 
`public FString `[`FactorUnitClassName`](#structFNFactorUnitRecord_1abc631e7c68cbcfa89e098acc3dba8890) | This is used only during serialization, it allow to re-instance the object on load
`public FString `[`OperatorProviderClassName`](#structFNFactorUnitRecord_1a852abc3517932d6df6c7b0ddf4693ed2) | 
`public inline  `[`FNFactorUnitRecord`](#structFNFactorUnitRecord_1ae7b81168f939b8912d738a401c9a33ea)`()` | 
`public inline  `[`FNFactorUnitRecord`](#structFNFactorUnitRecord_1a458a5e603b20902a509585d3e7b755f1)`(`[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * _FactorUnit)` | 
`public FNEventRecord & `[`GetEventRecord`](#structFNFactorUnitRecord_1a36ca58a43518b0575caff9763a5956c3)`(`[`UNFactorDecorator`](#classUNFactorDecorator)` * Factor)` | 
`public void `[`Serialize`](#structFNFactorUnitRecord_1a736256bf3c2237c02820856dee769b6e)`(FArchive & Ar,`[`UNFactorDecorator`](#classUNFactorDecorator)` * Factor)` | It manages Event object saving and loading

## Members

#### `public `[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * `[`FactorUnit`](#structFNFactorUnitRecord_1ad53484c42e49e1e69d1ae8511a2f3178) <a id="structFNFactorUnitRecord_1ad53484c42e49e1e69d1ae8511a2f3178"></a>

The [UNFactorUnitAdapter](#classUNFactorUnitAdapter) object

#### `public FString `[`UId`](#structFNFactorUnitRecord_1ab3be1f965e8b55590060263dbfdca863) <a id="structFNFactorUnitRecord_1ab3be1f965e8b55590060263dbfdca863"></a>

The time it as been attached to the timeline in secs (differ to UNEventDecorator::StartedAt)

#### `public FName `[`OperatorName`](#structFNFactorUnitRecord_1a5bf65e78fc8a54be2a609f49bc5eccbe) <a id="structFNFactorUnitRecord_1a5bf65e78fc8a54be2a609f49bc5eccbe"></a>

This value to keep trace of what happens, usefull for

#### `public float `[`Value`](#structFNFactorUnitRecord_1a260fbb276a68c4bea47ea0a54b7ed7b1) <a id="structFNFactorUnitRecord_1a260fbb276a68c4bea47ea0a54b7ed7b1"></a>

#### `public FString `[`FactorUnitClassName`](#structFNFactorUnitRecord_1abc631e7c68cbcfa89e098acc3dba8890) <a id="structFNFactorUnitRecord_1abc631e7c68cbcfa89e098acc3dba8890"></a>

This is used only during serialization, it allow to re-instance the object on load

#### `public FString `[`OperatorProviderClassName`](#structFNFactorUnitRecord_1a852abc3517932d6df6c7b0ddf4693ed2) <a id="structFNFactorUnitRecord_1a852abc3517932d6df6c7b0ddf4693ed2"></a>

#### `public inline  `[`FNFactorUnitRecord`](#structFNFactorUnitRecord_1ae7b81168f939b8912d738a401c9a33ea)`()` <a id="structFNFactorUnitRecord_1ae7b81168f939b8912d738a401c9a33ea"></a>

#### `public inline  `[`FNFactorUnitRecord`](#structFNFactorUnitRecord_1a458a5e603b20902a509585d3e7b755f1)`(`[`UNFactorUnitAdapter`](#classUNFactorUnitAdapter)` * _FactorUnit)` <a id="structFNFactorUnitRecord_1a458a5e603b20902a509585d3e7b755f1"></a>

#### `public FNEventRecord & `[`GetEventRecord`](#structFNFactorUnitRecord_1a36ca58a43518b0575caff9763a5956c3)`(`[`UNFactorDecorator`](#classUNFactorDecorator)` * Factor)` <a id="structFNFactorUnitRecord_1a36ca58a43518b0575caff9763a5956c3"></a>

#### `public void `[`Serialize`](#structFNFactorUnitRecord_1a736256bf3c2237c02820856dee769b6e)`(FArchive & Ar,`[`UNFactorDecorator`](#classUNFactorDecorator)` * Factor)` <a id="structFNFactorUnitRecord_1a736256bf3c2237c02820856dee769b6e"></a>

It manages Event object saving and loading

Generated by [Moxygen](https://sourcey.com/moxygen)