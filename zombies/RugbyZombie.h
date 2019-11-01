#pragma once
#include "Zombie.h"
class RugbyZombie :
	public Zombie
{
	static const int normalSpeed = -3, biteInterval = 2;
protected:
	virtual inline int initHp()const override { return 40; }
	virtual inline int damage()const override { return 2; }
	virtual inline int score()const override { return 6; }
	virtual inline int speed()const override {
		return timestamp >= normalSpeedTime ? normalSpeed : -2;
	}
	virtual inline int getBiteInterval()const override {
		return timestamp >= normalSpeedTime ? biteInterval : biteInterval * 2;
	}
public:
	RugbyZombie(System& system);
	virtual inline std::string toString()const override { return "éÏé­Çò½©Ê¬"; }
};

