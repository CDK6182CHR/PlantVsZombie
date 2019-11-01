#include "DoubleShooter.h"
#include "PeaSeed.h"

DoubleShooter::DoubleShooter(System& system):
	Plant(system),nextShootTime(timestamp+1),twoShoots(true)
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

void DoubleShooter::shoot()
{
	new PeaSeed(system, *this);
}
