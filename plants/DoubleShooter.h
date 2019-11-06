#pragma once
#include "PeaShooter.h"
class DoubleShooter :
	public PeaShooter
{
	const static int interval = 4;
	bool twoShoots; //下一发是否连发
	int nextShootTime;
protected:
	virtual inline int initHp()const override { return 12; }
public:
	DoubleShooter(System& system);
	virtual void update()override;
	virtual inline std::string toString()const override { return "双发射手"; }
};

