#pragma once
#include "Plant.h"

class Yard;

class PeaShooter :
	public Plant
{
	static const int initHp = 10, sunrays = 100, interval = 10;
public:
	PeaShooter(System& sys);
	virtual void update();
private:
	void shoot();//����һ���㶹���󣬰������뵽Yard��
};

