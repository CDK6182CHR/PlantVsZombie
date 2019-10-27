#include "PeaShooter.h"

PeaShooter::PeaShooter(System& sys):Plant(sys),nextShootTime(timestamp+interval)
{
}

void PeaShooter::update()
{
	if (timestamp >= nextShootTime)
		shoot();
	nextShootTime += interval;
}

