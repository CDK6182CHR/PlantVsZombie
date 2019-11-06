#pragma once
#include "Plant.h"
class WatermelonThrower :
	public Plant
{
	static const int interval = 5;
	int nextThrowTime;
protected:
	virtual inline int initHp()const override { return 15; }
public:
	WatermelonThrower(System& system);
	virtual inline std::string toString()const override { return "����Ͷ��"; }
	virtual void update()override;
protected:
	void throwSeed(); //throw�ǹؼ���
};

