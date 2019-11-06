#include "WatermelonThrower.h"
#include "Watermelon.h"

WatermelonThrower::WatermelonThrower(System& system):Plant(system),nextThrowTime(timestamp+1)
{
	hp = initHp();
}

void WatermelonThrower::update()
{
	if (timestamp >= nextThrowTime) {
		throwSeed();
		nextThrowTime = timestamp + interval;
	}
}

void WatermelonThrower::throwSeed()
{
	(new Watermelon(system, *this))->place();
}
