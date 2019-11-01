#pragma once
#include "Plant.h"
class Sunflower :
	public Plant
{
	static const int interval = 15;
	int nextSunTime;
protected:
	virtual inline int initHp()const override { return 10; }
public:
	Sunflower(System& sys);
	virtual void update()override;
	virtual inline std::string toString()const override { return "ÏòÈÕ¿û"; }

};

