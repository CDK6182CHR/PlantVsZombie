#include "Seed.h"
#include "Plant.h"
#include "../System.h"
#include "../zombies/Zombie.h"
#include <list>
using namespace std;

Seed::Seed(System& sys, Plant& p):Placeable(sys),parent(p)
{
	system.addSeed(this);
}

void Seed::remove()
{
	system.removeSeed(this);
}

void Seed::explode()
{
	list<Zombie*> zombies = position.target()->getZombies();//øΩ±¥ππ‘Ï£°
	for (list<Zombie*>::iterator itr = zombies.begin(); itr != zombies.end(); ++itr) {
		(*itr)->attacked(damage());
	}
}

void Seed::update()
{
	if (position.target()->zombieCount())
		explode();
	else
		position.move(speed());
	if (!position.inside())
		remove();
}
