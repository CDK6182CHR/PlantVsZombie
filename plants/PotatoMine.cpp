#include "PotatoMine.h"
#include <list>
#include "../Block.h"
#include "../zombies/Zombie.h"
using namespace std;

PotatoMine::PotatoMine(System& system):
	Plant(system),availableTime(timestamp + prepareTime)
{
	hp = initHp();
}

std::string PotatoMine::getStatus() const
{
	if (timestamp < availableTime)
		return Plant::getStatus();
	else
		return "(就绪)";
}

void PotatoMine::update()
{
	if (timestamp >= availableTime) {
		Block* block = position.target();
		if (block->zombieCount() > 0) {
			for (Zombie* z : list<Zombie*>(block->getZombies())) {
				z->remove();//直接去死
			}
			remove();
		}
	}
}
