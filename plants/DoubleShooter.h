#pragma once
#include "Plant.h"
class DoubleShooter :
	public Plant
{
	const static int interval = 4;
	bool twoShoots; //��һ���Ƿ�����
	int nextShootTime;
protected:
	virtual inline int initHp()const override { return 12; }
public:
	DoubleShooter(System& system);
	virtual void update()override;
	virtual inline std::string toString()const override { return "˫������"; }
private:
	void shoot();
};

