#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class NANSFACTORSFACTORYCORE_API NNullOperator : public IFactorOperator
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<IFactorOperator> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NAddOperator : public IFactorOperator
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<IFactorOperator> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NSubsctractOperator : public IFactorOperator
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<IFactorOperator> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NMultiplyOperator : public IFactorOperator
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<IFactorOperator> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NDividerOperator : public IFactorOperator
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<IFactorOperator> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};
