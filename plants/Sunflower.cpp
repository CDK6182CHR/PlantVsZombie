#include "Sunflower.h"
#include "../System.h"

Sunflower::Sunflower(System& sys):
	Plant(sys),nextSunTime(timestamp+interval)
{
	hp = initHp();
}

void Sunflower::update()
{
	if (timestamp >= nextSunTime) {
		nextSunTime = timestamp + interval;
		system.addSunray(50);
	}
}
