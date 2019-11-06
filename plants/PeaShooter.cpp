#include "PeaShooter.h"
#include "PeaSeed.h"
#include <stdio.h>
#include <iostream>
using namespace std;


PeaShooter::PeaShooter(System& sys):Plant(sys),nextShootTime(timestamp+2)
{
	hp = initHp();
}

void PeaShooter::update()
{
	if (timestamp >= nextShootTime) {
		shoot();
		nextShootTime += interval;
	}
}

void PeaShooter::shoot()
{
	(new PeaSeed(system, *this))->place();//seed���Լ������һ��
}

