#include "DoubleShooter.h"
#include "PeaSeed.h"

DoubleShooter::DoubleShooter(System& system):
	PeaShooter(system),nextShootTime(timestamp+1),twoShoots(true)
{
	hp = initHp();
}

void DoubleShooter::update()
{
	if (timestamp >= nextShootTime) {
		shoot();
		if (twoShoots)
			nextShootTime = timestamp + 1;
		else
			nextShootTime = timestamp + interval;
		twoShoots = !twoShoots;
	}
}
