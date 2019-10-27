#include "Block.h"

Block::Block():
	plant(nullptr),row(-1),col(-1)
{
}

void Block::init(int r, int c)
{
	row = r;
	col = c;
}

void Block::addZombie(Zombie* zombie)
{
	zombies.push_back(zombie);
}

void Block::removeZombie(Zombie* zombie)
{
	zombies.remove(zombie);
}

void Block::setPlant(Plant* plant)
{
	if (this->plant == nullptr)
		this->plant = plant;
}

Plant* Block::currentPlant()
{
	return plant;
}

std::list<Zombie*>& Block::getZombies()
{
	return zombies;
}

int Block::zombieCount() const
{
	return zombies.size();
}

void Block::removePlant()
{
	plant = nullptr;
}
