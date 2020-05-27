# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`FakeFactorStack`](#classFakeFactorStack) | 
`class `[`FakeResetOperator`](#classFakeResetOperator) | 
`class `[`FNansFactorsFactoryCoreModule`](#classFNansFactorsFactoryCoreModule) | 
`class `[`FNansFactorsFactoryUE4Module`](#classFNansFactorsFactoryUE4Module) | 
`class `[`FNFactorSettingsPinFactory`](#classFNFactorSettingsPinFactory) | 
`class `[`IFactorOperator`](#classIFactorOperator) | 
`class `[`IFactorOperatorWithStack`](#classIFactorOperatorWithStack) | 
`class `[`INFactorInterface`](#classINFactorInterface) | 
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
`class `[`NFactorsFactoryClient`](#classNFactorsFactoryClient) | 
`class `[`NFactorStack`](#classNFactorStack) | 
`class `[`NFactorState`](#classNFactorState) | 
`class `[`NMultiplyOperator`](#classNMultiplyOperator) | 
`class `[`NNullFactorState`](#classNNullFactorState) | 
`class `[`NNullOperator`](#classNNullOperator) | 
`class `[`NResetOperator`](#classNResetOperator) | 
`class `[`NResetOperatorBase`](#classNResetOperatorBase) | 
`class `[`NSubsctractOperator`](#classNSubsctractOperator) | 
`class `[`OperatorUtils`](#classOperatorUtils) | 
`class `[`SNFactorSettingsPin`](#classSNFactorSettingsPin) | 
`class `[`UFactorSettings`](#classUFactorSettings) | This allow to Thanks to: [https://forums.unrealengine.com/development-discussion/c-gameplay-programming/1503868-adding-a-custom-ini-file](https://forums.unrealengine.com/development-discussion/c-gameplay-programming/1503868-adding-a-custom-ini-file)
`class `[`UK2Node_FactorOperator`](#classUK2Node__FactorOperator) | 
`class `[`UMockGameInstance`](#classUMockGameInstance) | 
`class `[`UMockObject`](#classUMockObject) | 
`class `[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract) | 
`class `[`UNFactorAdapterBasic`](#classUNFactorAdapterBasic) | 
`class `[`UNFactorAdapterResetFromReason`](#classUNFactorAdapterResetFromReason) | 
`class `[`UNFactorClientAdapter`](#classUNFactorClientAdapter) | 
`class `[`UNFactorFactory`](#classUNFactorFactory) | 
`class `[`UNFactorsFactoryGameInstance`](#classUNFactorsFactoryGameInstance) | 
`class `[`UNFakeFactorsFactoryClient`](#classUNFakeFactorsFactoryClient) | 
`struct `[`FNFactorSettings`](#structFNFactorSettings) | 
`struct `[`FNFactorStateOperator`](#structFNFactorStateOperator) | 
`struct `[`FNFactorStateResult`](#structFNFactorStateResult) | 

# class `FakeFactorStack` <a id="classFakeFactorStack"></a>

```
class FakeFactorStack
  : public NFactorStack
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`FakeFactorStack`](#classFakeFactorStack_1a497c8e00840ed121b6d0bab0013bcfe5)`(FName _Name,TSharedPtr< NTimeline > _Timeline)` | 
`public inline virtual `[`NFactorState`](#classNFactorState)` * `[`GetCurrentState`](#classFakeFactorStack_1a57d75c1af93d5982c16d1371533c2a50)`()` | 

## Members

#### `public inline  `[`FakeFactorStack`](#classFakeFactorStack_1a497c8e00840ed121b6d0bab0013bcfe5)`(FName _Name,TSharedPtr< NTimeline > _Timeline)` <a id="classFakeFactorStack_1a497c8e00840ed121b6d0bab0013bcfe5"></a>

#### `public inline virtual `[`NFactorState`](#classNFactorState)` * `[`GetCurrentState`](#classFakeFactorStack_1a57d75c1af93d5982c16d1371533c2a50)`()` <a id="classFakeFactorStack_1a57d75c1af93d5982c16d1371533c2a50"></a>

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

# class `IFactorOperator` <a id="classIFactorOperator"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`Compute`](#classIFactorOperator_1ac0f70c996d754f42a9c1ceafae24ac28)`(float Lh,float Rh)` | 
`public `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classIFactorOperator_1a836816487117d94837ca5f850c5a4501)`()` | 
`public const FName `[`GetName`](#classIFactorOperator_1a0a89af52af01f140fac9034f1889b90d)`()` | 
`public inline virtual void `[`InIteration`](#classIFactorOperator_1ace914b2d47c904a983c2310b2f3d9de1)`(`[`NFactorStack`](#classNFactorStack)` * Stack)` | 

## Members

#### `public float `[`Compute`](#classIFactorOperator_1ac0f70c996d754f42a9c1ceafae24ac28)`(float Lh,float Rh)` <a id="classIFactorOperator_1ac0f70c996d754f42a9c1ceafae24ac28"></a>

#### `public `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classIFactorOperator_1a836816487117d94837ca5f850c5a4501)`()` <a id="classIFactorOperator_1a836816487117d94837ca5f850c5a4501"></a>

#### `public const FName `[`GetName`](#classIFactorOperator_1a0a89af52af01f140fac9034f1889b90d)`()` <a id="classIFactorOperator_1a0a89af52af01f140fac9034f1889b90d"></a>

#### `public inline virtual void `[`InIteration`](#classIFactorOperator_1ace914b2d47c904a983c2310b2f3d9de1)`(`[`NFactorStack`](#classNFactorStack)` * Stack)` <a id="classIFactorOperator_1ace914b2d47c904a983c2310b2f3d9de1"></a>

# class `IFactorOperatorWithStack` <a id="classIFactorOperatorWithStack"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`SetStack`](#classIFactorOperatorWithStack_1a2a721c24acfc3ffe1b25a0d1a6837388)`(`[`NFactorStack`](#classNFactorStack)` * Stack)` | 
`public void `[`SetKeyInStack`](#classIFactorOperatorWithStack_1a3cbc8f33ae5b66726a77de3d62275ba8)`(uint32 Key)` | 

## Members

#### `public void `[`SetStack`](#classIFactorOperatorWithStack_1a2a721c24acfc3ffe1b25a0d1a6837388)`(`[`NFactorStack`](#classNFactorStack)` * Stack)` <a id="classIFactorOperatorWithStack_1a2a721c24acfc3ffe1b25a0d1a6837388"></a>

#### `public void `[`SetKeyInStack`](#classIFactorOperatorWithStack_1a3cbc8f33ae5b66726a77de3d62275ba8)`(uint32 Key)` <a id="classIFactorOperatorWithStack_1a3cbc8f33ae5b66726a77de3d62275ba8"></a>

# class `INFactorInterface` <a id="classINFactorInterface"></a>

```
class INFactorInterface
  : public NTimelineEventBase
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`IFactorOperator`](#classIFactorOperator)` * `[`GetOperator`](#classINFactorInterface_1a5554a70cdea61a0aa284cc730d49c4a6)`() const` | 
`public float `[`GetFactorValue`](#classINFactorInterface_1a87a9f03e50590aa49b0ab6287a68c579)`() const` | 
`public FName `[`GetReason`](#classINFactorInterface_1accc2f634e428fdf9a560f14fc77f14cc)`() const` | 
`public bool `[`IsActivated`](#classINFactorInterface_1a3bafb74994bbd904cd0be1720fe9cbcd)`() const` | 
`public void `[`AddTime`](#classINFactorInterface_1a3dd748cecb231143cffd3d53b6e58f28)`(float Time)` | 
`public uint32 `[`GetUID`](#classINFactorInterface_1af915977c5ee7e6db2b25d5f17fc7dcc1)`() const` | 

## Members

#### `public `[`IFactorOperator`](#classIFactorOperator)` * `[`GetOperator`](#classINFactorInterface_1a5554a70cdea61a0aa284cc730d49c4a6)`() const` <a id="classINFactorInterface_1a5554a70cdea61a0aa284cc730d49c4a6"></a>

#### `public float `[`GetFactorValue`](#classINFactorInterface_1a87a9f03e50590aa49b0ab6287a68c579)`() const` <a id="classINFactorInterface_1a87a9f03e50590aa49b0ab6287a68c579"></a>

#### `public FName `[`GetReason`](#classINFactorInterface_1accc2f634e428fdf9a560f14fc77f14cc)`() const` <a id="classINFactorInterface_1accc2f634e428fdf9a560f14fc77f14cc"></a>

#### `public bool `[`IsActivated`](#classINFactorInterface_1a3bafb74994bbd904cd0be1720fe9cbcd)`() const` <a id="classINFactorInterface_1a3bafb74994bbd904cd0be1720fe9cbcd"></a>

#### `public void `[`AddTime`](#classINFactorInterface_1a3dd748cecb231143cffd3d53b6e58f28)`(float Time)` <a id="classINFactorInterface_1a3dd748cecb231143cffd3d53b6e58f28"></a>

#### `public uint32 `[`GetUID`](#classINFactorInterface_1af915977c5ee7e6db2b25d5f17fc7dcc1)`() const` <a id="classINFactorInterface_1af915977c5ee7e6db2b25d5f17fc7dcc1"></a>

# class `INFactorsFactoryGameInstance` <a id="classINFactorsFactoryGameInstance"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNFactorClientAdapter`](#classUNFactorClientAdapter)` * `[`GetFactorsFactoryClient`](#classINFactorsFactoryGameInstance_1a44dca0bd320cb368801d6e1f860af8d3)`() const` | 

## Members

#### `public `[`UNFactorClientAdapter`](#classUNFactorClientAdapter)` * `[`GetFactorsFactoryClient`](#classINFactorsFactoryGameInstance_1a44dca0bd320cb368801d6e1f860af8d3)`() const` <a id="classINFactorsFactoryGameInstance_1a44dca0bd320cb368801d6e1f860af8d3"></a>

# class `MockTimelineManager` <a id="classMockTimelineManager"></a>

```
class MockTimelineManager
  : public NTimelineManagerBase
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `NAddOperator` <a id="classNAddOperator"></a>

```
class NAddOperator
  : public IFactorOperator
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNAddOperator_1a5de4bacf334d15d62cc758944938dead)`(float Lh,float Rh)` | 
`public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNAddOperator_1a13cd805d45b572debe157ce1f6cc8b75)`()` | 
`public inline virtual const FName `[`GetName`](#classNAddOperator_1a53a8a7c8fb4e8f3f1787d933a05a8c4d)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNAddOperator_1a5de4bacf334d15d62cc758944938dead)`(float Lh,float Rh)` <a id="classNAddOperator_1a5de4bacf334d15d62cc758944938dead"></a>

#### `public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNAddOperator_1a13cd805d45b572debe157ce1f6cc8b75)`()` <a id="classNAddOperator_1a13cd805d45b572debe157ce1f6cc8b75"></a>

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
`protected `[`FakeFactorStack`](#classFakeFactorStack)` * `[`FactorStack`](#classNansFactorsFactoryCoreResetOperatorTest_1ad9aeb7c6c7494c088f0243d0edc3a044) | 
`protected NTimeline * `[`Timeline`](#classNansFactorsFactoryCoreResetOperatorTest_1a8c064e3886c7d4a4e8faa1d985883068) | 
`protected inline void `[`SetUp`](#classNansFactorsFactoryCoreResetOperatorTest_1ad6bb36d7f5822aeab63bd038a8b39321)`()` | 
`protected inline void `[`TearDown`](#classNansFactorsFactoryCoreResetOperatorTest_1a3524ca6c4518ab1923b1a2b28e748287)`()` | 

## Members

#### `protected `[`FakeFactorStack`](#classFakeFactorStack)` * `[`FactorStack`](#classNansFactorsFactoryCoreResetOperatorTest_1ad9aeb7c6c7494c088f0243d0edc3a044) <a id="classNansFactorsFactoryCoreResetOperatorTest_1ad9aeb7c6c7494c088f0243d0edc3a044"></a>

#### `protected NTimeline * `[`Timeline`](#classNansFactorsFactoryCoreResetOperatorTest_1a8c064e3886c7d4a4e8faa1d985883068) <a id="classNansFactorsFactoryCoreResetOperatorTest_1a8c064e3886c7d4a4e8faa1d985883068"></a>

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
`protected `[`NFactorStack`](#classNFactorStack)` * `[`FactorStack`](#classNansFactorsFactoryCoreStackTest_1a235af246fe7d460ff85f84bfbcd9b74d) | 
`protected NTimeline * `[`Timeline`](#classNansFactorsFactoryCoreStackTest_1a926eceb2d69e792cfff88bcf8003c2d6) | 
`protected inline void `[`SetUp`](#classNansFactorsFactoryCoreStackTest_1ad4b4371c0cc111b52f2232e7e5f255b5)`()` | 
`protected inline void `[`TearDown`](#classNansFactorsFactoryCoreStackTest_1acba841acf31d8f9444e4aa77dcc7604e)`()` | 

## Members

#### `protected `[`NFactorStack`](#classNFactorStack)` * `[`FactorStack`](#classNansFactorsFactoryCoreStackTest_1a235af246fe7d460ff85f84bfbcd9b74d) <a id="classNansFactorsFactoryCoreStackTest_1a235af246fe7d460ff85f84bfbcd9b74d"></a>

#### `protected NTimeline * `[`Timeline`](#classNansFactorsFactoryCoreStackTest_1a926eceb2d69e792cfff88bcf8003c2d6) <a id="classNansFactorsFactoryCoreStackTest_1a926eceb2d69e792cfff88bcf8003c2d6"></a>

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
  : public IFactorOperator
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNDividerOperator_1aba31fb472867515a6a554ea528aee149)`(float Lh,float Rh)` | 
`public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNDividerOperator_1a490bbf3adc74a6ea236c9a9e7e6eb4e9)`()` | 
`public inline virtual const FName `[`GetName`](#classNDividerOperator_1a22f6ea3308e67ae0c65d97f90f6dd414)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNDividerOperator_1aba31fb472867515a6a554ea528aee149)`(float Lh,float Rh)` <a id="classNDividerOperator_1aba31fb472867515a6a554ea528aee149"></a>

#### `public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNDividerOperator_1a490bbf3adc74a6ea236c9a9e7e6eb4e9)`()` <a id="classNDividerOperator_1a490bbf3adc74a6ea236c9a9e7e6eb4e9"></a>

#### `public inline virtual const FName `[`GetName`](#classNDividerOperator_1a22f6ea3308e67ae0c65d97f90f6dd414)`()` <a id="classNDividerOperator_1a22f6ea3308e67ae0c65d97f90f6dd414"></a>

# class `NFactor` <a id="classNFactor"></a>

```
class NFactor
  : public INFactorInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NFactor`](#classNFactor_1a7aade0c397029399481eef496898e020)`(float _FactorValue,`[`IFactorOperator`](#classIFactorOperator)` * _Operator,float _Duration,FName Reason,float _Delay)` | 
`public virtual bool `[`IsActivated`](#classNFactor_1ae4d6bf09600c7c2cb92fcd98bbce7913)`() const` | 
`public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetOperator`](#classNFactor_1ab6ec016f4168b8ce0b96932049f60e1d)`() const` | 
`public virtual float `[`GetFactorValue`](#classNFactor_1aaa0e436924fceddb031fbe2e5828c814)`() const` | 
`public virtual FName `[`GetReason`](#classNFactor_1ae2de6106daf773494393f49c73b3dccd)`() const` | 
`public virtual uint32 `[`GetUID`](#classNFactor_1a8bac96227fe585ec0ba71ca20abde936)`() const` | 
`public virtual void `[`AddTime`](#classNFactor_1a147710805dd204fa4680a5fb9d278099)`(float Time)` | 
`public void `[`Activate`](#classNFactor_1a1da74e109ffc3426593685e37899da98)`(bool _bIsActivated)` | 
`protected bool `[`bIsActivated`](#classNFactor_1a489248a0bbca33e35414302c918c5b0c) | 
`protected float `[`FactorValue`](#classNFactor_1a89828cdf2315c7d923a3b8f86c5dc1ba) | 
`protected `[`IFactorOperator`](#classIFactorOperator)` * `[`Operator`](#classNFactor_1a190d68092f15da8892a291cc752c7b73) | 
`protected uint32 `[`Id`](#classNFactor_1a8aad3d11b8649e0f1037c86aa27b85e9) | TODO use FGuid::NewGuid().ToString() instead

## Members

#### `public  `[`NFactor`](#classNFactor_1a7aade0c397029399481eef496898e020)`(float _FactorValue,`[`IFactorOperator`](#classIFactorOperator)` * _Operator,float _Duration,FName Reason,float _Delay)` <a id="classNFactor_1a7aade0c397029399481eef496898e020"></a>

#### `public virtual bool `[`IsActivated`](#classNFactor_1ae4d6bf09600c7c2cb92fcd98bbce7913)`() const` <a id="classNFactor_1ae4d6bf09600c7c2cb92fcd98bbce7913"></a>

#### `public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetOperator`](#classNFactor_1ab6ec016f4168b8ce0b96932049f60e1d)`() const` <a id="classNFactor_1ab6ec016f4168b8ce0b96932049f60e1d"></a>

#### `public virtual float `[`GetFactorValue`](#classNFactor_1aaa0e436924fceddb031fbe2e5828c814)`() const` <a id="classNFactor_1aaa0e436924fceddb031fbe2e5828c814"></a>

#### `public virtual FName `[`GetReason`](#classNFactor_1ae2de6106daf773494393f49c73b3dccd)`() const` <a id="classNFactor_1ae2de6106daf773494393f49c73b3dccd"></a>

#### `public virtual uint32 `[`GetUID`](#classNFactor_1a8bac96227fe585ec0ba71ca20abde936)`() const` <a id="classNFactor_1a8bac96227fe585ec0ba71ca20abde936"></a>

#### `public virtual void `[`AddTime`](#classNFactor_1a147710805dd204fa4680a5fb9d278099)`(float Time)` <a id="classNFactor_1a147710805dd204fa4680a5fb9d278099"></a>

#### `public void `[`Activate`](#classNFactor_1a1da74e109ffc3426593685e37899da98)`(bool _bIsActivated)` <a id="classNFactor_1a1da74e109ffc3426593685e37899da98"></a>

#### `protected bool `[`bIsActivated`](#classNFactor_1a489248a0bbca33e35414302c918c5b0c) <a id="classNFactor_1a489248a0bbca33e35414302c918c5b0c"></a>

#### `protected float `[`FactorValue`](#classNFactor_1a89828cdf2315c7d923a3b8f86c5dc1ba) <a id="classNFactor_1a89828cdf2315c7d923a3b8f86c5dc1ba"></a>

#### `protected `[`IFactorOperator`](#classIFactorOperator)` * `[`Operator`](#classNFactor_1a190d68092f15da8892a291cc752c7b73) <a id="classNFactor_1a190d68092f15da8892a291cc752c7b73"></a>

#### `protected uint32 `[`Id`](#classNFactor_1a8aad3d11b8649e0f1037c86aa27b85e9) <a id="classNFactor_1a8aad3d11b8649e0f1037c86aa27b85e9"></a>

TODO use FGuid::NewGuid().ToString() instead

# class `NFactorsFactoryClient` <a id="classNFactorsFactoryClient"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`CreateStack`](#classNFactorsFactoryClient_1a3c829abd61abf15c7ee273af15d1e81b)`(FName StackName,TSharedPtr< NTimeline > Timeline)` | 
`public void `[`CreateStack`](#classNFactorsFactoryClient_1aac680d3904526920dceb32aa05066070)`(TArray< FName > StackNames,TSharedPtr< NTimeline > Timeline)` | 
`public void `[`RemoveStack`](#classNFactorsFactoryClient_1aed5d6c5922e0da365e865320f5ff0f70)`(FName StackName)` | 
`public `[`NFactorState`](#classNFactorState)` * `[`GetState`](#classNFactorsFactoryClient_1a8bfe8509dea5d83a1e7006eaf3a9fc8f)`(FName StackName)` | 
`public TArray< `[`NFactorState`](#classNFactorState)` * > `[`GetStates`](#classNFactorsFactoryClient_1ae26abbc4d0cc48119afc26ae6159893a)`(TArray< FName > StackNames)` | 
`public void `[`AddFactor`](#classNFactorsFactoryClient_1a2ae90109b5766998dde7ec2f56742cff)`(FName StackName,TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > Factor)` | 
`public void `[`AddFactor`](#classNFactorsFactoryClient_1a922b92f837b4a5a7d720d71ea049af4e)`(TArray< FName > StackNames,TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > Factor)` | 
`public void `[`SetDebug`](#classNFactorsFactoryClient_1a0fa190ff18cd4fd52ba98e50aace77ee)`(const TArray< FName > StackNames,bool bDebug)` | 
`protected TMap< FName, TSharedPtr< `[`NFactorStack`](#classNFactorStack)` > > `[`StacksList`](#classNFactorsFactoryClient_1ad134516024217766b537f94684e01fc6) | 

## Members

#### `public void `[`CreateStack`](#classNFactorsFactoryClient_1a3c829abd61abf15c7ee273af15d1e81b)`(FName StackName,TSharedPtr< NTimeline > Timeline)` <a id="classNFactorsFactoryClient_1a3c829abd61abf15c7ee273af15d1e81b"></a>

#### `public void `[`CreateStack`](#classNFactorsFactoryClient_1aac680d3904526920dceb32aa05066070)`(TArray< FName > StackNames,TSharedPtr< NTimeline > Timeline)` <a id="classNFactorsFactoryClient_1aac680d3904526920dceb32aa05066070"></a>

#### `public void `[`RemoveStack`](#classNFactorsFactoryClient_1aed5d6c5922e0da365e865320f5ff0f70)`(FName StackName)` <a id="classNFactorsFactoryClient_1aed5d6c5922e0da365e865320f5ff0f70"></a>

#### `public `[`NFactorState`](#classNFactorState)` * `[`GetState`](#classNFactorsFactoryClient_1a8bfe8509dea5d83a1e7006eaf3a9fc8f)`(FName StackName)` <a id="classNFactorsFactoryClient_1a8bfe8509dea5d83a1e7006eaf3a9fc8f"></a>

#### `public TArray< `[`NFactorState`](#classNFactorState)` * > `[`GetStates`](#classNFactorsFactoryClient_1ae26abbc4d0cc48119afc26ae6159893a)`(TArray< FName > StackNames)` <a id="classNFactorsFactoryClient_1ae26abbc4d0cc48119afc26ae6159893a"></a>

#### `public void `[`AddFactor`](#classNFactorsFactoryClient_1a2ae90109b5766998dde7ec2f56742cff)`(FName StackName,TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > Factor)` <a id="classNFactorsFactoryClient_1a2ae90109b5766998dde7ec2f56742cff"></a>

#### `public void `[`AddFactor`](#classNFactorsFactoryClient_1a922b92f837b4a5a7d720d71ea049af4e)`(TArray< FName > StackNames,TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > Factor)` <a id="classNFactorsFactoryClient_1a922b92f837b4a5a7d720d71ea049af4e"></a>

#### `public void `[`SetDebug`](#classNFactorsFactoryClient_1a0fa190ff18cd4fd52ba98e50aace77ee)`(const TArray< FName > StackNames,bool bDebug)` <a id="classNFactorsFactoryClient_1a0fa190ff18cd4fd52ba98e50aace77ee"></a>

#### `protected TMap< FName, TSharedPtr< `[`NFactorStack`](#classNFactorStack)` > > `[`StacksList`](#classNFactorsFactoryClient_1ad134516024217766b537f94684e01fc6) <a id="classNFactorsFactoryClient_1ad134516024217766b537f94684e01fc6"></a>

# class `NFactorStack` <a id="classNFactorStack"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`bDebug`](#classNFactorStack_1a433b9bf07597be6f85c9d6e25a61a2c1) | 
`public  `[`NFactorStack`](#classNFactorStack_1aa3c3e966670588f269adac5a44918fab)`(FName _Name,TSharedPtr< NTimeline > _Timeline)` | 
`public virtual  `[`~NFactorStack`](#classNFactorStack_1ab58dc79ac0720a158da399eb000d1bcc)`()` | 
`public void `[`Reset`](#classNFactorStack_1ad7fe546b81cf17e39b4974c152a6535c)`()` | 
`public void `[`SetName`](#classNFactorStack_1a2e40efad7054626acde739195cefaf59)`(FName _Name)` | 
`public FName `[`GetName`](#classNFactorStack_1a5c3d98c65e81370d737f768f688fdcd2)`() const` | 
`public float `[`GetTime`](#classNFactorStack_1a5b12113a2ca83673680ed3320178245e)`() const` | 
`public `[`INFactorInterface`](#classINFactorInterface)` * `[`GetFactor`](#classNFactorStack_1a6a0df939dfdf56b361699bf1cbc0a945)`(uint32 Key) const` | 
`public void `[`AddFactor`](#classNFactorStack_1a051f9ac8744e410000bd6c0c98372d2a)`(TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > Factor)` | 
`public bool `[`HasFlag`](#classNFactorStack_1aad647225ced66030d02a31ba0ff77b61)`(FString Flag) const` | 
`public bool `[`GetFlag`](#classNFactorStack_1a9002bd2ebd5dcab3ba81cc312324d127)`(FString Flag) const` | 
`public void `[`SetFlag`](#classNFactorStack_1a5338085be518e58772a13efd3e16f088)`(FString Flag,bool value)` | 
`public virtual `[`NFactorState`](#classNFactorState)` * `[`GetCurrentState`](#classNFactorStack_1a458d83fa59aa4edbb93143eaa65adef7)`()` | 
`protected TMap< FString, bool > `[`IterationFlags`](#classNFactorStack_1ab0883ade9b34b28403e371568d7de572) | 
`protected TSharedPtr< NTimeline > `[`Timeline`](#classNFactorStack_1aeceb2b6991432298b53243f5acd96a38) | 
`protected TArray< TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > > `[`Factors`](#classNFactorStack_1af607daf40357b5e82478c297b12b61b7) | 
`protected FName `[`Name`](#classNFactorStack_1a77470aff166c1c99b6fad3095082ef09) | 
`protected void `[`AddFactorsToState`](#classNFactorStack_1af1b6c00bd6f8711139e4bd49c55473ad)`(`[`NFactorState`](#classNFactorState)` * State)` | 

## Members

#### `public bool `[`bDebug`](#classNFactorStack_1a433b9bf07597be6f85c9d6e25a61a2c1) <a id="classNFactorStack_1a433b9bf07597be6f85c9d6e25a61a2c1"></a>

#### `public  `[`NFactorStack`](#classNFactorStack_1aa3c3e966670588f269adac5a44918fab)`(FName _Name,TSharedPtr< NTimeline > _Timeline)` <a id="classNFactorStack_1aa3c3e966670588f269adac5a44918fab"></a>

#### `public virtual  `[`~NFactorStack`](#classNFactorStack_1ab58dc79ac0720a158da399eb000d1bcc)`()` <a id="classNFactorStack_1ab58dc79ac0720a158da399eb000d1bcc"></a>

#### `public void `[`Reset`](#classNFactorStack_1ad7fe546b81cf17e39b4974c152a6535c)`()` <a id="classNFactorStack_1ad7fe546b81cf17e39b4974c152a6535c"></a>

#### `public void `[`SetName`](#classNFactorStack_1a2e40efad7054626acde739195cefaf59)`(FName _Name)` <a id="classNFactorStack_1a2e40efad7054626acde739195cefaf59"></a>

#### `public FName `[`GetName`](#classNFactorStack_1a5c3d98c65e81370d737f768f688fdcd2)`() const` <a id="classNFactorStack_1a5c3d98c65e81370d737f768f688fdcd2"></a>

#### `public float `[`GetTime`](#classNFactorStack_1a5b12113a2ca83673680ed3320178245e)`() const` <a id="classNFactorStack_1a5b12113a2ca83673680ed3320178245e"></a>

#### `public `[`INFactorInterface`](#classINFactorInterface)` * `[`GetFactor`](#classNFactorStack_1a6a0df939dfdf56b361699bf1cbc0a945)`(uint32 Key) const` <a id="classNFactorStack_1a6a0df939dfdf56b361699bf1cbc0a945"></a>

#### `public void `[`AddFactor`](#classNFactorStack_1a051f9ac8744e410000bd6c0c98372d2a)`(TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > Factor)` <a id="classNFactorStack_1a051f9ac8744e410000bd6c0c98372d2a"></a>

#### `public bool `[`HasFlag`](#classNFactorStack_1aad647225ced66030d02a31ba0ff77b61)`(FString Flag) const` <a id="classNFactorStack_1aad647225ced66030d02a31ba0ff77b61"></a>

#### `public bool `[`GetFlag`](#classNFactorStack_1a9002bd2ebd5dcab3ba81cc312324d127)`(FString Flag) const` <a id="classNFactorStack_1a9002bd2ebd5dcab3ba81cc312324d127"></a>

#### `public void `[`SetFlag`](#classNFactorStack_1a5338085be518e58772a13efd3e16f088)`(FString Flag,bool value)` <a id="classNFactorStack_1a5338085be518e58772a13efd3e16f088"></a>

#### `public virtual `[`NFactorState`](#classNFactorState)` * `[`GetCurrentState`](#classNFactorStack_1a458d83fa59aa4edbb93143eaa65adef7)`()` <a id="classNFactorStack_1a458d83fa59aa4edbb93143eaa65adef7"></a>

#### `protected TMap< FString, bool > `[`IterationFlags`](#classNFactorStack_1ab0883ade9b34b28403e371568d7de572) <a id="classNFactorStack_1ab0883ade9b34b28403e371568d7de572"></a>

#### `protected TSharedPtr< NTimeline > `[`Timeline`](#classNFactorStack_1aeceb2b6991432298b53243f5acd96a38) <a id="classNFactorStack_1aeceb2b6991432298b53243f5acd96a38"></a>

#### `protected TArray< TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > > `[`Factors`](#classNFactorStack_1af607daf40357b5e82478c297b12b61b7) <a id="classNFactorStack_1af607daf40357b5e82478c297b12b61b7"></a>

#### `protected FName `[`Name`](#classNFactorStack_1a77470aff166c1c99b6fad3095082ef09) <a id="classNFactorStack_1a77470aff166c1c99b6fad3095082ef09"></a>

#### `protected void `[`AddFactorsToState`](#classNFactorStack_1af1b6c00bd6f8711139e4bd49c55473ad)`(`[`NFactorState`](#classNFactorState)` * State)` <a id="classNFactorStack_1af1b6c00bd6f8711139e4bd49c55473ad"></a>

# class `NFactorState` <a id="classNFactorState"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`bDebug`](#classNFactorState_1ac1565797048a0259d71bad1cb4995604) | 
`public inline virtual  `[`~NFactorState`](#classNFactorState_1a11c5c3b35724ddba3db601ff3d2574e9)`()` | 
`public inline  `[`NFactorState`](#classNFactorState_1a64392bc5f25117da90683127f38b3d61)`()` | 
`public  `[`NFactorState`](#classNFactorState_1ac199aef10127fd7f756b2488bf1b394f)`(float _Time)` | 
`public virtual void `[`AddFactor`](#classNFactorState_1a68f75e75147c5f7316dbc3f919c03cf2)`(TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > Factor)` | 
`public float `[`GetTime`](#classNFactorState_1a3005d9d3e20883af68b41450ac9dbc0e)`() const` | 
`public virtual float `[`Compute`](#classNFactorState_1a5d51713ab45f17155784d8ee9825277a)`()` | 
`public const TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`GetOperators`](#classNFactorState_1a112c65be5ba37626ff300bfce618e414)`() const` | 
`protected TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`Operators`](#classNFactorState_1a31de6655fee5eabd18207e137b7e34c0) | 

## Members

#### `public bool `[`bDebug`](#classNFactorState_1ac1565797048a0259d71bad1cb4995604) <a id="classNFactorState_1ac1565797048a0259d71bad1cb4995604"></a>

#### `public inline virtual  `[`~NFactorState`](#classNFactorState_1a11c5c3b35724ddba3db601ff3d2574e9)`()` <a id="classNFactorState_1a11c5c3b35724ddba3db601ff3d2574e9"></a>

#### `public inline  `[`NFactorState`](#classNFactorState_1a64392bc5f25117da90683127f38b3d61)`()` <a id="classNFactorState_1a64392bc5f25117da90683127f38b3d61"></a>

#### `public  `[`NFactorState`](#classNFactorState_1ac199aef10127fd7f756b2488bf1b394f)`(float _Time)` <a id="classNFactorState_1ac199aef10127fd7f756b2488bf1b394f"></a>

#### `public virtual void `[`AddFactor`](#classNFactorState_1a68f75e75147c5f7316dbc3f919c03cf2)`(TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > Factor)` <a id="classNFactorState_1a68f75e75147c5f7316dbc3f919c03cf2"></a>

#### `public float `[`GetTime`](#classNFactorState_1a3005d9d3e20883af68b41450ac9dbc0e)`() const` <a id="classNFactorState_1a3005d9d3e20883af68b41450ac9dbc0e"></a>

#### `public virtual float `[`Compute`](#classNFactorState_1a5d51713ab45f17155784d8ee9825277a)`()` <a id="classNFactorState_1a5d51713ab45f17155784d8ee9825277a"></a>

#### `public const TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`GetOperators`](#classNFactorState_1a112c65be5ba37626ff300bfce618e414)`() const` <a id="classNFactorState_1a112c65be5ba37626ff300bfce618e414"></a>

#### `protected TArray< `[`FNFactorStateOperator`](#structFNFactorStateOperator)` > `[`Operators`](#classNFactorState_1a31de6655fee5eabd18207e137b7e34c0) <a id="classNFactorState_1a31de6655fee5eabd18207e137b7e34c0"></a>

# class `NMultiplyOperator` <a id="classNMultiplyOperator"></a>

```
class NMultiplyOperator
  : public IFactorOperator
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNMultiplyOperator_1a13ed17ab0b1d7f45afb34bbb869a24fb)`(float Lh,float Rh)` | 
`public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNMultiplyOperator_1a22721e90a514a32e9c54be3fea2fb76a)`()` | 
`public inline virtual const FName `[`GetName`](#classNMultiplyOperator_1a78841a13d056a1d79ca82d35db1f26d2)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNMultiplyOperator_1a13ed17ab0b1d7f45afb34bbb869a24fb)`(float Lh,float Rh)` <a id="classNMultiplyOperator_1a13ed17ab0b1d7f45afb34bbb869a24fb"></a>

#### `public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNMultiplyOperator_1a22721e90a514a32e9c54be3fea2fb76a)`()` <a id="classNMultiplyOperator_1a22721e90a514a32e9c54be3fea2fb76a"></a>

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
`public virtual void `[`AddFactor`](#classNNullFactorState_1a9d6d4a893dc80d2ad2a8b19f2aaee51e)`(TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > Factor)` | 
`public virtual float `[`Compute`](#classNNullFactorState_1a4f8403c3a1253db93d88d6bdf2958f9f)`()` | 

## Members

#### `public  `[`NNullFactorState`](#classNNullFactorState_1a6fbb0af6b2427a0e182743fc63b59d58)`()` <a id="classNNullFactorState_1a6fbb0af6b2427a0e182743fc63b59d58"></a>

#### `public virtual void `[`AddFactor`](#classNNullFactorState_1a9d6d4a893dc80d2ad2a8b19f2aaee51e)`(TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > Factor)` <a id="classNNullFactorState_1a9d6d4a893dc80d2ad2a8b19f2aaee51e"></a>

#### `public virtual float `[`Compute`](#classNNullFactorState_1a4f8403c3a1253db93d88d6bdf2958f9f)`()` <a id="classNNullFactorState_1a4f8403c3a1253db93d88d6bdf2958f9f"></a>

# class `NNullOperator` <a id="classNNullOperator"></a>

```
class NNullOperator
  : public IFactorOperator
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNNullOperator_1a74b252e0b045e0867b283668c0776956)`(float Lh,float Rh)` | 
`public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNNullOperator_1a5ddf5a2dbe651f355bfec1fd690227b9)`()` | 
`public inline virtual const FName `[`GetName`](#classNNullOperator_1a5bab46d063f6b81227aa6925a34b1ea3)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNNullOperator_1a74b252e0b045e0867b283668c0776956)`(float Lh,float Rh)` <a id="classNNullOperator_1a74b252e0b045e0867b283668c0776956"></a>

#### `public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNNullOperator_1a5ddf5a2dbe651f355bfec1fd690227b9)`()` <a id="classNNullOperator_1a5ddf5a2dbe651f355bfec1fd690227b9"></a>

#### `public inline virtual const FName `[`GetName`](#classNNullOperator_1a5bab46d063f6b81227aa6925a34b1ea3)`()` <a id="classNNullOperator_1a5bab46d063f6b81227aa6925a34b1ea3"></a>

# class `NResetOperator` <a id="classNResetOperator"></a>

```
class NResetOperator
  : public NResetOperatorBase
  : public IFactorOperatorWithStack
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e)`(float Lh,float Rh)` | 
`public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNResetOperator_1a9f0241ad6e2cfd955ac6acd247b74d02)`()` | 
`public virtual void `[`SetStack`](#classNResetOperator_1a1b7dc931712401c85cd619e8cfcbabc1)`(`[`NFactorStack`](#classNFactorStack)` * Stack)` | 
`public virtual void `[`SetKeyInStack`](#classNResetOperator_1aa55538b52fae733a1f9133826e3b7981)`(uint32 Key)` | 
`public inline virtual const FName `[`GetName`](#classNResetOperator_1a2a588aed7287ebf233d15d215970683f)`()` | 
`protected `[`NFactorStack`](#classNFactorStack)` * `[`MyStack`](#classNResetOperator_1acfd64dcbd30f03fad487fdafb2f93c78) | 
`protected uint32 `[`KeyInStack`](#classNResetOperator_1a279132427eb6c24936faa0955aa98c57) | 

## Members

#### `public virtual float `[`Compute`](#classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e)`(float Lh,float Rh)` <a id="classNResetOperator_1abdb19ca6f82e81ff1d7d13948448f10e"></a>

#### `public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNResetOperator_1a9f0241ad6e2cfd955ac6acd247b74d02)`()` <a id="classNResetOperator_1a9f0241ad6e2cfd955ac6acd247b74d02"></a>

#### `public virtual void `[`SetStack`](#classNResetOperator_1a1b7dc931712401c85cd619e8cfcbabc1)`(`[`NFactorStack`](#classNFactorStack)` * Stack)` <a id="classNResetOperator_1a1b7dc931712401c85cd619e8cfcbabc1"></a>

#### `public virtual void `[`SetKeyInStack`](#classNResetOperator_1aa55538b52fae733a1f9133826e3b7981)`(uint32 Key)` <a id="classNResetOperator_1aa55538b52fae733a1f9133826e3b7981"></a>

#### `public inline virtual const FName `[`GetName`](#classNResetOperator_1a2a588aed7287ebf233d15d215970683f)`()` <a id="classNResetOperator_1a2a588aed7287ebf233d15d215970683f"></a>

#### `protected `[`NFactorStack`](#classNFactorStack)` * `[`MyStack`](#classNResetOperator_1acfd64dcbd30f03fad487fdafb2f93c78) <a id="classNResetOperator_1acfd64dcbd30f03fad487fdafb2f93c78"></a>

#### `protected uint32 `[`KeyInStack`](#classNResetOperator_1a279132427eb6c24936faa0955aa98c57) <a id="classNResetOperator_1a279132427eb6c24936faa0955aa98c57"></a>

# class `NResetOperatorBase` <a id="classNResetOperatorBase"></a>

```
class NResetOperatorBase
  : public IFactorOperator
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNResetOperatorBase_1a95a05c328d4745e631b22936f9276fd8)`()` | 

## Members

#### `public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNResetOperatorBase_1a95a05c328d4745e631b22936f9276fd8)`()` <a id="classNResetOperatorBase_1a95a05c328d4745e631b22936f9276fd8"></a>

# class `NSubsctractOperator` <a id="classNSubsctractOperator"></a>

```
class NSubsctractOperator
  : public IFactorOperator
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual float `[`Compute`](#classNSubsctractOperator_1ab0d1823a3d03ea5b098e184416d6f442)`(float Lh,float Rh)` | 
`public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNSubsctractOperator_1a5ad0a6396b30d03b43a175227f4e19f3)`()` | 
`public inline virtual const FName `[`GetName`](#classNSubsctractOperator_1a5c21df39e32ffbb8de747c4cd97332d5)`()` | 

## Members

#### `public virtual float `[`Compute`](#classNSubsctractOperator_1ab0d1823a3d03ea5b098e184416d6f442)`(float Lh,float Rh)` <a id="classNSubsctractOperator_1ab0d1823a3d03ea5b098e184416d6f442"></a>

#### `public virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetInverse`](#classNSubsctractOperator_1a5ad0a6396b30d03b43a175227f4e19f3)`()` <a id="classNSubsctractOperator_1a5ad0a6396b30d03b43a175227f4e19f3"></a>

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

# class `UFactorSettings` <a id="classUFactorSettings"></a>

```
class UFactorSettings
  : public UDeveloperSettings
```  

This allow to Thanks to: [https://forums.unrealengine.com/development-discussion/c-gameplay-programming/1503868-adding-a-custom-ini-file](https://forums.unrealengine.com/development-discussion/c-gameplay-programming/1503868-adding-a-custom-ini-file)

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
`public inline virtual bool `[`IsNodePure`](#classUK2Node__FactorOperator_1a9bcaa3595cccd555928fcbf513d20c02)`() const` | 
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

#### `public inline virtual bool `[`IsNodePure`](#classUK2Node__FactorOperator_1a9bcaa3595cccd555928fcbf513d20c02)`() const` <a id="classUK2Node__FactorOperator_1a9bcaa3595cccd555928fcbf513d20c02"></a>

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

# class `UMockGameInstance` <a id="classUMockGameInstance"></a>

```
class UMockGameInstance
  : public UGameInstance
  : public INFactorsFactoryGameInstance
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UMockGameInstance`](#classUMockGameInstance_1a5aca56dd620e7690e4f1e08f548d114b)`(const FObjectInitializer & ObjectInitializer)` | 
`public inline virtual `[`UNFactorClientAdapter`](#classUNFactorClientAdapter)` * `[`GetFactorsFactoryClient_Implementation`](#classUMockGameInstance_1a87b9176c965aa8cd6a99a1f43e4dc9af)`() const` | 
`protected `[`UNFactorClientAdapter`](#classUNFactorClientAdapter)` * `[`FactorsFactoryClient`](#classUMockGameInstance_1a711d201d2df38e93c979b6e3edfbf954) | 

## Members

#### `public inline  `[`UMockGameInstance`](#classUMockGameInstance_1a5aca56dd620e7690e4f1e08f548d114b)`(const FObjectInitializer & ObjectInitializer)` <a id="classUMockGameInstance_1a5aca56dd620e7690e4f1e08f548d114b"></a>

#### `public inline virtual `[`UNFactorClientAdapter`](#classUNFactorClientAdapter)` * `[`GetFactorsFactoryClient_Implementation`](#classUMockGameInstance_1a87b9176c965aa8cd6a99a1f43e4dc9af)`() const` <a id="classUMockGameInstance_1a87b9176c965aa8cd6a99a1f43e4dc9af"></a>

#### `protected `[`UNFactorClientAdapter`](#classUNFactorClientAdapter)` * `[`FactorsFactoryClient`](#classUMockGameInstance_1a711d201d2df38e93c979b6e3edfbf954) <a id="classUMockGameInstance_1a711d201d2df38e93c979b6e3edfbf954"></a>

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
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`FactorValue`](#classUNFactorAdapterAbstract_1a0e8e74a4d248caadadf074852b07c9cd) | 
`public float `[`Duration`](#classUNFactorAdapterAbstract_1a421efb06fdabdcdff355ceb7e0380564) | 
`public FName `[`Reason`](#classUNFactorAdapterAbstract_1a700115ff0f4d4c2d7323733894d90acc) | 
`public FName `[`InStack`](#classUNFactorAdapterAbstract_1a8fcba441b1dcdc548812f59baa6929c5) | 
`public inline TSharedPtr< `[`NFactor`](#classNFactor)` > `[`GetFactor`](#classUNFactorAdapterAbstract_1a25d9725d9f9e144fe8c194e7ce9db81f)`()` | 
`public inline virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetOperator`](#classUNFactorAdapterAbstract_1ac6c76bbd28737730761beaf5391e7e9c)`()` | 
`protected TSharedPtr< `[`NFactor`](#classNFactor)` > `[`Factor`](#classUNFactorAdapterAbstract_1ad3084b3d6ec528be360bf06bf79c5cfe) | 

## Members

#### `public float `[`FactorValue`](#classUNFactorAdapterAbstract_1a0e8e74a4d248caadadf074852b07c9cd) <a id="classUNFactorAdapterAbstract_1a0e8e74a4d248caadadf074852b07c9cd"></a>

#### `public float `[`Duration`](#classUNFactorAdapterAbstract_1a421efb06fdabdcdff355ceb7e0380564) <a id="classUNFactorAdapterAbstract_1a421efb06fdabdcdff355ceb7e0380564"></a>

#### `public FName `[`Reason`](#classUNFactorAdapterAbstract_1a700115ff0f4d4c2d7323733894d90acc) <a id="classUNFactorAdapterAbstract_1a700115ff0f4d4c2d7323733894d90acc"></a>

#### `public FName `[`InStack`](#classUNFactorAdapterAbstract_1a8fcba441b1dcdc548812f59baa6929c5) <a id="classUNFactorAdapterAbstract_1a8fcba441b1dcdc548812f59baa6929c5"></a>

#### `public inline TSharedPtr< `[`NFactor`](#classNFactor)` > `[`GetFactor`](#classUNFactorAdapterAbstract_1a25d9725d9f9e144fe8c194e7ce9db81f)`()` <a id="classUNFactorAdapterAbstract_1a25d9725d9f9e144fe8c194e7ce9db81f"></a>

#### `public inline virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetOperator`](#classUNFactorAdapterAbstract_1ac6c76bbd28737730761beaf5391e7e9c)`()` <a id="classUNFactorAdapterAbstract_1ac6c76bbd28737730761beaf5391e7e9c"></a>

#### `protected TSharedPtr< `[`NFactor`](#classNFactor)` > `[`Factor`](#classUNFactorAdapterAbstract_1ad3084b3d6ec528be360bf06bf79c5cfe) <a id="classUNFactorAdapterAbstract_1ad3084b3d6ec528be360bf06bf79c5cfe"></a>

# class `UNFactorAdapterBasic` <a id="classUNFactorAdapterBasic"></a>

```
class UNFactorAdapterBasic
  : public UNFactorAdapterAbstract
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`ENFactorOperator`](#FactorAdapters_8h_1ac0832918529efa40bbe65b8c54c4cf20)` `[`Operator`](#classUNFactorAdapterBasic_1af612bc210615099f14c584fc87037d1c) | 
`public inline virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetOperator`](#classUNFactorAdapterBasic_1a5fee9e0fb91ea90b5e342c9ff65c1756)`()` | 

## Members

#### `public `[`ENFactorOperator`](#FactorAdapters_8h_1ac0832918529efa40bbe65b8c54c4cf20)` `[`Operator`](#classUNFactorAdapterBasic_1af612bc210615099f14c584fc87037d1c) <a id="classUNFactorAdapterBasic_1af612bc210615099f14c584fc87037d1c"></a>

#### `public inline virtual `[`IFactorOperator`](#classIFactorOperator)` * `[`GetOperator`](#classUNFactorAdapterBasic_1a5fee9e0fb91ea90b5e342c9ff65c1756)`()` <a id="classUNFactorAdapterBasic_1a5fee9e0fb91ea90b5e342c9ff65c1756"></a>

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

# class `UNFactorClientAdapter` <a id="classUNFactorClientAdapter"></a>

```
class UNFactorClientAdapter
  : public UObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`UNFactorClientAdapter`](#classUNFactorClientAdapter_1af0a26b222d8c5b5c6812ef2ad3e0c1ed)`()` | 
`public void `[`CreateStack`](#classUNFactorClientAdapter_1ad32e164d1dc4833566ff7903b19187cd)`(FName StackName,UNTimelineManagerBaseDecorator * _Timeline)` | 
`public void `[`RemoveStack`](#classUNFactorClientAdapter_1ab30599e4c8157aabf2261bdc4ec698a3)`(FName StackName)` | 
`public `[`NFactorState`](#classNFactorState)` * `[`GetState`](#classUNFactorClientAdapter_1a5009b55c3188496e0f7f43473ba62201)`(FName StackName)` | 
`public TArray< `[`NFactorState`](#classNFactorState)` * > `[`GetStates`](#classUNFactorClientAdapter_1aa70f10526c4809f4811367cbd5b708cd)`(TArray< FName > StackNames)` | 
`public void `[`AddFactor`](#classUNFactorClientAdapter_1a9ac2a413b9f59397e8bb52711bb18481)`(FName StackName,`[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract)` * Factor)` | 
`public void `[`AddFactor`](#classUNFactorClientAdapter_1a6c8c174c113a6ae46e2fa112eda639cd)`(TArray< FName > StackNames,`[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract)` * Factor)` | 
`public void `[`SetDebug`](#classUNFactorClientAdapter_1af782be9ef09d1a5d5c18203850fccc7d)`(const TArray< FName > StackNames,bool bDebug)` | 
`protected TSharedPtr< `[`NFactorsFactoryClient`](#classNFactorsFactoryClient)` > `[`Client`](#classUNFactorClientAdapter_1a04cf056ee1708b0aacec7b8fa116902f) | 

## Members

#### `public  `[`UNFactorClientAdapter`](#classUNFactorClientAdapter_1af0a26b222d8c5b5c6812ef2ad3e0c1ed)`()` <a id="classUNFactorClientAdapter_1af0a26b222d8c5b5c6812ef2ad3e0c1ed"></a>

#### `public void `[`CreateStack`](#classUNFactorClientAdapter_1ad32e164d1dc4833566ff7903b19187cd)`(FName StackName,UNTimelineManagerBaseDecorator * _Timeline)` <a id="classUNFactorClientAdapter_1ad32e164d1dc4833566ff7903b19187cd"></a>

#### `public void `[`RemoveStack`](#classUNFactorClientAdapter_1ab30599e4c8157aabf2261bdc4ec698a3)`(FName StackName)` <a id="classUNFactorClientAdapter_1ab30599e4c8157aabf2261bdc4ec698a3"></a>

#### `public `[`NFactorState`](#classNFactorState)` * `[`GetState`](#classUNFactorClientAdapter_1a5009b55c3188496e0f7f43473ba62201)`(FName StackName)` <a id="classUNFactorClientAdapter_1a5009b55c3188496e0f7f43473ba62201"></a>

#### `public TArray< `[`NFactorState`](#classNFactorState)` * > `[`GetStates`](#classUNFactorClientAdapter_1aa70f10526c4809f4811367cbd5b708cd)`(TArray< FName > StackNames)` <a id="classUNFactorClientAdapter_1aa70f10526c4809f4811367cbd5b708cd"></a>

#### `public void `[`AddFactor`](#classUNFactorClientAdapter_1a9ac2a413b9f59397e8bb52711bb18481)`(FName StackName,`[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract)` * Factor)` <a id="classUNFactorClientAdapter_1a9ac2a413b9f59397e8bb52711bb18481"></a>

#### `public void `[`AddFactor`](#classUNFactorClientAdapter_1a6c8c174c113a6ae46e2fa112eda639cd)`(TArray< FName > StackNames,`[`UNFactorAdapterAbstract`](#classUNFactorAdapterAbstract)` * Factor)` <a id="classUNFactorClientAdapter_1a6c8c174c113a6ae46e2fa112eda639cd"></a>

#### `public void `[`SetDebug`](#classUNFactorClientAdapter_1af782be9ef09d1a5d5c18203850fccc7d)`(const TArray< FName > StackNames,bool bDebug)` <a id="classUNFactorClientAdapter_1af782be9ef09d1a5d5c18203850fccc7d"></a>

#### `protected TSharedPtr< `[`NFactorsFactoryClient`](#classNFactorsFactoryClient)` > `[`Client`](#classUNFactorClientAdapter_1a04cf056ee1708b0aacec7b8fa116902f) <a id="classUNFactorClientAdapter_1a04cf056ee1708b0aacec7b8fa116902f"></a>

# class `UNFactorFactory` <a id="classUNFactorFactory"></a>

```
class UNFactorFactory
  : public UBlueprintFunctionLibrary
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNFactorsFactoryGameInstance` <a id="classUNFactorsFactoryGameInstance"></a>

```
class UNFactorsFactoryGameInstance
  : public UInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNFakeFactorsFactoryClient` <a id="classUNFakeFactorsFactoryClient"></a>

```
class UNFakeFactorsFactoryClient
  : public NFactorsFactoryClient
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline TMap< FName, TSharedPtr< `[`NFactorStack`](#classNFactorStack)` > > `[`GetStack`](#classUNFakeFactorsFactoryClient_1a8b46c60ec2087bd95307e536ecd466b2)`()` | 
`public inline void `[`Reset`](#classUNFakeFactorsFactoryClient_1adb4edbfedf44d87d422144ae76c68e42)`()` | 

## Members

#### `public inline TMap< FName, TSharedPtr< `[`NFactorStack`](#classNFactorStack)` > > `[`GetStack`](#classUNFakeFactorsFactoryClient_1a8b46c60ec2087bd95307e536ecd466b2)`()` <a id="classUNFakeFactorsFactoryClient_1a8b46c60ec2087bd95307e536ecd466b2"></a>

#### `public inline void `[`Reset`](#classUNFakeFactorsFactoryClient_1adb4edbfedf44d87d422144ae76c68e42)`()` <a id="classUNFakeFactorsFactoryClient_1adb4edbfedf44d87d422144ae76c68e42"></a>

# struct `FNFactorSettings` <a id="structFNFactorSettings"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFNFactorSettings_1acedd2d410195b0d363964dc2bc1e2e8c) | 
`public TArray< FName > `[`CollectionsNames`](#structFNFactorSettings_1a6fd449102ed0d7eb54da4ca1259dd289) | 

## Members

#### `public FName `[`Name`](#structFNFactorSettings_1acedd2d410195b0d363964dc2bc1e2e8c) <a id="structFNFactorSettings_1acedd2d410195b0d363964dc2bc1e2e8c"></a>

#### `public TArray< FName > `[`CollectionsNames`](#structFNFactorSettings_1a6fd449102ed0d7eb54da4ca1259dd289) <a id="structFNFactorSettings_1a6fd449102ed0d7eb54da4ca1259dd289"></a>

# struct `FNFactorStateOperator` <a id="structFNFactorStateOperator"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > `[`Factor`](#structFNFactorStateOperator_1abe4326ef26635a822e315083672e5558) | 
`public float `[`Value`](#structFNFactorStateOperator_1a3de7a16e2324002ed5f48741c69bc8fe) | 
`public FName `[`Reason`](#structFNFactorStateOperator_1af8c21a16835a0f2ab9cd94c48454824f) | 
`public bool `[`Activate`](#structFNFactorStateOperator_1af2d735e5c96ee54b8f90a30aa5213485) | 
`public `[`IFactorOperator`](#classIFactorOperator)` * `[`Operator`](#structFNFactorStateOperator_1a20819b2ccbbb2c0ec3efad53771bdec4) | 
`public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1a62b4b9fcc006a27ce02977be4e0e066d)`()` | 
`public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1a5a12dbf899cc57a86b553c2e0dd040ca)`(TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > _Factor)` | 

## Members

#### `public TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > `[`Factor`](#structFNFactorStateOperator_1abe4326ef26635a822e315083672e5558) <a id="structFNFactorStateOperator_1abe4326ef26635a822e315083672e5558"></a>

#### `public float `[`Value`](#structFNFactorStateOperator_1a3de7a16e2324002ed5f48741c69bc8fe) <a id="structFNFactorStateOperator_1a3de7a16e2324002ed5f48741c69bc8fe"></a>

#### `public FName `[`Reason`](#structFNFactorStateOperator_1af8c21a16835a0f2ab9cd94c48454824f) <a id="structFNFactorStateOperator_1af8c21a16835a0f2ab9cd94c48454824f"></a>

#### `public bool `[`Activate`](#structFNFactorStateOperator_1af2d735e5c96ee54b8f90a30aa5213485) <a id="structFNFactorStateOperator_1af2d735e5c96ee54b8f90a30aa5213485"></a>

#### `public `[`IFactorOperator`](#classIFactorOperator)` * `[`Operator`](#structFNFactorStateOperator_1a20819b2ccbbb2c0ec3efad53771bdec4) <a id="structFNFactorStateOperator_1a20819b2ccbbb2c0ec3efad53771bdec4"></a>

#### `public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1a62b4b9fcc006a27ce02977be4e0e066d)`()` <a id="structFNFactorStateOperator_1a62b4b9fcc006a27ce02977be4e0e066d"></a>

#### `public  `[`FNFactorStateOperator`](#structFNFactorStateOperator_1a5a12dbf899cc57a86b553c2e0dd040ca)`(TSharedPtr< `[`INFactorInterface`](#classINFactorInterface)` > _Factor)` <a id="structFNFactorStateOperator_1a5a12dbf899cc57a86b553c2e0dd040ca"></a>

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