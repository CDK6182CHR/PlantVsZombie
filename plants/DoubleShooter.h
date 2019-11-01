#pragma once
#include "Plant.h"
class DoubleShooter :
	public Plant
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
private:
	void shoot();
};

