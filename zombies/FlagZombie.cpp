#include "FlagZombie.h"

FlagZombie::FlagZombie(System& system):
	NormalZombie(system)
{
	hp = initHp();
}
