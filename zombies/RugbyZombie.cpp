#include "RugbyZombie.h"

RugbyZombie::RugbyZombie(System& system):
	Zombie(system)
{
	hp = initHp();
}
