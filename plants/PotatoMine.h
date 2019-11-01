/*
土豆雷，
冷却20个时钟周期后直接爆炸。
*/
#pragma once
#include "Plant.h"
class PotatoMine :
	public Plant
{
	static const int prepareTime = 20;
	const int availableTime;
protected:
	virtual inline int initHp()const override { return 10; }
public:
	PotatoMine(System& system);
	virtual inline std::string toString()const override { return "土豆雷"; }
	virtual std::string getStatus()const override;
	virtual void update()override;
};

