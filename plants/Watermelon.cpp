#include "Watermelon.h"
#include "../zombies/Zombie.h"
#include "../Block.h"
#include "../System.h"
#include <iostream>
using namespace std;

Watermelon::Watermelon(System& system, Plant& parent):
	Seed(system,parent)
{
}

void Watermelon::explode()
{
	Block* block = position.target();
	for (Zombie* zombie : list<Zombie*>(block->getZombies())) {
		zombie->attacked(damage());
	}
	Block* upper = system.yard.upperNeighbor(block),
		* down = system.yard.downNeighbor(block);
	if (upper != nullptr) {
		for (Zombie* zombie : list<Zombie*>(upper->getZombies())) {
			zombie->attacked(damage());
		}
	}
	if (down != nullptr) {
		for (Zombie* zombie : list<Zombie*>(down->getZombies())) {
			zombie->attacked(damage());
		}
	}
	remove();
}
