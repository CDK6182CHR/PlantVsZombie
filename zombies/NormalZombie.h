#pragma once
#include "Zombie.h"
#include <string>

class NormalZombie :
	public Zombie
{
	static const int initHp = 10;
protected:
	virtual inline int damage()const { return 2; }
	virtual inline int speed()const { return -2; }
public:
	NormalZombie(System& sys);
	virtual inline std::string toString()const { return "½©Ê¬"; }
	virtual std::string getStatus()const;
};

