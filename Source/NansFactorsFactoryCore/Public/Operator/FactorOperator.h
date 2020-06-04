#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class NANSFACTORSFACTORYCORE_API NNullOperator : public FactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<FactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NAddOperator : public FactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<FactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NSubtractOperator : public FactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<FactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NMultiplyOperator : public FactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<FactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NDividerOperator : public FactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<FactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};
