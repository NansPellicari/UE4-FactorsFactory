# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`FactorOperatorInterface`](#classFactorOperatorInterface) | 
`class `[`FactorOperatorInterfaceWithStack`](#classFactorOperatorInterfaceWithStack) | 
`class `[`FakeFactorStack`](#classFakeFactorStack) | 
`class `[`FakeResetOperator`](#classFakeResetOperator) | 
`class `[`FNansFactorsFactoryCoreModule`](#classFNansFactorsFactoryCoreModule) | 
`class `[`FNansFactorsFactoryUE4Module`](#classFNansFactorsFactoryUE4Module) | 
`class `[`FNFactorSettingsPinFactory`](#classFNFactorSettingsPinFactory) | 
`class `[`INFactorsFactoryGameInstance`](#classINFactorsFactoryGameInstance) | 
`class `[`MockTimelineManager`](#classMockTimelineManager) | 
`class `[`NAddOperator`](#classNAddOperator) | 
`class `[`NansFactorsFactoryCore`](#classNansFactorsFactoryCore) | 
`class `[`NansFactorsFactoryCoreClientTest`](#classNansFactorsFactoryCoreClientTest) | 
`class `[`NansFactorsFactoryCoreFactorTest`](#classNansFactorsFactoryCoreFactorTest) | 
`class `[`NansFactorsFactoryCoreNullFactorTest`](#classNansFactorsFactoryCoreNullFactorTest) | 
`class `[`NansFactorsFactoryCoreOperatorTest`](#classNansFactorsFactoryCoreOperatorTest) | 
`class `[`NansFactorsFactoryCoreResetOperatorTest`](#classNansFactorsFactoryCoreResetOperatorTest) | 
`class `[`NansFactorsFactoryCoreStackTest`](#classNansFactorsFactoryCoreStackTest) | 
`class `[`NansFactorsFactoryCoreStateTest`](#classNansFactorsFactoryCoreStateTest) | 
`class `[`NansFactorsFactoryUE4`](#classNansFactorsFactoryUE4) | 
`class `[`NDividerOperator`](#classNDividerOperator) | 
`class `[`NFactor`](#classNFactor) | 
`class `[`NFactorEvent`](#classNFactorEvent) | 
`class `[`NFactorInterface`](#classNFactorInterface) | 
`class `[`NFactorsFactoryClient`](#classNFactorsFactoryClient) | 
`class `[`NFactorsFactoryClientInterface`](#classNFactorsFactoryClientInterface) | 
`class `[`NFactorStack`](#classNFactorStack) | 
`class `[`NFactorStackInterface`](#classNFactorStackInterface) | 
`class `[`NFactorState`](#classNFactorState) | 
`class `[`NFactorStateInterface`](#classNFactorStateInterface) | 
`class `[`NMultiplyOperator`](#classNMultiplyOperator) | 
`class `[`NNullFactorState`](#classNNullFactorState) | 
`class `[`NNullOperator`](#classNNullOperator) | 
`class `[`NResetOperator`](#classNResetOperator) | 
`class `[`NResetOperatorBase`](#classNResetOperatorBase) | 
`class `[`NSubsctractOperator`](#classNSubsctractOperator) | 
`class `[`OperatorUtils`](#classOperatorUtils) | 
`class `[`SNFactorSettingsPin`](#classSNFactorSettingsPin) | 
`class `[`UFactorFakeGameInstance`](#classUFactorFakeGameInstance) | 
`class `[`UFactorSettings`](#classUFactorSettings) | This allow to
`class `[`UK2Node_FactorOperator`](#classUK2Node__FactorOperator) | 
`class `[`UMockObject`](#classUMockObject) | 
`class `[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract) | 
`class `[`UNFactorAdapterBasic`](#classUNFactorAdapterBasic) | 
`class `[`UNFactorAdapterResetFromReason`](#classUNFactorAdapterResetFromReason) | 
`class `[`UNFactorEventDecorator`](#classUNFactorEventDecorator) | 
`class `[`UNFactorsFactoryBlueprintHelpers`](#classUNFactorsFactoryBlueprintHelpers) | 
`class `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter) | 
`class `[`UNFactorsFactoryGameInstance`](#classUNFactorsFactoryGameInstance) | 
`class `[`UNFactorStackDecorator`](#classUNFactorStackDecorator) | 
`class `[`UNFakeFactorsFactoryClient`](#classUNFakeFactorsFactoryClient) | 
`class `[`UnrealFactorProxy`](#classUnrealFactorProxy) | 
`class `[`UNUnrealFactorStackProxy`](#classUNUnrealFactorStackProxy) | 
`struct `[`FFactorStackAttribute`](#structFFactorStackAttribute) | 
`struct `[`FNFactorSettings`](#structFNFactorSettings) | 
`struct `[`FNFactorStateOperator`](#structFNFactorStateOperator) | 
`struct `[`FNFactorStateResult`](#structFNFactorStateResult) | 

# class `FactorOperatorInterface` <a id="classFactorOperatorInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`Compute`](#classFactorOperatorInterface_1ae494a3b17d2ef17c0209feb7e472db1d)`(float Lh,float Rh)` | 
`public TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classFactorOperatorInterface_1ac751aa23781d63220685d9b6cd41f6f9)`()` | 
`public const FName `[`GetName`](#classFactorOperatorInterface_1a1e8d2536b66098f7e1ddf9ac906ab55b)`()` | 

## Members

#### `public float `[`Compute`](#classFactorOperatorInterface_1ae494a3b17d2ef17c0209feb7e472db1d)`(float Lh,float Rh)` <a id="classFactorOperatorInterface_1ae494a3b17d2ef17c0209feb7e472db1d"></a>

#### `public TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classFactorOperatorInterface_1ac751aa23781d63220685d9b6cd41f6f9)`()` <a id="classFactorOperatorInterface_1ac751aa23781d63220685d9b6cd41f6f9"></a>

#### `public const FName `[`GetName`](#classFactorOperatorInterface_1a1e8d2536b66098f7e1ddf9ac906ab55b)`()` <a id="classFactorOperatorInterface_1a1e8d2536b66098f7e1ddf9ac906ab55b"></a>

# class `FactorOperatorInterfaceWithStack` <a id="classFactorOperatorInterfaceWithStack"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`SetStack`](#classFactorOperatorInterfaceWithStack_1a1d61142eb0ee24a55752b220141313d8)`(`[`NFactorStackInterface`](#classNFactorStackInterface)` * Stack)` | 
`public void `[`SetKeyInStack`](#classFactorOperatorInterfaceWithStack_1ab9ace7fd1e735be42ab59a82d278a082)`(uint32 Key)` | 

## Members

#### `public void `[`SetStack`](#classFactorOperatorInterfaceWithStack_1a1d61142eb0ee24a55752b220141313d8)`(`[`NFactorStackInterface`](#classNFactorStackInterface)` * Stack)` <a id="classFactorOperatorInterfaceWithStack_1a1d61142eb0ee24a55752b220141313d8"></a>

#### `public void `[`SetKeyInStack`](#classFactorOperatorInterfaceWithStack_1ab9ace7fd1e735be42ab59a82d278a082)`(uint32 Key)` <a id="classFactorOperatorInterfaceWithStack_1ab9ace7fd1e735be42ab59a82d278a082"></a>

# class `FakeFactorStack` <a id="classFakeFactorStack"></a>

```
class FakeFactorStack
  : public NFactorStack
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`FakeFactorStack`](#classFakeFactorStack_1a497c8e00840ed121b6d0bab0013bcfe5)`(FName _Name,TSharedPtr< NTimeline > _Timeline)` | 
`public inline virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetCurrentState`](#classFakeFactorStack_1aa14dac7d57ad704c9f528240072ebaf3)`()` | 

## Members

#### `public inline  `[`FakeFactorStack`](#classFakeFactorStack_1a497c8e00840ed121b6d0bab0013bcfe5)`(FName _Name,TSharedPtr< NTimeline > _Timeline)` <a id="classFakeFactorStack_1a497c8e00840ed121b6d0bab0013bcfe5"></a>

#### `public inline virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetCurrentState`](#classFakeFactorStack_1aa14dac7d57ad704c9f528240072ebaf3)`()` <a id="classFakeFactorStack_1aa14dac7d57ad704c9f528240072ebaf3"></a>

# class `FakeResetOperator` <a id="classFakeResetOperator"></a>

```
class FakeResetOperator
  : public NResetOperator
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline uint32 `[`GetKeyInStack`](#classFakeResetOperator_1aa5de5e076a4e6e414837d935e9a0a182)`()` | 
`public inline bool `[`HasStack`](#classFakeResetOperator_1a8b998e15002e352ae61fd4973ede179b)`()` | 

## Members

#### `public inline uint32 `[`GetKeyInStack`](#classFakeResetOperator_1aa5de5e076a4e6e414837d935e9a0a182)`()` <a id="classFakeResetOperator_1aa5de5e076a4e6e414837d935e9a0a182"></a>

#### `public inline bool `[`HasStack`](#classFakeResetOperator_1a8b998e15002e352ae61fd4973ede179b)`()` <a id="classFakeResetOperator_1a8b998e15002e352ae61fd4973ede179b"></a>

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
`public virtual `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter)` * `[`GetFactorsFactoryClient`](#classINFactorsFactoryGameInstance_1a2b28c233072fdb005682f1695ee06843)`() const` | 

## Members

#### `public virtual `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter)` * `[`GetFactorsFactoryClient`](#classINFactorsFactoryGameInstance_1a2b28c233072fdb005682f1695ee06843)`() const` <a id="classINFactorsFactoryGameInstance_1a2b28c233072fdb005682f1695ee06843"></a>

# class `MockTimelineManager` <a id="classMockTimelineManager"></a>

```
class MockTimelineManager
  : public NTimelineManager
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `NAddOperator` <a id="classNAddOperator"></a>

```
class NAddOperator
  : public FactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNAddOperator_1a5de4bacf334d15d62cc758944938dead)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNAddOperator_1aa69c6d7839ff84fcaab7156f79fc15f7)`()` | 
`public inline virtual const FName `[`GetName`](#classNAddOperator_1a53a8a7c8fb4e8f3f1787d933a05a8c4d)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNAddOperator_1a5de4bacf334d15d62cc758944938dead)`(float Lh,float Rh)` <a id="classNAddOperator_1a5de4bacf334d15d62cc758944938dead"></a>

#### `public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNAddOperator_1aa69c6d7839ff84fcaab7156f79fc15f7)`()` <a id="classNAddOperator_1aa69c6d7839ff84fcaab7156f79fc15f7"></a>

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

# class `NansFactorsFactoryCoreClientTest` <a id="classNansFactorsFactoryCoreClientTest"></a>

```
class NansFactorsFactoryCoreClientTest
  : public Test
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`protected `[`UNFakeFactorsFactoryClient`](#classUNFakeFactorsFactoryClient)` * `[`Client`](#classNansFactorsFactoryCoreClientTest_1a7015f3d4dde0465d46449b091b6ca2c9) | 
`protected TSharedPtr< NTimeline > `[`Timeline`](#classNansFactorsFactoryCoreClientTest_1a7c37f24f93384d1d655f8bd7fef2e788) | 
`protected inline void `[`SetUp`](#classNansFactorsFactoryCoreClientTest_1aa363285ab61318f1dd130b984caf8991)`()` | 
`protected inline void `[`TearDown`](#classNansFactorsFactoryCoreClientTest_1a5083cd402afaa19311e6d218d9281137)`()` | 

## Members

#### `protected `[`UNFakeFactorsFactoryClient`](#classUNFakeFactorsFactoryClient)` * `[`Client`](#classNansFactorsFactoryCoreClientTest_1a7015f3d4dde0465d46449b091b6ca2c9) <a id="classNansFactorsFactoryCoreClientTest_1a7015f3d4dde0465d46449b091b6ca2c9"></a>

#### `protected TSharedPtr< NTimeline > `[`Timeline`](#classNansFactorsFactoryCoreClientTest_1a7c37f24f93384d1d655f8bd7fef2e788) <a id="classNansFactorsFactoryCoreClientTest_1a7c37f24f93384d1d655f8bd7fef2e788"></a>

#### `protected inline void `[`SetUp`](#classNansFactorsFactoryCoreClientTest_1aa363285ab61318f1dd130b984caf8991)`()` <a id="classNansFactorsFactoryCoreClientTest_1aa363285ab61318f1dd130b984caf8991"></a>

#### `protected inline void `[`TearDown`](#classNansFactorsFactoryCoreClientTest_1a5083cd402afaa19311e6d218d9281137)`()` <a id="classNansFactorsFactoryCoreClientTest_1a5083cd402afaa19311e6d218d9281137"></a>

# class `NansFactorsFactoryCoreFactorTest` <a id="classNansFactorsFactoryCoreFactorTest"></a>

```
class NansFactorsFactoryCoreFactorTest
  : public Test
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `NansFactorsFactoryCoreNullFactorTest` <a id="classNansFactorsFactoryCoreNullFactorTest"></a>

```
class NansFactorsFactoryCoreNullFactorTest
  : public Test
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `NansFactorsFactoryCoreOperatorTest` <a id="classNansFactorsFactoryCoreOperatorTest"></a>

```
class NansFactorsFactoryCoreOperatorTest
  : public Test
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `NansFactorsFactoryCoreResetOperatorTest` <a id="classNansFactorsFactoryCoreResetOperatorTest"></a>

```
class NansFactorsFactoryCoreResetOperatorTest
  : public Test
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`protected TSharedPtr< `[`FakeFactorStack`](#classFakeFactorStack)` > `[`FactorStack`](#classNansFactorsFactoryCoreResetOperatorTest_1a1e83a2f21292f01ea6da26ddc33dd384) | 
`protected TSharedPtr< NTimeline > `[`Timeline`](#classNansFactorsFactoryCoreResetOperatorTest_1a869dbf5fc9d2cf009bc7cd50bb0b0bb6) | 
`protected inline void `[`SetUp`](#classNansFactorsFactoryCoreResetOperatorTest_1ad6bb36d7f5822aeab63bd038a8b39321)`()` | 
`protected inline void `[`TearDown`](#classNansFactorsFactoryCoreResetOperatorTest_1a3524ca6c4518ab1923b1a2b28e748287)`()` | 

## Members

#### `protected TSharedPtr< `[`FakeFactorStack`](#classFakeFactorStack)` > `[`FactorStack`](#classNansFactorsFactoryCoreResetOperatorTest_1a1e83a2f21292f01ea6da26ddc33dd384) <a id="classNansFactorsFactoryCoreResetOperatorTest_1a1e83a2f21292f01ea6da26ddc33dd384"></a>

#### `protected TSharedPtr< NTimeline > `[`Timeline`](#classNansFactorsFactoryCoreResetOperatorTest_1a869dbf5fc9d2cf009bc7cd50bb0b0bb6) <a id="classNansFactorsFactoryCoreResetOperatorTest_1a869dbf5fc9d2cf009bc7cd50bb0b0bb6"></a>

#### `protected inline void `[`SetUp`](#classNansFactorsFactoryCoreResetOperatorTest_1ad6bb36d7f5822aeab63bd038a8b39321)`()` <a id="classNansFactorsFactoryCoreResetOperatorTest_1ad6bb36d7f5822aeab63bd038a8b39321"></a>

#### `protected inline void `[`TearDown`](#classNansFactorsFactoryCoreResetOperatorTest_1a3524ca6c4518ab1923b1a2b28e748287)`()` <a id="classNansFactorsFactoryCoreResetOperatorTest_1a3524ca6c4518ab1923b1a2b28e748287"></a>

# class `NansFactorsFactoryCoreStackTest` <a id="classNansFactorsFactoryCoreStackTest"></a>

```
class NansFactorsFactoryCoreStackTest
  : public Test
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`protected TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > `[`FactorStack`](#classNansFactorsFactoryCoreStackTest_1a3fb73999d2c87dc5e57706793a73467d) | 
`protected TSharedPtr< NTimeline > `[`Timeline`](#classNansFactorsFactoryCoreStackTest_1ac2a50721bf7e06841789c5dfa770f9d8) | 
`protected inline void `[`SetUp`](#classNansFactorsFactoryCoreStackTest_1ad4b4371c0cc111b52f2232e7e5f255b5)`()` | 
`protected inline void `[`TearDown`](#classNansFactorsFactoryCoreStackTest_1acba841acf31d8f9444e4aa77dcc7604e)`()` | 

## Members

#### `protected TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > `[`FactorStack`](#classNansFactorsFactoryCoreStackTest_1a3fb73999d2c87dc5e57706793a73467d) <a id="classNansFactorsFactoryCoreStackTest_1a3fb73999d2c87dc5e57706793a73467d"></a>

#### `protected TSharedPtr< NTimeline > `[`Timeline`](#classNansFactorsFactoryCoreStackTest_1ac2a50721bf7e06841789c5dfa770f9d8) <a id="classNansFactorsFactoryCoreStackTest_1ac2a50721bf7e06841789c5dfa770f9d8"></a>

#### `protected inline void `[`SetUp`](#classNansFactorsFactoryCoreStackTest_1ad4b4371c0cc111b52f2232e7e5f255b5)`()` <a id="classNansFactorsFactoryCoreStackTest_1ad4b4371c0cc111b52f2232e7e5f255b5"></a>

#### `protected inline void `[`TearDown`](#classNansFactorsFactoryCoreStackTest_1acba841acf31d8f9444e4aa77dcc7604e)`()` <a id="classNansFactorsFactoryCoreStackTest_1acba841acf31d8f9444e4aa77dcc7604e"></a>

# class `NansFactorsFactoryCoreStateTest` <a id="classNansFactorsFactoryCoreStateTest"></a>

```
class NansFactorsFactoryCoreStateTest
  : public Test
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

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

# class `NDividerOperator` <a id="classNDividerOperator"></a>

```
class NDividerOperator
  : public FactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNDividerOperator_1aba31fb472867515a6a554ea528aee149)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNDividerOperator_1a2b0f518514c40b36d3072d45ba86fd42)`()` | 
`public inline virtual const FName `[`GetName`](#classNDividerOperator_1a22f6ea3308e67ae0c65d97f90f6dd414)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNDividerOperator_1aba31fb472867515a6a554ea528aee149)`(float Lh,float Rh)` <a id="classNDividerOperator_1aba31fb472867515a6a554ea528aee149"></a>

#### `public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNDividerOperator_1a2b0f518514c40b36d3072d45ba86fd42)`()` <a id="classNDividerOperator_1a2b0f518514c40b36d3072d45ba86fd42"></a>

#### `public inline virtual const FName `[`GetName`](#classNDividerOperator_1a22f6ea3308e67ae0c65d97f90f6dd414)`()` <a id="classNDividerOperator_1a22f6ea3308e67ae0c65d97f90f6dd414"></a>

# class `NFactor` <a id="classNFactor"></a>

```
class NFactor
  : public NFactorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NFactor`](#classNFactor_1a3aa980bfef8d6f5d3ac964b76a877bbd)`(float _FactorValue,TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > _Operator,float _Duration,FName Reason,float _Delay,TSharedPtr< NEventInterface > _Event)` | 
`public virtual  `[`~NFactor`](#classNFactor_1ad236413a6b0e2169d13e8910d1cba2e3)`()` | 
`public virtual bool `[`IsActivated`](#classNFactor_1ae4d6bf09600c7c2cb92fcd98bbce7913)`() const` | 
`public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetOperator`](#classNFactor_1a289953f31e47f72705f4c15da686e3c7)`() const` | 
`public virtual float `[`GetFactorValue`](#classNFactor_1aaa0e436924fceddb031fbe2e5828c814)`() const` | 
`public virtual FName `[`GetReason`](#classNFactor_1ae2de6106daf773494393f49c73b3dccd)`() const` | 
`public virtual uint32 `[`GetUID`](#classNFactor_1a8bac96227fe585ec0ba71ca20abde936)`() const` | 
`public virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classNFactor_1a83f07e97b488550cd4f9892e49d19f05)`()` | 
`public void `[`Activate`](#classNFactor_1a1da74e109ffc3426593685e37899da98)`(bool _bIsActivated)` | 
`protected TSharedPtr< NEventInterface > `[`Event`](#classNFactor_1a62b32140c003f599df4e16578d1fbe3d) | 
`protected bool `[`bIsActivated`](#classNFactor_1a489248a0bbca33e35414302c918c5b0c) | 
`protected float `[`FactorValue`](#classNFactor_1a89828cdf2315c7d923a3b8f86c5dc1ba) | 
`protected TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`Operator`](#classNFactor_1a1d8f643b4585e38189b61fae7e500a7a) | 
`protected uint32 `[`Id`](#classNFactor_1a8aad3d11b8649e0f1037c86aa27b85e9) | TODO use FGuid::NewGuid().ToString() instead

## Members

#### `public  `[`NFactor`](#classNFactor_1a3aa980bfef8d6f5d3ac964b76a877bbd)`(float _FactorValue,TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > _Operator,float _Duration,FName Reason,float _Delay,TSharedPtr< NEventInterface > _Event)` <a id="classNFactor_1a3aa980bfef8d6f5d3ac964b76a877bbd"></a>

#### `public virtual  `[`~NFactor`](#classNFactor_1ad236413a6b0e2169d13e8910d1cba2e3)`()` <a id="classNFactor_1ad236413a6b0e2169d13e8910d1cba2e3"></a>

#### `public virtual bool `[`IsActivated`](#classNFactor_1ae4d6bf09600c7c2cb92fcd98bbce7913)`() const` <a id="classNFactor_1ae4d6bf09600c7c2cb92fcd98bbce7913"></a>

#### `public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetOperator`](#classNFactor_1a289953f31e47f72705f4c15da686e3c7)`() const` <a id="classNFactor_1a289953f31e47f72705f4c15da686e3c7"></a>

#### `public virtual float `[`GetFactorValue`](#classNFactor_1aaa0e436924fceddb031fbe2e5828c814)`() const` <a id="classNFactor_1aaa0e436924fceddb031fbe2e5828c814"></a>

#### `public virtual FName `[`GetReason`](#classNFactor_1ae2de6106daf773494393f49c73b3dccd)`() const` <a id="classNFactor_1ae2de6106daf773494393f49c73b3dccd"></a>

#### `public virtual uint32 `[`GetUID`](#classNFactor_1a8bac96227fe585ec0ba71ca20abde936)`() const` <a id="classNFactor_1a8bac96227fe585ec0ba71ca20abde936"></a>

#### `public virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classNFactor_1a83f07e97b488550cd4f9892e49d19f05)`()` <a id="classNFactor_1a83f07e97b488550cd4f9892e49d19f05"></a>

#### `public void `[`Activate`](#classNFactor_1a1da74e109ffc3426593685e37899da98)`(bool _bIsActivated)` <a id="classNFactor_1a1da74e109ffc3426593685e37899da98"></a>

#### `protected TSharedPtr< NEventInterface > `[`Event`](#classNFactor_1a62b32140c003f599df4e16578d1fbe3d) <a id="classNFactor_1a62b32140c003f599df4e16578d1fbe3d"></a>

#### `protected bool `[`bIsActivated`](#classNFactor_1a489248a0bbca33e35414302c918c5b0c) <a id="classNFactor_1a489248a0bbca33e35414302c918c5b0c"></a>

#### `protected float `[`FactorValue`](#classNFactor_1a89828cdf2315c7d923a3b8f86c5dc1ba) <a id="classNFactor_1a89828cdf2315c7d923a3b8f86c5dc1ba"></a>

#### `protected TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`Operator`](#classNFactor_1a1d8f643b4585e38189b61fae7e500a7a) <a id="classNFactor_1a1d8f643b4585e38189b61fae7e500a7a"></a>

#### `protected uint32 `[`Id`](#classNFactor_1a8aad3d11b8649e0f1037c86aa27b85e9) <a id="classNFactor_1a8aad3d11b8649e0f1037c86aa27b85e9"></a>

TODO use FGuid::NewGuid().ToString() instead

# class `NFactorEvent` <a id="classNFactorEvent"></a>

```
class NFactorEvent
  : public NEvent
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NFactorEvent`](#classNFactorEvent_1abda2bc8fb50fd6db125b64fc5e65d72b)`(uint32 _Id)` | 
`protected const uint32 `[`Id`](#classNFactorEvent_1a1c9dce43ca683f5b6453d16c5bf51206) | 

## Members

#### `public inline  `[`NFactorEvent`](#classNFactorEvent_1abda2bc8fb50fd6db125b64fc5e65d72b)`(uint32 _Id)` <a id="classNFactorEvent_1abda2bc8fb50fd6db125b64fc5e65d72b"></a>

#### `protected const uint32 `[`Id`](#classNFactorEvent_1a1c9dce43ca683f5b6453d16c5bf51206) <a id="classNFactorEvent_1a1c9dce43ca683f5b6453d16c5bf51206"></a>

# class `NFactorInterface` <a id="classNFactorInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetOperator`](#classNFactorInterface_1a5d92e884acb0d1a58344a3eb683361df)`() const` | 
`public float `[`GetFactorValue`](#classNFactorInterface_1af8f8af2d9c5d42ab015ea7730ca4da5a)`() const` | 
`public FName `[`GetReason`](#classNFactorInterface_1ab43aa38e309d6d6be8479fe9812a56c1)`() const` | 
`public bool `[`IsActivated`](#classNFactorInterface_1ac296007f0bc9948bf4f0d901ca348598)`() const` | 
`public uint32 `[`GetUID`](#classNFactorInterface_1a162f4219ad94ebb08e3774821e3be746)`() const` | 
`public TSharedPtr< NEventInterface > `[`GetEvent`](#classNFactorInterface_1a432d4f6b6337c7af89f14feeb81fab56)`()` | 

## Members

#### `public TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetOperator`](#classNFactorInterface_1a5d92e884acb0d1a58344a3eb683361df)`() const` <a id="classNFactorInterface_1a5d92e884acb0d1a58344a3eb683361df"></a>

#### `public float `[`GetFactorValue`](#classNFactorInterface_1af8f8af2d9c5d42ab015ea7730ca4da5a)`() const` <a id="classNFactorInterface_1af8f8af2d9c5d42ab015ea7730ca4da5a"></a>

#### `public FName `[`GetReason`](#classNFactorInterface_1ab43aa38e309d6d6be8479fe9812a56c1)`() const` <a id="classNFactorInterface_1ab43aa38e309d6d6be8479fe9812a56c1"></a>

#### `public bool `[`IsActivated`](#classNFactorInterface_1ac296007f0bc9948bf4f0d901ca348598)`() const` <a id="classNFactorInterface_1ac296007f0bc9948bf4f0d901ca348598"></a>

#### `public uint32 `[`GetUID`](#classNFactorInterface_1a162f4219ad94ebb08e3774821e3be746)`() const` <a id="classNFactorInterface_1a162f4219ad94ebb08e3774821e3be746"></a>

#### `public TSharedPtr< NEventInterface > `[`GetEvent`](#classNFactorInterface_1a432d4f6b6337c7af89f14feeb81fab56)`()` <a id="classNFactorInterface_1a432d4f6b6337c7af89f14feeb81fab56"></a>

# class `NFactorsFactoryClient` <a id="classNFactorsFactoryClient"></a>

```
class NFactorsFactoryClient
  : public NFactorsFactoryClientInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual  `[`~NFactorsFactoryClient`](#classNFactorsFactoryClient_1a1bf0a0ad559e6e449ebc9eb293d8cb9a)`()` | 
`public virtual void `[`CreateStack`](#classNFactorsFactoryClient_1ac506be39c7b5970ad922b9b749dd6cbd)`(FName StackName,TSharedPtr< NTimelineInterface > Timeline)` | 
`public virtual void `[`CreateStack`](#classNFactorsFactoryClient_1a60a4bc2c01813d816addfc4defb0ce67)`(TArray< FName > StackNames,TSharedPtr< NTimelineInterface > Timeline)` | 
`public virtual void `[`AddStack`](#classNFactorsFactoryClient_1a2e39dacd5386ac3559dbdd84e9f87a95)`(TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > Stack)` | 
`public virtual void `[`RemoveStack`](#classNFactorsFactoryClient_1a4eb4cacb1a723b5d0614511a0599cee7)`(FName StackName)` | 
`public virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetState`](#classNFactorsFactoryClient_1a3de705550f7385fdabf2bdb8ebb482a8)`(FName StackName)` | 
`public virtual TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classNFactorsFactoryClient_1a9f0a7933b063d951afce8d84acb2e3e9)`(TArray< FName > StackNames)` | 
`public virtual void `[`AddFactor`](#classNFactorsFactoryClient_1af04e6201332f28ac9bed3487acd7258e)`(FName StackName,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public virtual void `[`AddFactor`](#classNFactorsFactoryClient_1ac5d27d41195deaf7b2e72facb205d5e2)`(TArray< FName > StackNames,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public virtual void `[`SetDebug`](#classNFactorsFactoryClient_1a09146ea3b5ab0efe9e29502987a17003)`(const TArray< FName > StackNames,bool bDebug)` | 
`protected TMap< FName, TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > > `[`StacksList`](#classNFactorsFactoryClient_1ac84777bf8fab0fe4358202a62c765967) | 

## Members

#### `public inline virtual  `[`~NFactorsFactoryClient`](#classNFactorsFactoryClient_1a1bf0a0ad559e6e449ebc9eb293d8cb9a)`()` <a id="classNFactorsFactoryClient_1a1bf0a0ad559e6e449ebc9eb293d8cb9a"></a>

#### `public virtual void `[`CreateStack`](#classNFactorsFactoryClient_1ac506be39c7b5970ad922b9b749dd6cbd)`(FName StackName,TSharedPtr< NTimelineInterface > Timeline)` <a id="classNFactorsFactoryClient_1ac506be39c7b5970ad922b9b749dd6cbd"></a>

#### `public virtual void `[`CreateStack`](#classNFactorsFactoryClient_1a60a4bc2c01813d816addfc4defb0ce67)`(TArray< FName > StackNames,TSharedPtr< NTimelineInterface > Timeline)` <a id="classNFactorsFactoryClient_1a60a4bc2c01813d816addfc4defb0ce67"></a>

#### `public virtual void `[`AddStack`](#classNFactorsFactoryClient_1a2e39dacd5386ac3559dbdd84e9f87a95)`(TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > Stack)` <a id="classNFactorsFactoryClient_1a2e39dacd5386ac3559dbdd84e9f87a95"></a>

#### `public virtual void `[`RemoveStack`](#classNFactorsFactoryClient_1a4eb4cacb1a723b5d0614511a0599cee7)`(FName StackName)` <a id="classNFactorsFactoryClient_1a4eb4cacb1a723b5d0614511a0599cee7"></a>

#### `public virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetState`](#classNFactorsFactoryClient_1a3de705550f7385fdabf2bdb8ebb482a8)`(FName StackName)` <a id="classNFactorsFactoryClient_1a3de705550f7385fdabf2bdb8ebb482a8"></a>

#### `public virtual TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classNFactorsFactoryClient_1a9f0a7933b063d951afce8d84acb2e3e9)`(TArray< FName > StackNames)` <a id="classNFactorsFactoryClient_1a9f0a7933b063d951afce8d84acb2e3e9"></a>

#### `public virtual void `[`AddFactor`](#classNFactorsFactoryClient_1af04e6201332f28ac9bed3487acd7258e)`(FName StackName,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNFactorsFactoryClient_1af04e6201332f28ac9bed3487acd7258e"></a>

#### `public virtual void `[`AddFactor`](#classNFactorsFactoryClient_1ac5d27d41195deaf7b2e72facb205d5e2)`(TArray< FName > StackNames,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNFactorsFactoryClient_1ac5d27d41195deaf7b2e72facb205d5e2"></a>

#### `public virtual void `[`SetDebug`](#classNFactorsFactoryClient_1a09146ea3b5ab0efe9e29502987a17003)`(const TArray< FName > StackNames,bool bDebug)` <a id="classNFactorsFactoryClient_1a09146ea3b5ab0efe9e29502987a17003"></a>

#### `protected TMap< FName, TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > > `[`StacksList`](#classNFactorsFactoryClient_1ac84777bf8fab0fe4358202a62c765967) <a id="classNFactorsFactoryClient_1ac84777bf8fab0fe4358202a62c765967"></a>

# class `NFactorsFactoryClientInterface` <a id="classNFactorsFactoryClientInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`CreateStack`](#classNFactorsFactoryClientInterface_1a4cfc83b6327b54e2ba533b7c1d737145)`(FName StackName,TSharedPtr< NTimelineInterface > Timeline)` | 
`public void `[`CreateStack`](#classNFactorsFactoryClientInterface_1afda952f109511b436a52e3947fb5e066)`(TArray< FName > StackNames,TSharedPtr< NTimelineInterface > Timeline)` | 
`public void `[`AddStack`](#classNFactorsFactoryClientInterface_1a4522c8202d9fdb5c39a573d9ba81164a)`(TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > Stack)` | 
`public void `[`RemoveStack`](#classNFactorsFactoryClientInterface_1a9750ca39ed5e5cb77a9837e898d26196)`(FName StackName)` | 
`public `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetState`](#classNFactorsFactoryClientInterface_1a57083f17d2dd252e51ebbbb629be0417)`(FName StackName)` | 
`public TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classNFactorsFactoryClientInterface_1a4cd104a135919406fc568b7452920c8b)`(TArray< FName > StackNames)` | 
`public void `[`AddFactor`](#classNFactorsFactoryClientInterface_1a2fcd9465268c7e36d36f33ade58c3623)`(FName StackName,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public void `[`AddFactor`](#classNFactorsFactoryClientInterface_1ab344000d68f3397a4abed3ced6fa2885)`(TArray< FName > StackNames,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public void `[`SetDebug`](#classNFactorsFactoryClientInterface_1a40427f04cf0143a25f9844099209bf37)`(const TArray< FName > StackNames,bool bDebug)` | 

## Members

#### `public void `[`CreateStack`](#classNFactorsFactoryClientInterface_1a4cfc83b6327b54e2ba533b7c1d737145)`(FName StackName,TSharedPtr< NTimelineInterface > Timeline)` <a id="classNFactorsFactoryClientInterface_1a4cfc83b6327b54e2ba533b7c1d737145"></a>

#### `public void `[`CreateStack`](#classNFactorsFactoryClientInterface_1afda952f109511b436a52e3947fb5e066)`(TArray< FName > StackNames,TSharedPtr< NTimelineInterface > Timeline)` <a id="classNFactorsFactoryClientInterface_1afda952f109511b436a52e3947fb5e066"></a>

#### `public void `[`AddStack`](#classNFactorsFactoryClientInterface_1a4522c8202d9fdb5c39a573d9ba81164a)`(TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > Stack)` <a id="classNFactorsFactoryClientInterface_1a4522c8202d9fdb5c39a573d9ba81164a"></a>

#### `public void `[`RemoveStack`](#classNFactorsFactoryClientInterface_1a9750ca39ed5e5cb77a9837e898d26196)`(FName StackName)` <a id="classNFactorsFactoryClientInterface_1a9750ca39ed5e5cb77a9837e898d26196"></a>

#### `public `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetState`](#classNFactorsFactoryClientInterface_1a57083f17d2dd252e51ebbbb629be0417)`(FName StackName)` <a id="classNFactorsFactoryClientInterface_1a57083f17d2dd252e51ebbbb629be0417"></a>

#### `public TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classNFactorsFactoryClientInterface_1a4cd104a135919406fc568b7452920c8b)`(TArray< FName > StackNames)` <a id="classNFactorsFactoryClientInterface_1a4cd104a135919406fc568b7452920c8b"></a>

#### `public void `[`AddFactor`](#classNFactorsFactoryClientInterface_1a2fcd9465268c7e36d36f33ade58c3623)`(FName StackName,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNFactorsFactoryClientInterface_1a2fcd9465268c7e36d36f33ade58c3623"></a>

#### `public void `[`AddFactor`](#classNFactorsFactoryClientInterface_1ab344000d68f3397a4abed3ced6fa2885)`(TArray< FName > StackNames,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNFactorsFactoryClientInterface_1ab344000d68f3397a4abed3ced6fa2885"></a>

#### `public void `[`SetDebug`](#classNFactorsFactoryClientInterface_1a40427f04cf0143a25f9844099209bf37)`(const TArray< FName > StackNames,bool bDebug)` <a id="classNFactorsFactoryClientInterface_1a40427f04cf0143a25f9844099209bf37"></a>

# class `NFactorStack` <a id="classNFactorStack"></a>

```
class NFactorStack
  : public NFactorStackInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NFactorStack`](#classNFactorStack_1a19717747cef350942062180a20b990c2)`(FName _Name,TSharedPtr< NTimelineInterface > _Timeline)` | 
`public virtual  `[`~NFactorStack`](#classNFactorStack_1ab58dc79ac0720a158da399eb000d1bcc)`()` | 
`public virtual void `[`Reset`](#classNFactorStack_1a988ac79b4e2149e6761ab2bd54800738)`()` | 
`public virtual void `[`SetName`](#classNFactorStack_1a087ef213044d04257471687e2f29e998)`(FName _Name)` | 
`public virtual FName `[`GetName`](#classNFactorStack_1a0aeeb7cb3030d99655821b78f4ae6ad1)`() const` | 
`public virtual float `[`GetTime`](#classNFactorStack_1a167bf32542bddda67fb8e2237411f571)`() const` | 
`public virtual TSharedRef< `[`NFactorInterface`](#classNFactorInterface)` > `[`GetFactor`](#classNFactorStack_1a8ee76243346399ab28efbd6ea6ff7358)`(uint32 Key) const` | 
`public virtual void `[`AddFactor`](#classNFactorStack_1a2a1412321e6f40dd51ba657bc51a8dea)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public virtual bool `[`HasFlag`](#classNFactorStack_1a8f5b9902cf64f1eafc3b1fbfe91f6e54)`(FString Flag) const` | 
`public virtual bool `[`GetFlag`](#classNFactorStack_1a8d2ba6a3a6c13624c2d289266ab126c3)`(FString Flag) const` | 
`public virtual void `[`SetFlag`](#classNFactorStack_1a3d62bbcb02c9c6e72e9039c15936e1ec)`(FString Flag,bool Value)` | 
`public virtual TArray< TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`GetFactors`](#classNFactorStack_1a1c19bcd2252ebc2afb24e01917ce686d)`() const` | 
`public virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetCurrentState`](#classNFactorStack_1a3ac5bc039e2276f311a2a9cf2e9cedcd)`()` | 
`public virtual void `[`Debug`](#classNFactorStack_1acb9d2567eaf2dd9f1c25acb9888e4bb7)`(bool _bDebug)` | 
`protected bool `[`bDebug`](#classNFactorStack_1a433b9bf07597be6f85c9d6e25a61a2c1) | 
`protected TMap< FString, bool > `[`IterationFlags`](#classNFactorStack_1ab0883ade9b34b28403e371568d7de572) | 
`protected TSharedPtr< NTimelineInterface > `[`Timeline`](#classNFactorStack_1a2644739de140ddc539da5a1c3d3ce452) | 
`protected TArray< TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`Factors`](#classNFactorStack_1a4ec56071d7e68a5cf28ef3d4f5d87e60) | 
`protected FName `[`Name`](#classNFactorStack_1a77470aff166c1c99b6fad3095082ef09) | 
`protected void `[`AddFactorsToState`](#classNFactorStack_1a3aa4886fc0033bfda2dbde62fa684c67)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` * State)` | 

## Members

#### `public  `[`NFactorStack`](#classNFactorStack_1a19717747cef350942062180a20b990c2)`(FName _Name,TSharedPtr< NTimelineInterface > _Timeline)` <a id="classNFactorStack_1a19717747cef350942062180a20b990c2"></a>

#### `public virtual  `[`~NFactorStack`](#classNFactorStack_1ab58dc79ac0720a158da399eb000d1bcc)`()` <a id="classNFactorStack_1ab58dc79ac0720a158da399eb000d1bcc"></a>

#### `public virtual void `[`Reset`](#classNFactorStack_1a988ac79b4e2149e6761ab2bd54800738)`()` <a id="classNFactorStack_1a988ac79b4e2149e6761ab2bd54800738"></a>

#### `public virtual void `[`SetName`](#classNFactorStack_1a087ef213044d04257471687e2f29e998)`(FName _Name)` <a id="classNFactorStack_1a087ef213044d04257471687e2f29e998"></a>

#### `public virtual FName `[`GetName`](#classNFactorStack_1a0aeeb7cb3030d99655821b78f4ae6ad1)`() const` <a id="classNFactorStack_1a0aeeb7cb3030d99655821b78f4ae6ad1"></a>

#### `public virtual float `[`GetTime`](#classNFactorStack_1a167bf32542bddda67fb8e2237411f571)`() const` <a id="classNFactorStack_1a167bf32542bddda67fb8e2237411f571"></a>

#### `public virtual TSharedRef< `[`NFactorInterface`](#classNFactorInterface)` > `[`GetFactor`](#classNFactorStack_1a8ee76243346399ab28efbd6ea6ff7358)`(uint32 Key) const` <a id="classNFactorStack_1a8ee76243346399ab28efbd6ea6ff7358"></a>

#### `public virtual void `[`AddFactor`](#classNFactorStack_1a2a1412321e6f40dd51ba657bc51a8dea)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNFactorStack_1a2a1412321e6f40dd51ba657bc51a8dea"></a>

#### `public virtual bool `[`HasFlag`](#classNFactorStack_1a8f5b9902cf64f1eafc3b1fbfe91f6e54)`(FString Flag) const` <a id="classNFactorStack_1a8f5b9902cf64f1eafc3b1fbfe91f6e54"></a>

#### `public virtual bool `[`GetFlag`](#classNFactorStack_1a8d2ba6a3a6c13624c2d289266ab126c3)`(FString Flag) const` <a id="classNFactorStack_1a8d2ba6a3a6c13624c2d289266ab126c3"></a>

#### `public virtual void `[`SetFlag`](#classNFactorStack_1a3d62bbcb02c9c6e72e9039c15936e1ec)`(FString Flag,bool Value)` <a id="classNFactorStack_1a3d62bbcb02c9c6e72e9039c15936e1ec"></a>

#### `public virtual TArray< TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`GetFactors`](#classNFactorStack_1a1c19bcd2252ebc2afb24e01917ce686d)`() const` <a id="classNFactorStack_1a1c19bcd2252ebc2afb24e01917ce686d"></a>

#### `public virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetCurrentState`](#classNFactorStack_1a3ac5bc039e2276f311a2a9cf2e9cedcd)`()` <a id="classNFactorStack_1a3ac5bc039e2276f311a2a9cf2e9cedcd"></a>

#### `public virtual void `[`Debug`](#classNFactorStack_1acb9d2567eaf2dd9f1c25acb9888e4bb7)`(bool _bDebug)` <a id="classNFactorStack_1acb9d2567eaf2dd9f1c25acb9888e4bb7"></a>

#### `protected bool `[`bDebug`](#classNFactorStack_1a433b9bf07597be6f85c9d6e25a61a2c1) <a id="classNFactorStack_1a433b9bf07597be6f85c9d6e25a61a2c1"></a>

#### `protected TMap< FString, bool > `[`IterationFlags`](#classNFactorStack_1ab0883ade9b34b28403e371568d7de572) <a id="classNFactorStack_1ab0883ade9b34b28403e371568d7de572"></a>

#### `protected TSharedPtr< NTimelineInterface > `[`Timeline`](#classNFactorStack_1a2644739de140ddc539da5a1c3d3ce452) <a id="classNFactorStack_1a2644739de140ddc539da5a1c3d3ce452"></a>

#### `protected TArray< TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`Factors`](#classNFactorStack_1a4ec56071d7e68a5cf28ef3d4f5d87e60) <a id="classNFactorStack_1a4ec56071d7e68a5cf28ef3d4f5d87e60"></a>

#### `protected FName `[`Name`](#classNFactorStack_1a77470aff166c1c99b6fad3095082ef09) <a id="classNFactorStack_1a77470aff166c1c99b6fad3095082ef09"></a>

#### `protected void `[`AddFactorsToState`](#classNFactorStack_1a3aa4886fc0033bfda2dbde62fa684c67)`(`[`NFactorStateInterface`](#classNFactorStateInterface)` * State)` <a id="classNFactorStack_1a3aa4886fc0033bfda2dbde62fa684c67"></a>

# class `NFactorStackInterface` <a id="classNFactorStackInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`Reset`](#classNFactorStackInterface_1ad7567ca14fae76f1b382a671ef90661d)`()` | 
`public void `[`SetName`](#classNFactorStackInterface_1ade86192c58d4c042a9d3134b72dc0ecd)`(FName _Name)` | 
`public FName `[`GetName`](#classNFactorStackInterface_1a947b28a853f76dba1ca78e168257616b)`() const` | 
`public float `[`GetTime`](#classNFactorStackInterface_1aa07ecc03626cafff59487e3cc05136d7)`() const` | 
`public TSharedRef< `[`NFactorInterface`](#classNFactorInterface)` > `[`GetFactor`](#classNFactorStackInterface_1aea5ac837f53a480e8a5bdb8b79c27b8e)`(uint32 Key) const` | 
`public TArray< TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`GetFactors`](#classNFactorStackInterface_1a33a829c38d9b6f71fd84c4c01d70a87f)`() const` | 
`public void `[`AddFactor`](#classNFactorStackInterface_1a42c9d99704801cf743fce0d2668420a1)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public bool `[`HasFlag`](#classNFactorStackInterface_1a3a05d36bd890766358c587e140c7cec7)`(FString Flag) const` | 
`public bool `[`GetFlag`](#classNFactorStackInterface_1a5616cad3df65a2f070c3906a02413da2)`(FString Flag) const` | 
`public void `[`SetFlag`](#classNFactorStackInterface_1a67926a572f866b783734ab50bffb5f6c)`(FString Flag,bool Value)` | 
`public void `[`Debug`](#classNFactorStackInterface_1a68956343f378061695a7042523a15b06)`(bool _bDebug)` | 
`public `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetCurrentState`](#classNFactorStackInterface_1a89985da471ac114277a7d91fc964d5b5)`()` | 

## Members

#### `public void `[`Reset`](#classNFactorStackInterface_1ad7567ca14fae76f1b382a671ef90661d)`()` <a id="classNFactorStackInterface_1ad7567ca14fae76f1b382a671ef90661d"></a>

#### `public void `[`SetName`](#classNFactorStackInterface_1ade86192c58d4c042a9d3134b72dc0ecd)`(FName _Name)` <a id="classNFactorStackInterface_1ade86192c58d4c042a9d3134b72dc0ecd"></a>

#### `public FName `[`GetName`](#classNFactorStackInterface_1a947b28a853f76dba1ca78e168257616b)`() const` <a id="classNFactorStackInterface_1a947b28a853f76dba1ca78e168257616b"></a>

#### `public float `[`GetTime`](#classNFactorStackInterface_1aa07ecc03626cafff59487e3cc05136d7)`() const` <a id="classNFactorStackInterface_1aa07ecc03626cafff59487e3cc05136d7"></a>

#### `public TSharedRef< `[`NFactorInterface`](#classNFactorInterface)` > `[`GetFactor`](#classNFactorStackInterface_1aea5ac837f53a480e8a5bdb8b79c27b8e)`(uint32 Key) const` <a id="classNFactorStackInterface_1aea5ac837f53a480e8a5bdb8b79c27b8e"></a>

#### `public TArray< TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`GetFactors`](#classNFactorStackInterface_1a33a829c38d9b6f71fd84c4c01d70a87f)`() const` <a id="classNFactorStackInterface_1a33a829c38d9b6f71fd84c4c01d70a87f"></a>

#### `public void `[`AddFactor`](#classNFactorStackInterface_1a42c9d99704801cf743fce0d2668420a1)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNFactorStackInterface_1a42c9d99704801cf743fce0d2668420a1"></a>

#### `public bool `[`HasFlag`](#classNFactorStackInterface_1a3a05d36bd890766358c587e140c7cec7)`(FString Flag) const` <a id="classNFactorStackInterface_1a3a05d36bd890766358c587e140c7cec7"></a>

#### `public bool `[`GetFlag`](#classNFactorStackInterface_1a5616cad3df65a2f070c3906a02413da2)`(FString Flag) const` <a id="classNFactorStackInterface_1a5616cad3df65a2f070c3906a02413da2"></a>

#### `public void `[`SetFlag`](#classNFactorStackInterface_1a67926a572f866b783734ab50bffb5f6c)`(FString Flag,bool Value)` <a id="classNFactorStackInterface_1a67926a572f866b783734ab50bffb5f6c"></a>

#### `public void `[`Debug`](#classNFactorStackInterface_1a68956343f378061695a7042523a15b06)`(bool _bDebug)` <a id="classNFactorStackInterface_1a68956343f378061695a7042523a15b06"></a>

#### `public `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetCurrentState`](#classNFactorStackInterface_1a89985da471ac114277a7d91fc964d5b5)`()` <a id="classNFactorStackInterface_1a89985da471ac114277a7d91fc964d5b5"></a>

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
`public  `[`NFactorState`](#classNFactorState_1ac199aef10127fd7f756b2488bf1b394f)`(float _Time)` | 
`public virtual void `[`AddFactor`](#classNFactorState_1a88263bca3e1d91d3a80a8a3c88aa4656)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public virtual float `[`GetTime`](#classNFactorState_1aa4ab3543a7bb44e9a9763f544366fa84)`() const` | 
`public virtual float `[`Compute`](#classNFactorState_1a95f00f47091e4c1ab6d1e4cba3421e5a)`()` | 
`public virtual void `[`Debug`](#classNFactorState_1a30fba76e979ccc5f32482e512f31e805)`(bool _bDebug)` | 
`public virtual const TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`GetOperators`](#classNFactorState_1a16096dbc1357e7723fa7388b887d46cb)`() const` | 
`protected TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`Operators`](#classNFactorState_1a31de6655fee5eabd18207e137b7e34c0) | 

## Members

#### `public bool `[`bDebug`](#classNFactorState_1ac1565797048a0259d71bad1cb4995604) <a id="classNFactorState_1ac1565797048a0259d71bad1cb4995604"></a>

#### `public inline virtual  `[`~NFactorState`](#classNFactorState_1a11c5c3b35724ddba3db601ff3d2574e9)`()` <a id="classNFactorState_1a11c5c3b35724ddba3db601ff3d2574e9"></a>

#### `public inline  `[`NFactorState`](#classNFactorState_1a64392bc5f25117da90683127f38b3d61)`()` <a id="classNFactorState_1a64392bc5f25117da90683127f38b3d61"></a>

#### `public  `[`NFactorState`](#classNFactorState_1ac199aef10127fd7f756b2488bf1b394f)`(float _Time)` <a id="classNFactorState_1ac199aef10127fd7f756b2488bf1b394f"></a>

#### `public virtual void `[`AddFactor`](#classNFactorState_1a88263bca3e1d91d3a80a8a3c88aa4656)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNFactorState_1a88263bca3e1d91d3a80a8a3c88aa4656"></a>

#### `public virtual float `[`GetTime`](#classNFactorState_1aa4ab3543a7bb44e9a9763f544366fa84)`() const` <a id="classNFactorState_1aa4ab3543a7bb44e9a9763f544366fa84"></a>

#### `public virtual float `[`Compute`](#classNFactorState_1a95f00f47091e4c1ab6d1e4cba3421e5a)`()` <a id="classNFactorState_1a95f00f47091e4c1ab6d1e4cba3421e5a"></a>

#### `public virtual void `[`Debug`](#classNFactorState_1a30fba76e979ccc5f32482e512f31e805)`(bool _bDebug)` <a id="classNFactorState_1a30fba76e979ccc5f32482e512f31e805"></a>

#### `public virtual const TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`GetOperators`](#classNFactorState_1a16096dbc1357e7723fa7388b887d46cb)`() const` <a id="classNFactorState_1a16096dbc1357e7723fa7388b887d46cb"></a>

#### `protected TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`Operators`](#classNFactorState_1a31de6655fee5eabd18207e137b7e34c0) <a id="classNFactorState_1a31de6655fee5eabd18207e137b7e34c0"></a>

# class `NFactorStateInterface` <a id="classNFactorStateInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`AddFactor`](#classNFactorStateInterface_1ac4dbe9b19f85305fb340de59e4313eba)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public float `[`GetTime`](#classNFactorStateInterface_1a0db01ef0d3940a9ff8aa49df01d9368a)`() const` | 
`public float `[`Compute`](#classNFactorStateInterface_1a612d26366bf252a9772d8edaa9deb1ee)`()` | 
`public void `[`Debug`](#classNFactorStateInterface_1a0da2fc0ac04e1d121dece2c20b4a9df9)`(bool _bDebug)` | 
`public const TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`GetOperators`](#classNFactorStateInterface_1a69be6ed66d3ce8da4310169c24ba11f3)`() const` | 

## Members

#### `public void `[`AddFactor`](#classNFactorStateInterface_1ac4dbe9b19f85305fb340de59e4313eba)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNFactorStateInterface_1ac4dbe9b19f85305fb340de59e4313eba"></a>

#### `public float `[`GetTime`](#classNFactorStateInterface_1a0db01ef0d3940a9ff8aa49df01d9368a)`() const` <a id="classNFactorStateInterface_1a0db01ef0d3940a9ff8aa49df01d9368a"></a>

#### `public float `[`Compute`](#classNFactorStateInterface_1a612d26366bf252a9772d8edaa9deb1ee)`()` <a id="classNFactorStateInterface_1a612d26366bf252a9772d8edaa9deb1ee"></a>

#### `public void `[`Debug`](#classNFactorStateInterface_1a0da2fc0ac04e1d121dece2c20b4a9df9)`(bool _bDebug)` <a id="classNFactorStateInterface_1a0da2fc0ac04e1d121dece2c20b4a9df9"></a>

#### `public const TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`GetOperators`](#classNFactorStateInterface_1a69be6ed66d3ce8da4310169c24ba11f3)`() const` <a id="classNFactorStateInterface_1a69be6ed66d3ce8da4310169c24ba11f3"></a>

# class `NMultiplyOperator` <a id="classNMultiplyOperator"></a>

```
class NMultiplyOperator
  : public FactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNMultiplyOperator_1a13ed17ab0b1d7f45afb34bbb869a24fb)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNMultiplyOperator_1aa7f43a251189265f3e9854bcefc0ff90)`()` | 
`public inline virtual const FName `[`GetName`](#classNMultiplyOperator_1a78841a13d056a1d79ca82d35db1f26d2)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNMultiplyOperator_1a13ed17ab0b1d7f45afb34bbb869a24fb)`(float Lh,float Rh)` <a id="classNMultiplyOperator_1a13ed17ab0b1d7f45afb34bbb869a24fb"></a>

#### `public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNMultiplyOperator_1aa7f43a251189265f3e9854bcefc0ff90)`()` <a id="classNMultiplyOperator_1aa7f43a251189265f3e9854bcefc0ff90"></a>

#### `public inline virtual const FName `[`GetName`](#classNMultiplyOperator_1a78841a13d056a1d79ca82d35db1f26d2)`()` <a id="classNMultiplyOperator_1a78841a13d056a1d79ca82d35db1f26d2"></a>

# class `NNullFactorState` <a id="classNNullFactorState"></a>

```
class NNullFactorState
  : public NFactorState
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NNullFactorState`](#classNNullFactorState_1a6fbb0af6b2427a0e182743fc63b59d58)`()` | 
`public virtual void `[`AddFactor`](#classNNullFactorState_1a1ef780cdbb3f4e72d1180e9f48e4d1f4)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public virtual float `[`Compute`](#classNNullFactorState_1a4f8403c3a1253db93d88d6bdf2958f9f)`()` | 

## Members

#### `public  `[`NNullFactorState`](#classNNullFactorState_1a6fbb0af6b2427a0e182743fc63b59d58)`()` <a id="classNNullFactorState_1a6fbb0af6b2427a0e182743fc63b59d58"></a>

#### `public virtual void `[`AddFactor`](#classNNullFactorState_1a1ef780cdbb3f4e72d1180e9f48e4d1f4)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classNNullFactorState_1a1ef780cdbb3f4e72d1180e9f48e4d1f4"></a>

#### `public virtual float `[`Compute`](#classNNullFactorState_1a4f8403c3a1253db93d88d6bdf2958f9f)`()` <a id="classNNullFactorState_1a4f8403c3a1253db93d88d6bdf2958f9f"></a>

# class `NNullOperator` <a id="classNNullOperator"></a>

```
class NNullOperator
  : public FactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNNullOperator_1a74b252e0b045e0867b283668c0776956)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNNullOperator_1a98d1acaad0817243d6ba1a1ddef3d0ff)`()` | 
`public inline virtual const FName `[`GetName`](#classNNullOperator_1a5bab46d063f6b81227aa6925a34b1ea3)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNNullOperator_1a74b252e0b045e0867b283668c0776956)`(float Lh,float Rh)` <a id="classNNullOperator_1a74b252e0b045e0867b283668c0776956"></a>

#### `public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNNullOperator_1a98d1acaad0817243d6ba1a1ddef3d0ff)`()` <a id="classNNullOperator_1a98d1acaad0817243d6ba1a1ddef3d0ff"></a>

#### `public inline virtual const FName `[`GetName`](#classNNullOperator_1a5bab46d063f6b81227aa6925a34b1ea3)`()` <a id="classNNullOperator_1a5bab46d063f6b81227aa6925a34b1ea3"></a>

# class `NResetOperator` <a id="classNResetOperator"></a>

```
class NResetOperator
  : public NResetOperatorBase
  : public FactorOperatorInterfaceWithStack
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~NResetOperator`](#classNResetOperator_1af776191fda9671ac0431ee6b0b668dce)`()` | 
`public inline virtual const FName `[`GetName`](#classNResetOperator_1a2a588aed7287ebf233d15d215970683f)`()` | 
`public virtual float `[`Compute`](#classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNResetOperator_1a958d337c82eb2422323ee223b76cab66)`()` | 
`public virtual void `[`SetStack`](#classNResetOperator_1a51923e9c111d4f23a921877e47ee8b7e)`(`[`NFactorStackInterface`](#classNFactorStackInterface)` * Stack)` | 
`public virtual void `[`SetKeyInStack`](#classNResetOperator_1aa55538b52fae733a1f9133826e3b7981)`(uint32 Key)` | 
`protected `[`NFactorStackInterface`](#classNFactorStackInterface)` * `[`MyStack`](#classNResetOperator_1aaff9f7bed2f4c6be6077721aeff7a0b5) | 
`protected uint32 `[`KeyInStack`](#classNResetOperator_1a279132427eb6c24936faa0955aa98c57) | 

## Members

#### `public virtual  `[`~NResetOperator`](#classNResetOperator_1af776191fda9671ac0431ee6b0b668dce)`()` <a id="classNResetOperator_1af776191fda9671ac0431ee6b0b668dce"></a>

#### `public inline virtual const FName `[`GetName`](#classNResetOperator_1a2a588aed7287ebf233d15d215970683f)`()` <a id="classNResetOperator_1a2a588aed7287ebf233d15d215970683f"></a>

#### `public virtual float `[`Compute`](#classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e)`(float Lh,float Rh)` <a id="classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e"></a>

#### `public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNResetOperator_1a958d337c82eb2422323ee223b76cab66)`()` <a id="classNResetOperator_1a958d337c82eb2422323ee223b76cab66"></a>

#### `public virtual void `[`SetStack`](#classNResetOperator_1a51923e9c111d4f23a921877e47ee8b7e)`(`[`NFactorStackInterface`](#classNFactorStackInterface)` * Stack)` <a id="classNResetOperator_1a51923e9c111d4f23a921877e47ee8b7e"></a>

#### `public virtual void `[`SetKeyInStack`](#classNResetOperator_1aa55538b52fae733a1f9133826e3b7981)`(uint32 Key)` <a id="classNResetOperator_1aa55538b52fae733a1f9133826e3b7981"></a>

#### `protected `[`NFactorStackInterface`](#classNFactorStackInterface)` * `[`MyStack`](#classNResetOperator_1aaff9f7bed2f4c6be6077721aeff7a0b5) <a id="classNResetOperator_1aaff9f7bed2f4c6be6077721aeff7a0b5"></a>

#### `protected uint32 `[`KeyInStack`](#classNResetOperator_1a279132427eb6c24936faa0955aa98c57) <a id="classNResetOperator_1a279132427eb6c24936faa0955aa98c57"></a>

# class `NResetOperatorBase` <a id="classNResetOperatorBase"></a>

```
class NResetOperatorBase
  : public FactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNResetOperatorBase_1a6ff5195aa5c913fd5af7efc35ac4d265)`()` | 

## Members

#### `public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNResetOperatorBase_1a6ff5195aa5c913fd5af7efc35ac4d265)`()` <a id="classNResetOperatorBase_1a6ff5195aa5c913fd5af7efc35ac4d265"></a>

# class `NSubsctractOperator` <a id="classNSubsctractOperator"></a>

```
class NSubsctractOperator
  : public FactorOperatorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNSubsctractOperator_1ab0d1823a3d03ea5b098e184416d6f442)`(float Lh,float Rh)` | 
`public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNSubsctractOperator_1af05c24d1f89beed95840c05615a3edbc)`()` | 
`public inline virtual const FName `[`GetName`](#classNSubsctractOperator_1a5c21df39e32ffbb8de747c4cd97332d5)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNSubsctractOperator_1ab0d1823a3d03ea5b098e184416d6f442)`(float Lh,float Rh)` <a id="classNSubsctractOperator_1ab0d1823a3d03ea5b098e184416d6f442"></a>

#### `public virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetInverse`](#classNSubsctractOperator_1af05c24d1f89beed95840c05615a3edbc)`()` <a id="classNSubsctractOperator_1af05c24d1f89beed95840c05615a3edbc"></a>

#### `public inline virtual const FName `[`GetName`](#classNSubsctractOperator_1a5c21df39e32ffbb8de747c4cd97332d5)`()` <a id="classNSubsctractOperator_1a5c21df39e32ffbb8de747c4cd97332d5"></a>

# class `OperatorUtils` <a id="classOperatorUtils"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

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

# class `UFactorFakeGameInstance` <a id="classUFactorFakeGameInstance"></a>

```
class UFactorFakeGameInstance
  : public UFakeGameInstance
  : public INFactorsFactoryGameInstance
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UFactorFakeGameInstance`](#classUFactorFakeGameInstance_1ac703369180215869db8f91a53a1f1382)`()` | 
`public inline virtual `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter)` * `[`GetFactorsFactoryClient`](#classUFactorFakeGameInstance_1af4ae95005be5ff5c2a9974579c6c631f)`() const` | 
`protected `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter)` * `[`FactorsFactoryClient`](#classUFactorFakeGameInstance_1ad5f2dda28e59badba6fc3d2afc3d3832) | 

## Members

#### `public inline  `[`UFactorFakeGameInstance`](#classUFactorFakeGameInstance_1ac703369180215869db8f91a53a1f1382)`()` <a id="classUFactorFakeGameInstance_1ac703369180215869db8f91a53a1f1382"></a>

#### `public inline virtual `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter)` * `[`GetFactorsFactoryClient`](#classUFactorFakeGameInstance_1af4ae95005be5ff5c2a9974579c6c631f)`() const` <a id="classUFactorFakeGameInstance_1af4ae95005be5ff5c2a9974579c6c631f"></a>

#### `protected `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter)` * `[`FactorsFactoryClient`](#classUFactorFakeGameInstance_1ad5f2dda28e59badba6fc3d2afc3d3832) <a id="classUFactorFakeGameInstance_1ad5f2dda28e59badba6fc3d2afc3d3832"></a>

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

# class `UK2Node_FactorOperator` <a id="classUK2Node__FactorOperator"></a>

```
class UK2Node_FactorOperator
  : public UK2Node
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`BeginDestroy`](#classUK2Node__FactorOperator_1abe95ed3e5db1e6b5b18ef944fe749896)`()` | 
`public virtual void `[`PostEditChangeProperty`](#classUK2Node__FactorOperator_1a926b8f3314809423b98ef0c261632e18)`(struct FPropertyChangedEvent & PropertyChangedEvent)` | 
`public virtual void `[`PreEditChange`](#classUK2Node__FactorOperator_1a62e4b3137f9f7f14d479f5484451290e)`(UProperty * PropertyAboutToChange)` | 
`public virtual FText `[`GetNodeTitle`](#classUK2Node__FactorOperator_1a942770c29d3a5f36b4963c9750b425f9)`(ENodeTitleType::Type TitleType) const` | 
`public virtual FText `[`GetTooltipText`](#classUK2Node__FactorOperator_1aa0bc30677eeef3637c8f944bbbaf8be7)`() const` | 
`public virtual void `[`AllocateDefaultPins`](#classUK2Node__FactorOperator_1a99e35e30c4e6d7aa1005fe4d059799d5)`()` | 
`public virtual void `[`PostPlacedNewNode`](#classUK2Node__FactorOperator_1a635463c9a784768f35d8f620ec2c791f)`()` | 
`public virtual void `[`PinDefaultValueChanged`](#classUK2Node__FactorOperator_1a12f298ffe40c74a851b8d705fa30f591)`(UEdGraphPin * Pin)` | 
`public virtual void `[`PinConnectionListChanged`](#classUK2Node__FactorOperator_1aab63a9a025ce0ce5abef1d4fd7bc347f)`(UEdGraphPin * Pin)` | 
`public virtual void `[`ValidateNodeDuringCompilation`](#classUK2Node__FactorOperator_1a61088c55586b9b55977d765631ce2cad)`(class FCompilerResultsLog & MessageLog) const` | 
`public inline virtual bool `[`ShouldShowNodeProperties`](#classUK2Node__FactorOperator_1ab66148b0e43836cbc0456d455640a38c)`() const` | 
`public virtual void `[`ReallocatePinsDuringReconstruction`](#classUK2Node__FactorOperator_1af76c21297f39efc3745159aa18c5158f)`(TArray< UEdGraphPin * > & OldPins)` | 
`public virtual bool `[`HasExternalDependencies`](#classUK2Node__FactorOperator_1af06102885767e3f0e395d3634d9b6d4c)`(TArray< class UStruct * > * OptionalOutput) const` | 
`public virtual class FNodeHandlingFunctor * `[`CreateNodeHandler`](#classUK2Node__FactorOperator_1af93336d26a6a417f59c71096b25ef214)`(class FKismetCompilerContext & CompilerContext) const` | 
`public virtual void `[`ExpandNode`](#classUK2Node__FactorOperator_1ab2b71e23b67852303bed8ce10c2c038f)`(class FKismetCompilerContext & CompilerContext,UEdGraph * SourceGraph)` | 
`public virtual void `[`GetMenuActions`](#classUK2Node__FactorOperator_1aed249802840d8e031ba45f005e8a452b)`(FBlueprintActionDatabaseRegistrar & ActionRegistrar) const` | 
`public virtual FText `[`GetMenuCategory`](#classUK2Node__FactorOperator_1aa01422bdd97ce092713d0e111d496ca3)`() const` | 
`public bool `[`TryConnectPin`](#classUK2Node__FactorOperator_1abc01d644da9d911117f73c2655b06a3b)`(FKismetCompilerContext & CompilerContext,UEdGraphPin * PinA,UEdGraphPin * PinB) const` | 
`public inline UEdGraphPin * `[`FindClassPin`](#classUK2Node__FactorOperator_1af20a4d927dcff66afcce3e36f1b195dc)`() const` | Finds and returns the class input pin from the current set of pins.
`public UEdGraphPin * `[`GetResultPin`](#classUK2Node__FactorOperator_1a5a373cc9dec8e9950101b3e4795f0d76)`() const` | 
`public UEdGraphPin * `[`GetThenPin`](#classUK2Node__FactorOperator_1a4ddae61c346d63d0190c0114b40f94c4)`() const` | 
`public UEdGraphPin * `[`GetOuterPin`](#classUK2Node__FactorOperator_1a54eafeebb68a110dd895eb34c8014e02)`() const` | 
`public inline UClass * `[`GetInputClass`](#classUK2Node__FactorOperator_1a652a8d57b22a73c086cb32663bba69cf)`() const` | Retrieves the current input class type.
`public void `[`OnBlueprintClassModified`](#classUK2Node__FactorOperator_1ab599f3c28dcd97430cc301c8c9c9ee3c)`(UBlueprint * TargetBlueprint)` | 
`public void `[`ClearDelegates`](#classUK2Node__FactorOperator_1a99e68cec308fa3c4991bf4f07bc11c61)`()` | 
`protected UEdGraphPin * `[`FindClassPin`](#classUK2Node__FactorOperator_1a999bea75bad83a53ecefcb828c7cf041)`(const TArray< UEdGraphPin * > & FromPins) const` | Finds and returns the class input pin.
`protected UClass * `[`GetInputClass`](#classUK2Node__FactorOperator_1a888c0647555d013d49ad18eb34d36cac)`(const UEdGraphPin * FromPin) const` | Determines the input class type from the given pin.
`protected void `[`CreateNewPins`](#classUK2Node__FactorOperator_1aee3f14c4c58a1e94030bb6fa58487e60)`(UClass * InClass)` | Creates the full set of pins (properties) from the given input class.
`protected void `[`OnClassPinChanged`](#classUK2Node__FactorOperator_1a707e58272062acef24fcf2034014cd21)`()` | Will be called whenever the class pin selector changes its value.

## Members

#### `public virtual void `[`BeginDestroy`](#classUK2Node__FactorOperator_1abe95ed3e5db1e6b5b18ef944fe749896)`()` <a id="classUK2Node__FactorOperator_1abe95ed3e5db1e6b5b18ef944fe749896"></a>

#### `public virtual void `[`PostEditChangeProperty`](#classUK2Node__FactorOperator_1a926b8f3314809423b98ef0c261632e18)`(struct FPropertyChangedEvent & PropertyChangedEvent)` <a id="classUK2Node__FactorOperator_1a926b8f3314809423b98ef0c261632e18"></a>

#### `public virtual void `[`PreEditChange`](#classUK2Node__FactorOperator_1a62e4b3137f9f7f14d479f5484451290e)`(UProperty * PropertyAboutToChange)` <a id="classUK2Node__FactorOperator_1a62e4b3137f9f7f14d479f5484451290e"></a>

#### `public virtual FText `[`GetNodeTitle`](#classUK2Node__FactorOperator_1a942770c29d3a5f36b4963c9750b425f9)`(ENodeTitleType::Type TitleType) const` <a id="classUK2Node__FactorOperator_1a942770c29d3a5f36b4963c9750b425f9"></a>

#### `public virtual FText `[`GetTooltipText`](#classUK2Node__FactorOperator_1aa0bc30677eeef3637c8f944bbbaf8be7)`() const` <a id="classUK2Node__FactorOperator_1aa0bc30677eeef3637c8f944bbbaf8be7"></a>

#### `public virtual void `[`AllocateDefaultPins`](#classUK2Node__FactorOperator_1a99e35e30c4e6d7aa1005fe4d059799d5)`()` <a id="classUK2Node__FactorOperator_1a99e35e30c4e6d7aa1005fe4d059799d5"></a>

#### `public virtual void `[`PostPlacedNewNode`](#classUK2Node__FactorOperator_1a635463c9a784768f35d8f620ec2c791f)`()` <a id="classUK2Node__FactorOperator_1a635463c9a784768f35d8f620ec2c791f"></a>

#### `public virtual void `[`PinDefaultValueChanged`](#classUK2Node__FactorOperator_1a12f298ffe40c74a851b8d705fa30f591)`(UEdGraphPin * Pin)` <a id="classUK2Node__FactorOperator_1a12f298ffe40c74a851b8d705fa30f591"></a>

#### `public virtual void `[`PinConnectionListChanged`](#classUK2Node__FactorOperator_1aab63a9a025ce0ce5abef1d4fd7bc347f)`(UEdGraphPin * Pin)` <a id="classUK2Node__FactorOperator_1aab63a9a025ce0ce5abef1d4fd7bc347f"></a>

#### `public virtual void `[`ValidateNodeDuringCompilation`](#classUK2Node__FactorOperator_1a61088c55586b9b55977d765631ce2cad)`(class FCompilerResultsLog & MessageLog) const` <a id="classUK2Node__FactorOperator_1a61088c55586b9b55977d765631ce2cad"></a>

#### `public inline virtual bool `[`ShouldShowNodeProperties`](#classUK2Node__FactorOperator_1ab66148b0e43836cbc0456d455640a38c)`() const` <a id="classUK2Node__FactorOperator_1ab66148b0e43836cbc0456d455640a38c"></a>

#### `public virtual void `[`ReallocatePinsDuringReconstruction`](#classUK2Node__FactorOperator_1af76c21297f39efc3745159aa18c5158f)`(TArray< UEdGraphPin * > & OldPins)` <a id="classUK2Node__FactorOperator_1af76c21297f39efc3745159aa18c5158f"></a>

#### `public virtual bool `[`HasExternalDependencies`](#classUK2Node__FactorOperator_1af06102885767e3f0e395d3634d9b6d4c)`(TArray< class UStruct * > * OptionalOutput) const` <a id="classUK2Node__FactorOperator_1af06102885767e3f0e395d3634d9b6d4c"></a>

#### `public virtual class FNodeHandlingFunctor * `[`CreateNodeHandler`](#classUK2Node__FactorOperator_1af93336d26a6a417f59c71096b25ef214)`(class FKismetCompilerContext & CompilerContext) const` <a id="classUK2Node__FactorOperator_1af93336d26a6a417f59c71096b25ef214"></a>

#### `public virtual void `[`ExpandNode`](#classUK2Node__FactorOperator_1ab2b71e23b67852303bed8ce10c2c038f)`(class FKismetCompilerContext & CompilerContext,UEdGraph * SourceGraph)` <a id="classUK2Node__FactorOperator_1ab2b71e23b67852303bed8ce10c2c038f"></a>

#### `public virtual void `[`GetMenuActions`](#classUK2Node__FactorOperator_1aed249802840d8e031ba45f005e8a452b)`(FBlueprintActionDatabaseRegistrar & ActionRegistrar) const` <a id="classUK2Node__FactorOperator_1aed249802840d8e031ba45f005e8a452b"></a>

#### `public virtual FText `[`GetMenuCategory`](#classUK2Node__FactorOperator_1aa01422bdd97ce092713d0e111d496ca3)`() const` <a id="classUK2Node__FactorOperator_1aa01422bdd97ce092713d0e111d496ca3"></a>

#### `public bool `[`TryConnectPin`](#classUK2Node__FactorOperator_1abc01d644da9d911117f73c2655b06a3b)`(FKismetCompilerContext & CompilerContext,UEdGraphPin * PinA,UEdGraphPin * PinB) const` <a id="classUK2Node__FactorOperator_1abc01d644da9d911117f73c2655b06a3b"></a>

#### `public inline UEdGraphPin * `[`FindClassPin`](#classUK2Node__FactorOperator_1af20a4d927dcff66afcce3e36f1b195dc)`() const` <a id="classUK2Node__FactorOperator_1af20a4d927dcff66afcce3e36f1b195dc"></a>

Finds and returns the class input pin from the current set of pins.

#### `public UEdGraphPin * `[`GetResultPin`](#classUK2Node__FactorOperator_1a5a373cc9dec8e9950101b3e4795f0d76)`() const` <a id="classUK2Node__FactorOperator_1a5a373cc9dec8e9950101b3e4795f0d76"></a>

#### `public UEdGraphPin * `[`GetThenPin`](#classUK2Node__FactorOperator_1a4ddae61c346d63d0190c0114b40f94c4)`() const` <a id="classUK2Node__FactorOperator_1a4ddae61c346d63d0190c0114b40f94c4"></a>

#### `public UEdGraphPin * `[`GetOuterPin`](#classUK2Node__FactorOperator_1a54eafeebb68a110dd895eb34c8014e02)`() const` <a id="classUK2Node__FactorOperator_1a54eafeebb68a110dd895eb34c8014e02"></a>

#### `public inline UClass * `[`GetInputClass`](#classUK2Node__FactorOperator_1a652a8d57b22a73c086cb32663bba69cf)`() const` <a id="classUK2Node__FactorOperator_1a652a8d57b22a73c086cb32663bba69cf"></a>

Retrieves the current input class type.

#### `public void `[`OnBlueprintClassModified`](#classUK2Node__FactorOperator_1ab599f3c28dcd97430cc301c8c9c9ee3c)`(UBlueprint * TargetBlueprint)` <a id="classUK2Node__FactorOperator_1ab599f3c28dcd97430cc301c8c9c9ee3c"></a>

#### `public void `[`ClearDelegates`](#classUK2Node__FactorOperator_1a99e68cec308fa3c4991bf4f07bc11c61)`()` <a id="classUK2Node__FactorOperator_1a99e68cec308fa3c4991bf4f07bc11c61"></a>

#### `protected UEdGraphPin * `[`FindClassPin`](#classUK2Node__FactorOperator_1a999bea75bad83a53ecefcb828c7cf041)`(const TArray< UEdGraphPin * > & FromPins) const` <a id="classUK2Node__FactorOperator_1a999bea75bad83a53ecefcb828c7cf041"></a>

Finds and returns the class input pin.

#### Parameters
* `FromPins` A list of pins to search.

#### `protected UClass * `[`GetInputClass`](#classUK2Node__FactorOperator_1a888c0647555d013d49ad18eb34d36cac)`(const UEdGraphPin * FromPin) const` <a id="classUK2Node__FactorOperator_1a888c0647555d013d49ad18eb34d36cac"></a>

Determines the input class type from the given pin.

#### Parameters
* `FromPin` Input class pin.

#### `protected void `[`CreateNewPins`](#classUK2Node__FactorOperator_1aee3f14c4c58a1e94030bb6fa58487e60)`(UClass * InClass)` <a id="classUK2Node__FactorOperator_1aee3f14c4c58a1e94030bb6fa58487e60"></a>

Creates the full set of pins (properties) from the given input class.

#### Parameters
* `InClass` Input class type.

#### `protected void `[`OnClassPinChanged`](#classUK2Node__FactorOperator_1a707e58272062acef24fcf2034014cd21)`()` <a id="classUK2Node__FactorOperator_1a707e58272062acef24fcf2034014cd21"></a>

Will be called whenever the class pin selector changes its value.

# class `UMockObject` <a id="classUMockObject"></a>

```
class UMockObject
  : public UObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline void `[`SetMyWorld`](#classUMockObject_1a89fb5a5c78fbbfe7fa4d2c692461bd18)`(TSharedPtr< UWorld > World)` | 
`public inline virtual class UWorld * `[`GetWorld`](#classUMockObject_1a4c10dee80ddfc7fbdce27c57e4bfa8d6)`() const` | 

## Members

#### `public inline void `[`SetMyWorld`](#classUMockObject_1a89fb5a5c78fbbfe7fa4d2c692461bd18)`(TSharedPtr< UWorld > World)` <a id="classUMockObject_1a89fb5a5c78fbbfe7fa4d2c692461bd18"></a>

#### `public inline virtual class UWorld * `[`GetWorld`](#classUMockObject_1a4c10dee80ddfc7fbdce27c57e4bfa8d6)`() const` <a id="classUMockObject_1a4c10dee80ddfc7fbdce27c57e4bfa8d6"></a>

# class `UNFactorAdapterAbstract` <a id="classUNFactorAdapterAbstract"></a>

```
class UNFactorAdapterAbstract
  : public UObject
  : public NFactorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`FactorValue`](#classUNFactorAdapterAbstract_1a0e8e74a4d248caadadf074852b07c9cd) | 
`public float `[`Duration`](#classUNFactorAdapterAbstract_1a421efb06fdabdcdff355ceb7e0380564) | 
`public float `[`Delay`](#classUNFactorAdapterAbstract_1a2c1dc6b075ce89b2ed9ec869511c1011) | 
`public FName `[`Reason`](#classUNFactorAdapterAbstract_1a700115ff0f4d4c2d7323733894d90acc) | 
`public `[`FFactorStackAttribute`](#structFFactorStackAttribute)` `[`InStack`](#classUNFactorAdapterAbstract_1abc4945d9fb61ce1949d04aff8a72226e) | 
`public inline  `[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract_1a11f7a1aaa719ec1cdc993d5d5921037a)`()` | 
`public inline virtual void `[`Init`](#classUNFactorAdapterAbstract_1ad3cd1501a95ebc20c5cd3a62c90cc09c)`()` | 
`public inline virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classUNFactorAdapterAbstract_1a6cb4b2f0e5309443e32739e96085872d)`()` | 
`public inline virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetConfiguredOperator`](#classUNFactorAdapterAbstract_1aceb60634e2b24dc048e3932b3215b975)`() const` | 
`public inline virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetOperator`](#classUNFactorAdapterAbstract_1a32de5301dc6c8290f3699318afe313bd)`() const` | 
`public inline virtual float `[`GetFactorValue`](#classUNFactorAdapterAbstract_1a2bbd6149655559619618f04bd35c8b69)`() const` | 
`public inline virtual FName `[`GetReason`](#classUNFactorAdapterAbstract_1a7d5f668b22f5e14c4b39ebac38269430)`() const` | 
`public inline virtual bool `[`IsActivated`](#classUNFactorAdapterAbstract_1aba454ba04a61984062bb022824e6ce67)`() const` | 
`public inline virtual uint32 `[`GetUID`](#classUNFactorAdapterAbstract_1a3efc0ab3b14b6155aecf2d9fb1f2bb03)`() const` | 
`protected TSharedPtr< `[`NFactor`](#classNFactor)` > `[`Factor`](#classUNFactorAdapterAbstract_1ad3084b3d6ec528be360bf06bf79c5cfe) | 
`protected `[`UNFactorEventDecorator`](#classUNFactorEventDecorator)` * `[`Event`](#classUNFactorAdapterAbstract_1a3457af72cb3f51d47a1c92efac3c73bb) | 

## Members

#### `public float `[`FactorValue`](#classUNFactorAdapterAbstract_1a0e8e74a4d248caadadf074852b07c9cd) <a id="classUNFactorAdapterAbstract_1a0e8e74a4d248caadadf074852b07c9cd"></a>

#### `public float `[`Duration`](#classUNFactorAdapterAbstract_1a421efb06fdabdcdff355ceb7e0380564) <a id="classUNFactorAdapterAbstract_1a421efb06fdabdcdff355ceb7e0380564"></a>

#### `public float `[`Delay`](#classUNFactorAdapterAbstract_1a2c1dc6b075ce89b2ed9ec869511c1011) <a id="classUNFactorAdapterAbstract_1a2c1dc6b075ce89b2ed9ec869511c1011"></a>

#### `public FName `[`Reason`](#classUNFactorAdapterAbstract_1a700115ff0f4d4c2d7323733894d90acc) <a id="classUNFactorAdapterAbstract_1a700115ff0f4d4c2d7323733894d90acc"></a>

#### `public `[`FFactorStackAttribute`](#structFFactorStackAttribute)` `[`InStack`](#classUNFactorAdapterAbstract_1abc4945d9fb61ce1949d04aff8a72226e) <a id="classUNFactorAdapterAbstract_1abc4945d9fb61ce1949d04aff8a72226e"></a>

#### `public inline  `[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract_1a11f7a1aaa719ec1cdc993d5d5921037a)`()` <a id="classUNFactorAdapterAbstract_1a11f7a1aaa719ec1cdc993d5d5921037a"></a>

#### `public inline virtual void `[`Init`](#classUNFactorAdapterAbstract_1ad3cd1501a95ebc20c5cd3a62c90cc09c)`()` <a id="classUNFactorAdapterAbstract_1ad3cd1501a95ebc20c5cd3a62c90cc09c"></a>

#### `public inline virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classUNFactorAdapterAbstract_1a6cb4b2f0e5309443e32739e96085872d)`()` <a id="classUNFactorAdapterAbstract_1a6cb4b2f0e5309443e32739e96085872d"></a>

#### `public inline virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetConfiguredOperator`](#classUNFactorAdapterAbstract_1aceb60634e2b24dc048e3932b3215b975)`() const` <a id="classUNFactorAdapterAbstract_1aceb60634e2b24dc048e3932b3215b975"></a>

#### `public inline virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetOperator`](#classUNFactorAdapterAbstract_1a32de5301dc6c8290f3699318afe313bd)`() const` <a id="classUNFactorAdapterAbstract_1a32de5301dc6c8290f3699318afe313bd"></a>

#### `public inline virtual float `[`GetFactorValue`](#classUNFactorAdapterAbstract_1a2bbd6149655559619618f04bd35c8b69)`() const` <a id="classUNFactorAdapterAbstract_1a2bbd6149655559619618f04bd35c8b69"></a>

#### `public inline virtual FName `[`GetReason`](#classUNFactorAdapterAbstract_1a7d5f668b22f5e14c4b39ebac38269430)`() const` <a id="classUNFactorAdapterAbstract_1a7d5f668b22f5e14c4b39ebac38269430"></a>

#### `public inline virtual bool `[`IsActivated`](#classUNFactorAdapterAbstract_1aba454ba04a61984062bb022824e6ce67)`() const` <a id="classUNFactorAdapterAbstract_1aba454ba04a61984062bb022824e6ce67"></a>

#### `public inline virtual uint32 `[`GetUID`](#classUNFactorAdapterAbstract_1a3efc0ab3b14b6155aecf2d9fb1f2bb03)`() const` <a id="classUNFactorAdapterAbstract_1a3efc0ab3b14b6155aecf2d9fb1f2bb03"></a>

#### `protected TSharedPtr< `[`NFactor`](#classNFactor)` > `[`Factor`](#classUNFactorAdapterAbstract_1ad3084b3d6ec528be360bf06bf79c5cfe) <a id="classUNFactorAdapterAbstract_1ad3084b3d6ec528be360bf06bf79c5cfe"></a>

#### `protected `[`UNFactorEventDecorator`](#classUNFactorEventDecorator)` * `[`Event`](#classUNFactorAdapterAbstract_1a3457af72cb3f51d47a1c92efac3c73bb) <a id="classUNFactorAdapterAbstract_1a3457af72cb3f51d47a1c92efac3c73bb"></a>

# class `UNFactorAdapterBasic` <a id="classUNFactorAdapterBasic"></a>

```
class UNFactorAdapterBasic
  : public UNFactorAdapterAbstract
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`ENFactorOperator`](#FactorAdapters_8h_1ac0832918529efa40bbe65b8c54c4cf20)` `[`Operator`](#classUNFactorAdapterBasic_1af612bc210615099f14c584fc87037d1c) | 
`public inline virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetConfiguredOperator`](#classUNFactorAdapterBasic_1a3c1c0eae0a072df300b7d2d47085dd91)`() const` | 

## Members

#### `public `[`ENFactorOperator`](#FactorAdapters_8h_1ac0832918529efa40bbe65b8c54c4cf20)` `[`Operator`](#classUNFactorAdapterBasic_1af612bc210615099f14c584fc87037d1c) <a id="classUNFactorAdapterBasic_1af612bc210615099f14c584fc87037d1c"></a>

#### `public inline virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetConfiguredOperator`](#classUNFactorAdapterBasic_1a3c1c0eae0a072df300b7d2d47085dd91)`() const` <a id="classUNFactorAdapterBasic_1a3c1c0eae0a072df300b7d2d47085dd91"></a>

# class `UNFactorAdapterResetFromReason` <a id="classUNFactorAdapterResetFromReason"></a>

```
class UNFactorAdapterResetFromReason
  : public UNFactorAdapterAbstract
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`ReasonToReset`](#classUNFactorAdapterResetFromReason_1a74c39e3e6e3c16994a01489d81c94303) | 

## Members

#### `public FName `[`ReasonToReset`](#classUNFactorAdapterResetFromReason_1a74c39e3e6e3c16994a01489d81c94303) <a id="classUNFactorAdapterResetFromReason_1a74c39e3e6e3c16994a01489d81c94303"></a>

# class `UNFactorEventDecorator` <a id="classUNFactorEventDecorator"></a>

```
class UNFactorEventDecorator
  : public UNEventDecorator
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UNFactorEventDecorator`](#classUNFactorEventDecorator_1af02c54de62e737dc91a5f986012c844b)`()` | 

## Members

#### `public inline  `[`UNFactorEventDecorator`](#classUNFactorEventDecorator_1af02c54de62e737dc91a5f986012c844b)`()` <a id="classUNFactorEventDecorator_1af02c54de62e737dc91a5f986012c844b"></a>

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
`public void `[`Init`](#classUNFactorsFactoryClientAdapter_1ae232af08c5f91d5a428d09036e845c05)`()` | 
`public virtual void `[`CreateStack`](#classUNFactorsFactoryClientAdapter_1a161472f0233688a594aa84a2bd275cf9)`(FName StackName,TSharedPtr< NTimelineInterface > Timeline)` | 
`public virtual void `[`CreateStack`](#classUNFactorsFactoryClientAdapter_1aa353be4f630c1f692597582bf438cc89)`(TArray< FName > StackNames,TSharedPtr< NTimelineInterface > Timeline)` | 
`public virtual void `[`AddStack`](#classUNFactorsFactoryClientAdapter_1adde63733e603e138efca0890373d7d8f)`(TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > Stack)` | 
`public virtual void `[`RemoveStack`](#classUNFactorsFactoryClientAdapter_1a84486fbbe8fa5bfa362e2f1492a4f228)`(FName StackName)` | 
`public virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetState`](#classUNFactorsFactoryClientAdapter_1ae11edf7ecbc266246265d765bbceaee9)`(FName StackName)` | 
`public virtual TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classUNFactorsFactoryClientAdapter_1aac14278db2d4c5008b7aa6b5bd742820)`(TArray< FName > StackNames)` | 
`public virtual void `[`AddFactor`](#classUNFactorsFactoryClientAdapter_1ae0cdf01f75295ec16e8ea36af0d0d864)`(FName StackName,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public virtual void `[`AddFactor`](#classUNFactorsFactoryClientAdapter_1aa2f192548a0c59ece7bb8a09051e8d56)`(TArray< FName > StackNames,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public virtual void `[`SetDebug`](#classUNFactorsFactoryClientAdapter_1a017768670a500c620c024b526936e072)`(const TArray< FName > StackNames,bool bDebug)` | 
`protected TSharedPtr< `[`NFactorsFactoryClient`](#classNFactorsFactoryClient)` > `[`Client`](#classUNFactorsFactoryClientAdapter_1af67fcbc5cd85dc08876ce79ef1bab4ca) | 

## Members

#### `public  `[`UNFactorsFactoryClientAdapter`](#classUNFactorsFactoryClientAdapter_1a9c56d9300d9ca48e9b5e8dd8456a1677)`()` <a id="classUNFactorsFactoryClientAdapter_1a9c56d9300d9ca48e9b5e8dd8456a1677"></a>

#### `public void `[`Init`](#classUNFactorsFactoryClientAdapter_1ae232af08c5f91d5a428d09036e845c05)`()` <a id="classUNFactorsFactoryClientAdapter_1ae232af08c5f91d5a428d09036e845c05"></a>

#### `public virtual void `[`CreateStack`](#classUNFactorsFactoryClientAdapter_1a161472f0233688a594aa84a2bd275cf9)`(FName StackName,TSharedPtr< NTimelineInterface > Timeline)` <a id="classUNFactorsFactoryClientAdapter_1a161472f0233688a594aa84a2bd275cf9"></a>

#### `public virtual void `[`CreateStack`](#classUNFactorsFactoryClientAdapter_1aa353be4f630c1f692597582bf438cc89)`(TArray< FName > StackNames,TSharedPtr< NTimelineInterface > Timeline)` <a id="classUNFactorsFactoryClientAdapter_1aa353be4f630c1f692597582bf438cc89"></a>

#### `public virtual void `[`AddStack`](#classUNFactorsFactoryClientAdapter_1adde63733e603e138efca0890373d7d8f)`(TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > Stack)` <a id="classUNFactorsFactoryClientAdapter_1adde63733e603e138efca0890373d7d8f"></a>

#### `public virtual void `[`RemoveStack`](#classUNFactorsFactoryClientAdapter_1a84486fbbe8fa5bfa362e2f1492a4f228)`(FName StackName)` <a id="classUNFactorsFactoryClientAdapter_1a84486fbbe8fa5bfa362e2f1492a4f228"></a>

#### `public virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetState`](#classUNFactorsFactoryClientAdapter_1ae11edf7ecbc266246265d765bbceaee9)`(FName StackName)` <a id="classUNFactorsFactoryClientAdapter_1ae11edf7ecbc266246265d765bbceaee9"></a>

#### `public virtual TArray< `[`NFactorStateInterface`](#classNFactorStateInterface)` * > `[`GetStates`](#classUNFactorsFactoryClientAdapter_1aac14278db2d4c5008b7aa6b5bd742820)`(TArray< FName > StackNames)` <a id="classUNFactorsFactoryClientAdapter_1aac14278db2d4c5008b7aa6b5bd742820"></a>

#### `public virtual void `[`AddFactor`](#classUNFactorsFactoryClientAdapter_1ae0cdf01f75295ec16e8ea36af0d0d864)`(FName StackName,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classUNFactorsFactoryClientAdapter_1ae0cdf01f75295ec16e8ea36af0d0d864"></a>

#### `public virtual void `[`AddFactor`](#classUNFactorsFactoryClientAdapter_1aa2f192548a0c59ece7bb8a09051e8d56)`(TArray< FName > StackNames,TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classUNFactorsFactoryClientAdapter_1aa2f192548a0c59ece7bb8a09051e8d56"></a>

#### `public virtual void `[`SetDebug`](#classUNFactorsFactoryClientAdapter_1a017768670a500c620c024b526936e072)`(const TArray< FName > StackNames,bool bDebug)` <a id="classUNFactorsFactoryClientAdapter_1a017768670a500c620c024b526936e072"></a>

#### `protected TSharedPtr< `[`NFactorsFactoryClient`](#classNFactorsFactoryClient)` > `[`Client`](#classUNFactorsFactoryClientAdapter_1af67fcbc5cd85dc08876ce79ef1bab4ca) <a id="classUNFactorsFactoryClientAdapter_1af67fcbc5cd85dc08876ce79ef1bab4ca"></a>

# class `UNFactorsFactoryGameInstance` <a id="classUNFactorsFactoryGameInstance"></a>

```
class UNFactorsFactoryGameInstance
  : public UInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNFactorStackDecorator` <a id="classUNFactorStackDecorator"></a>

```
class UNFactorStackDecorator
  : public UObject
  : public NFactorStackInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UNFactorStackDecorator`](#classUNFactorStackDecorator_1af3d4765f75cc6b408a409374516f0dcc)`()` | 
`public inline void `[`Init`](#classUNFactorStackDecorator_1aff2839f6f3ceba43f0e6125048308984)`(FName _Name,TSharedPtr< NTimelineInterface > _Timeline)` | 
`public inline virtual void `[`Reset`](#classUNFactorStackDecorator_1a1ad9663926ef2f35ca0a196b5f3dadab)`()` | 
`public inline virtual void `[`SetName`](#classUNFactorStackDecorator_1ae0e91c1098a2f3d89f948f3f11707c80)`(FName _Name)` | 
`public inline virtual FName `[`GetName`](#classUNFactorStackDecorator_1a5c2511377803e094692664d3488dba4a)`() const` | 
`public inline virtual float `[`GetTime`](#classUNFactorStackDecorator_1a211c88f04912adee52ae2dc9bcf7dabb)`() const` | 
`public inline virtual TSharedRef< `[`NFactorInterface`](#classNFactorInterface)` > `[`GetFactor`](#classUNFactorStackDecorator_1ab2cb0d838bf790a89c4705d89ba66788)`(uint32 Key) const` | 
`public inline virtual TArray< TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`GetFactors`](#classUNFactorStackDecorator_1a5bdb23896d2906e0c85ef14cc0768f0c)`() const` | 
`public inline virtual void `[`AddFactor`](#classUNFactorStackDecorator_1a33ae8e9f954a8c78bc67cfc438d61419)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public inline virtual bool `[`HasFlag`](#classUNFactorStackDecorator_1a038483ea28e1953b99b2c62543aeb43c)`(FString Flag) const` | 
`public inline virtual bool `[`GetFlag`](#classUNFactorStackDecorator_1a85066be4f66fd2e70e61c5be43b6baf3)`(FString Flag) const` | 
`public inline virtual void `[`SetFlag`](#classUNFactorStackDecorator_1aca8d18dacb8ed3c94f252f3e25e9c588)`(FString Flag,bool Value)` | 
`public inline virtual void `[`Debug`](#classUNFactorStackDecorator_1aba378f8f409e4f1139f30c393f4e5a3f)`(bool _bDebug)` | 
`public inline virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetCurrentState`](#classUNFactorStackDecorator_1acbb1f50f6ba76e793b2bc38f11d9f481)`()` | 
`protected TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > `[`Stack`](#classUNFactorStackDecorator_1a25c45d18d80a7563cc29cd111d7fd795) | 

## Members

#### `public inline  `[`UNFactorStackDecorator`](#classUNFactorStackDecorator_1af3d4765f75cc6b408a409374516f0dcc)`()` <a id="classUNFactorStackDecorator_1af3d4765f75cc6b408a409374516f0dcc"></a>

#### `public inline void `[`Init`](#classUNFactorStackDecorator_1aff2839f6f3ceba43f0e6125048308984)`(FName _Name,TSharedPtr< NTimelineInterface > _Timeline)` <a id="classUNFactorStackDecorator_1aff2839f6f3ceba43f0e6125048308984"></a>

#### `public inline virtual void `[`Reset`](#classUNFactorStackDecorator_1a1ad9663926ef2f35ca0a196b5f3dadab)`()` <a id="classUNFactorStackDecorator_1a1ad9663926ef2f35ca0a196b5f3dadab"></a>

#### `public inline virtual void `[`SetName`](#classUNFactorStackDecorator_1ae0e91c1098a2f3d89f948f3f11707c80)`(FName _Name)` <a id="classUNFactorStackDecorator_1ae0e91c1098a2f3d89f948f3f11707c80"></a>

#### `public inline virtual FName `[`GetName`](#classUNFactorStackDecorator_1a5c2511377803e094692664d3488dba4a)`() const` <a id="classUNFactorStackDecorator_1a5c2511377803e094692664d3488dba4a"></a>

#### `public inline virtual float `[`GetTime`](#classUNFactorStackDecorator_1a211c88f04912adee52ae2dc9bcf7dabb)`() const` <a id="classUNFactorStackDecorator_1a211c88f04912adee52ae2dc9bcf7dabb"></a>

#### `public inline virtual TSharedRef< `[`NFactorInterface`](#classNFactorInterface)` > `[`GetFactor`](#classUNFactorStackDecorator_1ab2cb0d838bf790a89c4705d89ba66788)`(uint32 Key) const` <a id="classUNFactorStackDecorator_1ab2cb0d838bf790a89c4705d89ba66788"></a>

#### `public inline virtual TArray< TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`GetFactors`](#classUNFactorStackDecorator_1a5bdb23896d2906e0c85ef14cc0768f0c)`() const` <a id="classUNFactorStackDecorator_1a5bdb23896d2906e0c85ef14cc0768f0c"></a>

#### `public inline virtual void `[`AddFactor`](#classUNFactorStackDecorator_1a33ae8e9f954a8c78bc67cfc438d61419)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classUNFactorStackDecorator_1a33ae8e9f954a8c78bc67cfc438d61419"></a>

#### `public inline virtual bool `[`HasFlag`](#classUNFactorStackDecorator_1a038483ea28e1953b99b2c62543aeb43c)`(FString Flag) const` <a id="classUNFactorStackDecorator_1a038483ea28e1953b99b2c62543aeb43c"></a>

#### `public inline virtual bool `[`GetFlag`](#classUNFactorStackDecorator_1a85066be4f66fd2e70e61c5be43b6baf3)`(FString Flag) const` <a id="classUNFactorStackDecorator_1a85066be4f66fd2e70e61c5be43b6baf3"></a>

#### `public inline virtual void `[`SetFlag`](#classUNFactorStackDecorator_1aca8d18dacb8ed3c94f252f3e25e9c588)`(FString Flag,bool Value)` <a id="classUNFactorStackDecorator_1aca8d18dacb8ed3c94f252f3e25e9c588"></a>

#### `public inline virtual void `[`Debug`](#classUNFactorStackDecorator_1aba378f8f409e4f1139f30c393f4e5a3f)`(bool _bDebug)` <a id="classUNFactorStackDecorator_1aba378f8f409e4f1139f30c393f4e5a3f"></a>

#### `public inline virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetCurrentState`](#classUNFactorStackDecorator_1acbb1f50f6ba76e793b2bc38f11d9f481)`()` <a id="classUNFactorStackDecorator_1acbb1f50f6ba76e793b2bc38f11d9f481"></a>

#### `protected TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > `[`Stack`](#classUNFactorStackDecorator_1a25c45d18d80a7563cc29cd111d7fd795) <a id="classUNFactorStackDecorator_1a25c45d18d80a7563cc29cd111d7fd795"></a>

# class `UNFakeFactorsFactoryClient` <a id="classUNFakeFactorsFactoryClient"></a>

```
class UNFakeFactorsFactoryClient
  : public NFactorsFactoryClient
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline TMap< FName, TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > > `[`GetStack`](#classUNFakeFactorsFactoryClient_1a3c7f07d025318c2470a0b7236de87af2)`()` | 
`public inline void `[`Reset`](#classUNFakeFactorsFactoryClient_1adb4edbfedf44d87d422144ae76c68e42)`()` | 

## Members

#### `public inline TMap< FName, TSharedPtr< `[`NFactorStackInterface`](#classNFactorStackInterface)` > > `[`GetStack`](#classUNFakeFactorsFactoryClient_1a3c7f07d025318c2470a0b7236de87af2)`()` <a id="classUNFakeFactorsFactoryClient_1a3c7f07d025318c2470a0b7236de87af2"></a>

#### `public inline void `[`Reset`](#classUNFakeFactorsFactoryClient_1adb4edbfedf44d87d422144ae76c68e42)`()` <a id="classUNFakeFactorsFactoryClient_1adb4edbfedf44d87d422144ae76c68e42"></a>

# class `UnrealFactorProxy` <a id="classUnrealFactorProxy"></a>

```
class UnrealFactorProxy
  : public NFactorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract)` & `[`Factor`](#classUnrealFactorProxy_1add91851130c1d72924db4216753d1557) | 
`public inline  `[`UnrealFactorProxy`](#classUnrealFactorProxy_1a2c06a9a27ba52f2d9361e39d98527920)`(`[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract)` & _Factor)` | 
`public inline virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetOperator`](#classUnrealFactorProxy_1a0d43675dfe47e0532bb27b49a81ac05f)`() const` | 
`public inline virtual float `[`GetFactorValue`](#classUnrealFactorProxy_1ab9dcce6e38a685cfdfc6599acaa8cb79)`() const` | 
`public inline virtual FName `[`GetReason`](#classUnrealFactorProxy_1a1117decfed06c52a3e15132b28df4afd)`() const` | 
`public inline virtual bool `[`IsActivated`](#classUnrealFactorProxy_1ac0954b19b6e125ae4657a83742a06adf)`() const` | 
`public inline virtual uint32 `[`GetUID`](#classUnrealFactorProxy_1a822d0d752f81bc0f854c181c96b446ab)`() const` | 
`public inline virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classUnrealFactorProxy_1a0e037d6430ad22a6080e2ba5f1c61071)`()` | 

## Members

#### `public `[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract)` & `[`Factor`](#classUnrealFactorProxy_1add91851130c1d72924db4216753d1557) <a id="classUnrealFactorProxy_1add91851130c1d72924db4216753d1557"></a>

#### `public inline  `[`UnrealFactorProxy`](#classUnrealFactorProxy_1a2c06a9a27ba52f2d9361e39d98527920)`(`[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract)` & _Factor)` <a id="classUnrealFactorProxy_1a2c06a9a27ba52f2d9361e39d98527920"></a>

#### `public inline virtual TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`GetOperator`](#classUnrealFactorProxy_1a0d43675dfe47e0532bb27b49a81ac05f)`() const` <a id="classUnrealFactorProxy_1a0d43675dfe47e0532bb27b49a81ac05f"></a>

#### `public inline virtual float `[`GetFactorValue`](#classUnrealFactorProxy_1ab9dcce6e38a685cfdfc6599acaa8cb79)`() const` <a id="classUnrealFactorProxy_1ab9dcce6e38a685cfdfc6599acaa8cb79"></a>

#### `public inline virtual FName `[`GetReason`](#classUnrealFactorProxy_1a1117decfed06c52a3e15132b28df4afd)`() const` <a id="classUnrealFactorProxy_1a1117decfed06c52a3e15132b28df4afd"></a>

#### `public inline virtual bool `[`IsActivated`](#classUnrealFactorProxy_1ac0954b19b6e125ae4657a83742a06adf)`() const` <a id="classUnrealFactorProxy_1ac0954b19b6e125ae4657a83742a06adf"></a>

#### `public inline virtual uint32 `[`GetUID`](#classUnrealFactorProxy_1a822d0d752f81bc0f854c181c96b446ab)`() const` <a id="classUnrealFactorProxy_1a822d0d752f81bc0f854c181c96b446ab"></a>

#### `public inline virtual TSharedPtr< NEventInterface > `[`GetEvent`](#classUnrealFactorProxy_1a0e037d6430ad22a6080e2ba5f1c61071)`()` <a id="classUnrealFactorProxy_1a0e037d6430ad22a6080e2ba5f1c61071"></a>

# class `UNUnrealFactorStackProxy` <a id="classUNUnrealFactorStackProxy"></a>

```
class UNUnrealFactorStackProxy
  : public NFactorStackInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNFactorStackDecorator`](#classUNFactorStackDecorator)` & `[`Stack`](#classUNUnrealFactorStackProxy_1a07705431dc35be4cc1645dc5f73f0289) | 
`public inline  `[`UNUnrealFactorStackProxy`](#classUNUnrealFactorStackProxy_1a1ddaaa1b85a4b5296c766c6037207a35)`(`[`UNFactorStackDecorator`](#classUNFactorStackDecorator)` & _Stack)` | 
`public inline virtual void `[`Reset`](#classUNUnrealFactorStackProxy_1a518a29a44b57f39cbfff5a97a4821986)`()` | 
`public inline virtual void `[`SetName`](#classUNUnrealFactorStackProxy_1aca95adc16b7c80ae91e890199096f92f)`(FName _Name)` | 
`public inline virtual FName `[`GetName`](#classUNUnrealFactorStackProxy_1af8933bb3bbe5852cda31126c842533a0)`() const` | 
`public inline virtual float `[`GetTime`](#classUNUnrealFactorStackProxy_1a036a22776d9482319abcf67948b847ec)`() const` | 
`public inline virtual TSharedRef< `[`NFactorInterface`](#classNFactorInterface)` > `[`GetFactor`](#classUNUnrealFactorStackProxy_1ae2820f8ebb7b1beefe833772ddb4e1f1)`(uint32 Key) const` | 
`public inline virtual TArray< TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`GetFactors`](#classUNUnrealFactorStackProxy_1a41d477db088e837d023f587dd769b55a)`() const` | 
`public inline virtual void `[`AddFactor`](#classUNUnrealFactorStackProxy_1a8d85281156677b5b3a70510a3dfd8cff)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` | 
`public inline virtual bool `[`HasFlag`](#classUNUnrealFactorStackProxy_1a4a963743d7a83d3bcde31c757ad6a9fd)`(FString Flag) const` | 
`public inline virtual bool `[`GetFlag`](#classUNUnrealFactorStackProxy_1a1d2785a6ad2f73261ca4af168142b4c6)`(FString Flag) const` | 
`public inline virtual void `[`SetFlag`](#classUNUnrealFactorStackProxy_1aae2f415a1303f79498344aa014dbccbe)`(FString Flag,bool Value)` | 
`public inline virtual void `[`Debug`](#classUNUnrealFactorStackProxy_1a39c04d60430ce77d56c3fe892fe32e2a)`(bool _bDebug)` | 
`public inline virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetCurrentState`](#classUNUnrealFactorStackProxy_1a004f1259066e2b491ae0815d87b1cf75)`()` | 

## Members

#### `public `[`UNFactorStackDecorator`](#classUNFactorStackDecorator)` & `[`Stack`](#classUNUnrealFactorStackProxy_1a07705431dc35be4cc1645dc5f73f0289) <a id="classUNUnrealFactorStackProxy_1a07705431dc35be4cc1645dc5f73f0289"></a>

#### `public inline  `[`UNUnrealFactorStackProxy`](#classUNUnrealFactorStackProxy_1a1ddaaa1b85a4b5296c766c6037207a35)`(`[`UNFactorStackDecorator`](#classUNFactorStackDecorator)` & _Stack)` <a id="classUNUnrealFactorStackProxy_1a1ddaaa1b85a4b5296c766c6037207a35"></a>

#### `public inline virtual void `[`Reset`](#classUNUnrealFactorStackProxy_1a518a29a44b57f39cbfff5a97a4821986)`()` <a id="classUNUnrealFactorStackProxy_1a518a29a44b57f39cbfff5a97a4821986"></a>

#### `public inline virtual void `[`SetName`](#classUNUnrealFactorStackProxy_1aca95adc16b7c80ae91e890199096f92f)`(FName _Name)` <a id="classUNUnrealFactorStackProxy_1aca95adc16b7c80ae91e890199096f92f"></a>

#### `public inline virtual FName `[`GetName`](#classUNUnrealFactorStackProxy_1af8933bb3bbe5852cda31126c842533a0)`() const` <a id="classUNUnrealFactorStackProxy_1af8933bb3bbe5852cda31126c842533a0"></a>

#### `public inline virtual float `[`GetTime`](#classUNUnrealFactorStackProxy_1a036a22776d9482319abcf67948b847ec)`() const` <a id="classUNUnrealFactorStackProxy_1a036a22776d9482319abcf67948b847ec"></a>

#### `public inline virtual TSharedRef< `[`NFactorInterface`](#classNFactorInterface)` > `[`GetFactor`](#classUNUnrealFactorStackProxy_1ae2820f8ebb7b1beefe833772ddb4e1f1)`(uint32 Key) const` <a id="classUNUnrealFactorStackProxy_1ae2820f8ebb7b1beefe833772ddb4e1f1"></a>

#### `public inline virtual TArray< TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > > `[`GetFactors`](#classUNUnrealFactorStackProxy_1a41d477db088e837d023f587dd769b55a)`() const` <a id="classUNUnrealFactorStackProxy_1a41d477db088e837d023f587dd769b55a"></a>

#### `public inline virtual void `[`AddFactor`](#classUNUnrealFactorStackProxy_1a8d85281156677b5b3a70510a3dfd8cff)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > Factor)` <a id="classUNUnrealFactorStackProxy_1a8d85281156677b5b3a70510a3dfd8cff"></a>

#### `public inline virtual bool `[`HasFlag`](#classUNUnrealFactorStackProxy_1a4a963743d7a83d3bcde31c757ad6a9fd)`(FString Flag) const` <a id="classUNUnrealFactorStackProxy_1a4a963743d7a83d3bcde31c757ad6a9fd"></a>

#### `public inline virtual bool `[`GetFlag`](#classUNUnrealFactorStackProxy_1a1d2785a6ad2f73261ca4af168142b4c6)`(FString Flag) const` <a id="classUNUnrealFactorStackProxy_1a1d2785a6ad2f73261ca4af168142b4c6"></a>

#### `public inline virtual void `[`SetFlag`](#classUNUnrealFactorStackProxy_1aae2f415a1303f79498344aa014dbccbe)`(FString Flag,bool Value)` <a id="classUNUnrealFactorStackProxy_1aae2f415a1303f79498344aa014dbccbe"></a>

#### `public inline virtual void `[`Debug`](#classUNUnrealFactorStackProxy_1a39c04d60430ce77d56c3fe892fe32e2a)`(bool _bDebug)` <a id="classUNUnrealFactorStackProxy_1a39c04d60430ce77d56c3fe892fe32e2a"></a>

#### `public inline virtual `[`NFactorStateInterface`](#classNFactorStateInterface)` * `[`GetCurrentState`](#classUNUnrealFactorStackProxy_1a004f1259066e2b491ae0815d87b1cf75)`()` <a id="classUNUnrealFactorStackProxy_1a004f1259066e2b491ae0815d87b1cf75"></a>

# struct `FFactorStackAttribute` <a id="structFFactorStackAttribute"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFFactorStackAttribute_1a5b36a6efb43b4d539f9ecb5e23709bea) | 
`public inline  `[`FFactorStackAttribute`](#structFFactorStackAttribute_1ad85bf0490c5b5b902ad95d87a2c7e2e5)`()` | 
`public inline  `[`FFactorStackAttribute`](#structFFactorStackAttribute_1acd00d8398d1c3673cc0ae3791baedd1f)`(FName _Name)` | 

## Members

#### `public FName `[`Name`](#structFFactorStackAttribute_1a5b36a6efb43b4d539f9ecb5e23709bea) <a id="structFFactorStackAttribute_1a5b36a6efb43b4d539f9ecb5e23709bea"></a>

#### `public inline  `[`FFactorStackAttribute`](#structFFactorStackAttribute_1ad85bf0490c5b5b902ad95d87a2c7e2e5)`()` <a id="structFFactorStackAttribute_1ad85bf0490c5b5b902ad95d87a2c7e2e5"></a>

#### `public inline  `[`FFactorStackAttribute`](#structFFactorStackAttribute_1acd00d8398d1c3673cc0ae3791baedd1f)`(FName _Name)` <a id="structFFactorStackAttribute_1acd00d8398d1c3673cc0ae3791baedd1f"></a>

# struct `FNFactorSettings` <a id="structFNFactorSettings"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFNFactorSettings_1acedd2d410195b0d363964dc2bc1e2e8c) | 
`public FName `[`TimelineName`](#structFNFactorSettings_1a09235f8b2ab0a80f2d23cb2db5f8cd61) | 

## Members

#### `public FName `[`Name`](#structFNFactorSettings_1acedd2d410195b0d363964dc2bc1e2e8c) <a id="structFNFactorSettings_1acedd2d410195b0d363964dc2bc1e2e8c"></a>

#### `public FName `[`TimelineName`](#structFNFactorSettings_1a09235f8b2ab0a80f2d23cb2db5f8cd61) <a id="structFNFactorSettings_1a09235f8b2ab0a80f2d23cb2db5f8cd61"></a>

# struct `FNFactorStateOperator` <a id="structFNFactorStateOperator"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > `[`Factor`](#structFNFactorStateOperator_1a869c40b47f97700d1c1031e2038cef2f) | 
`public float `[`Value`](#structFNFactorStateOperator_1a3de7a16e2324002ed5f48741c69bc8fe) | 
`public FName `[`Reason`](#structFNFactorStateOperator_1af8c21a16835a0f2ab9cd94c48454824f) | 
`public bool `[`Activate`](#structFNFactorStateOperator_1af2d735e5c96ee54b8f90a30aa5213485) | 
`public TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`Operator`](#structFNFactorStateOperator_1a8163e4b01b170b3373d1ebac49ba6261) | 
`public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1a62b4b9fcc006a27ce02977be4e0e066d)`()` | 
`public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1a45aeecede34f48917d59350c2d116f1b)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > _Factor)` | 

## Members

#### `public TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > `[`Factor`](#structFNFactorStateOperator_1a869c40b47f97700d1c1031e2038cef2f) <a id="structFNFactorStateOperator_1a869c40b47f97700d1c1031e2038cef2f"></a>

#### `public float `[`Value`](#structFNFactorStateOperator_1a3de7a16e2324002ed5f48741c69bc8fe) <a id="structFNFactorStateOperator_1a3de7a16e2324002ed5f48741c69bc8fe"></a>

#### `public FName `[`Reason`](#structFNFactorStateOperator_1af8c21a16835a0f2ab9cd94c48454824f) <a id="structFNFactorStateOperator_1af8c21a16835a0f2ab9cd94c48454824f"></a>

#### `public bool `[`Activate`](#structFNFactorStateOperator_1af2d735e5c96ee54b8f90a30aa5213485) <a id="structFNFactorStateOperator_1af2d735e5c96ee54b8f90a30aa5213485"></a>

#### `public TSharedPtr< `[`FactorOperatorInterface`](#classFactorOperatorInterface)` > `[`Operator`](#structFNFactorStateOperator_1a8163e4b01b170b3373d1ebac49ba6261) <a id="structFNFactorStateOperator_1a8163e4b01b170b3373d1ebac49ba6261"></a>

#### `public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1a62b4b9fcc006a27ce02977be4e0e066d)`()` <a id="structFNFactorStateOperator_1a62b4b9fcc006a27ce02977be4e0e066d"></a>

#### `public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1a45aeecede34f48917d59350c2d116f1b)`(TSharedPtr< `[`NFactorInterface`](#classNFactorInterface)` > _Factor)` <a id="structFNFactorStateOperator_1a45aeecede34f48917d59350c2d116f1b"></a>

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

Generated by [Moxygen](https://sourcey.com/moxygen)