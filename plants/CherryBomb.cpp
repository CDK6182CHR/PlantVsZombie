#include "CherryBomb.h"
#include "../System.h"
#include "../zombies/Zombie.h"
#include <list>
using namespace std;

CherryBomb::CherryBomb(System& system):Plant(system),explodeTime(timestamp+2)
{
	hp = initHp();
}

void CherryBomb::update()
{
	if (timestamp >= explodeTime) {
		Block* b = position.target();
		list<Block*> lst = system.yard.neighborBlocks(b);
		lst.push_front(b);
		for (Block* block : lst) {
			block->setStatus(BlockStatus::WholeExploded);
			if (block->zombieCount()) {
				for (Zombie* zombie : list<Zombie*>(block->getZombies()))
					zombie->remove();
			}
		}
		remove();
	}
}
