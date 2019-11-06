#pragma once
#include "PeaShooter.h"
class DoubleShooter :
	public PeaShooter
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
};

