#include "Zombie.h"
#include "../Block.h"
#include "../System.h"
#include "../plants/Plant.h"

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

void Zombie::eat(Plant* plant)
{
	if (!plant->eatable())
		return;
	plant->eaten(damage());
}

void Zombie::update()
{
	Plant* p = position.target()->currentPlant();
	if (p != nullptr && p->eatable())
		eat(p);
	else
		position.move(speed());
	if (!position.inside())
		remove();
}

void Zombie::attacked(int dh)
{
	hp -= dh;
	if (hp <= 0)
		remove();
}
