#pragma once
#include "Plant.h"
class NutWall :
	public Plant
{
protected:
	virtual inline int initHp()const override { return 60; }
public:
	NutWall(System& system);
	virtual void update()override {}
	virtual inline std::string toString()const override { return "¼á¹ûÇ½"; }
};

