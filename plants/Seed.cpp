#include "Seed.h"
#include "Plant.h"
#include "../System.h"
#include "../zombies/Zombie.h"
#include <list>
using namespace std;

Seed::Seed(System& sys, Plant& p):Placeable(sys),parent(p)
{
	position.setPos(p.getRow(), p.getColpix());
}

void Seed::place()
{
	position.target()->addSeed(this);
	system.addItem(this);
}

void Seed::remove()
{
	position.target()->removeSeed(this);
	system.removeItem(this);
}

void Seed::explode()
{
	list<Zombie*> zombies = position.target()->getZombies();//øΩ±¥ππ‘Ï£°
	for (list<Zombie*>::iterator itr = zombies.begin(); itr != zombies.end(); ++itr) {
		attactZombie(*itr);
	}
	remove();
}

void Seed::update()
{
	if (position.target()->zombieCount())
		explode();
	else {
		Block* oldBlock = position.target();
		position.move(speed());
		Block* newBlock = position.target();
		if (newBlock != oldBlock) {
			oldBlock->removeSeed(this);
			if (newBlock != nullptr)
				newBlock->addSeed(this);
			else
				system.removeItem(this);
		}
	}
}

void Seed::attactZombie(Zombie* zombie)
{
	zombie->attacked(damage());
}
