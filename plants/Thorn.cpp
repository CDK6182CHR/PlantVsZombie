#include "Thorn.h"
#include <list>
#include "../zombies/Zombie.h"
#include "../Block.h"
using namespace std;

Thorn::Thorn(System& system):Plant(system)
{
}

void Thorn::update()
{
	Block* block = position.target();
	list<Zombie*> zombies = block->getZombies();//¿½±´¹¹Ôì
	for (Zombie* z : zombies)
		z->attacked(damage);
}
