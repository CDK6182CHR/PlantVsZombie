#pragma once
#include "../Placeable.h"

class Zombie:
	public Placeable
{
protected:
	int hp;
	virtual inline int damage()const = 0;
	virtual inline int speed()const = 0;
public:
	Zombie(System& sys);
	void place();
	void remove();
	void attacked(int dh);
};

