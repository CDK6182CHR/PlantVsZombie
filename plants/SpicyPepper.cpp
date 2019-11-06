#include "SpicyPepper.h"
#include "../Yard.h"
#include "../Block.h"
#include "../System.h"
#include "../zombies/Zombie.h"
#include <list>
using namespace std;
SpicyPepper::SpicyPepper(System& system):Plant(system),explodeTime(timestamp+2)
{
	hp = initHp();
}

void SpicyPepper::update()
{
	if (timestamp >= explodeTime) {
		int row = position.target()->getRow();
		for (int i = 0; i < COLS; i++) {
			Block* block = system.yard.blockAt(row, i);
			for (Zombie* zombie : list<Zombie*>(block->getZombies()))
				zombie->remove();
			block->setStatus(BlockStatus::BottomExploded);
		}
		remove();
	}
}
