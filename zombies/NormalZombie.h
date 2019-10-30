#pragma once
#include "Zombie.h"
#include <string>

class NormalZombie :
	public Zombie
{
	static const int normalSpeed = -2, biteInterval = 3;
protected:
	virtual inline int damage()const { return 2; }
	virtual inline int initHp()const override { return 10; }
	virtual inline int score()const override { return 1; }
	virtual inline int speed()const override {
		return timestamp >= normalSpeedTime ? normalSpeed : normalSpeed / 2;
	}
	virtual inline int getBiteInterval()const override {
		return timestamp >= normalSpeedTime ? biteInterval : biteInterval * 2;
	}
public:
	NormalZombie(System& sys);
	virtual inline std::string toString()const { return "½©Ê¬"; }
};

