#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class NANSFACTORSFACTORYCORE_API NNullOperator : public NFactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NAddOperator : public NFactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NSubtractOperator : public NFactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NMultiplyOperator : public NFactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NDividerOperator : public NFactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};
