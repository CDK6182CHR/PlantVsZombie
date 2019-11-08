#pragma once
#include "NormalZombie.h"
class FlagZombie :
	public NormalZombie
{
public:
	FlagZombie(System& system);
	virtual inline std::string toString()const override { return "ҡ�콩ʬ"; }
	virtual inline int initHp()const override { return 15; }
	virtual inline int speed()const override { return -3; }
	virtual inline int score()const override { return 2; }
};

