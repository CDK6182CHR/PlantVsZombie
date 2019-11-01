#pragma once
#include "PeaShooter.h"
class IceShooter :
	public PeaShooter
{
public:
	IceShooter(System& system);
	virtual inline std::string toString()const override { return "∫Æ±˘…‰ ÷"; }
protected:
	virtual void shoot()override;
};

