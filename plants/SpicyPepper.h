/*
火爆辣椒，放置后的下一个时钟周期立即生效
*/
#pragma once
#include "Plant.h"
class SpicyPepper :
	public Plant
{
	int explodeTime;
protected:
	virtual inline int initHp()const override { return 50; }
public:
	SpicyPepper(System& system);
	virtual inline bool hasStatus()const override { return false; }
	virtual void update()override;
	virtual std::string toString()const override { return "火爆辣椒"; }
};

