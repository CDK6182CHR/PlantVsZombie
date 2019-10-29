#include "PeaShooter.h"
#include "PeaSeed.h"
#include <stdio.h>
#include <iostream>
using namespace std;


PeaShooter::PeaShooter(System& sys):Plant(sys),nextShootTime(timestamp+2)
{
	hp = initHp;
}

void PeaShooter::update()
{
	if (timestamp >= nextShootTime) {
		shoot();
		nextShootTime += interval;
	}
}

std::string PeaShooter::getStatus() const
{
	char buffer[100];
	sprintf_s(buffer,100, "(%d%%)", (int)((double)hp*100 / initHp));
	return string(buffer);
}

void PeaShooter::shoot()
{
	PeaSeed* pea = new PeaSeed(system, *this);//seed会自己解决好一切
}

