/*
�����������ú����һ��ʱ������������Ч
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
	virtual std::string toString()const override { return "������"; }
};

