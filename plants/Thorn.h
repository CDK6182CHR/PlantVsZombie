/*
地刺（荆棘），最大的特点是不可以被吃。
*/
#pragma once
#include "Plant.h"
class Thorn :
	public Plant
{
	static const int damage = 1;
protected:
	virtual inline int initHp()const { return 1; }
public:
	Thorn(System& system);
	virtual inline std::string toString()const override { return "地刺"; }
	virtual inline bool eatable()const override { return false; }
	virtual inline bool hasStatus()const override { return false; } //不需要状态！
	virtual void update()override;
};

