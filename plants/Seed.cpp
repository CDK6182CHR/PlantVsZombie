#include "Seed.h"
#include "Plant.h"
#include "../System.h"

Seed::Seed(System& sys, Plant& p):Placeable(sys),parent(p)
{
	system.addSeed(this);
}

void Seed::remove()
{
	system.removeSeed(this);
}
