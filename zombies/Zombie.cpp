#include "Zombie.h"
#include "../Block.h"
#include "../System.h"
#include "../plants/Plant.h"

Zombie::Zombie(System& sys):
	Placeable(sys),hp(0),normalSpeedTime(timestamp),nextBiteTime(timestamp)
{
}

void Zombie::move(int dcol, int drow)
{
	Block* pOld = position.target();
	position.move(dcol);
	Block* pNew = position.target();
	if (pNew != pOld) {
		pOld->removeZombie(this);
		if (position.getColpix() < 0)
			system.gameOver(this);
		else if (!position.inside())
			remove();
		else
			pNew->addZombie(this);
	}
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
	system.addScore(score());
	active = false;
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
	if (!active)
		return;
	if (position.getColpix() < 0)
		system.gameOver(this);
	Block* b = position.target();
	Plant* p = b->currentPlant();
	if (p != nullptr && p->eatable()) {
		if (timestamp >= nextBiteTime) {
			eat(p);
			nextBiteTime = timestamp + getBiteInterval();
		}
	}
	else {
		move(speed());
	}
}

void Zombie::attacked(int dh)
{
	hp -= dh;
	if (hp <= 0)
		remove();
}

void Zombie::slowDown(int tm)
{
	normalSpeedTime = tm + timestamp;
}

std::string Zombie::getStatus() const
{
	char buffer[100];
	sprintf_s(buffer, "(%d%%)", int(hp * 100.0 / initHp()));
	return std::string(buffer);
}
