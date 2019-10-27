#include "Zombie.h"
#include "../Block.h"
#include "../System.h"

Zombie::Zombie(System& sys):Placeable(sys),hp(0)
{
}

void Zombie::place()
{
	Block* pBlock = position.target();
	pBlock->addZombie(this);
	system.addItem(this);
}

void Zombie::remove()
{
	position.target()->removeZombie(this);
	system.removeItem(this);
}
