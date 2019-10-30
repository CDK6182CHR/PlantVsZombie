#include "NormalZombie.h"


NormalZombie::NormalZombie(System& sys):
	Zombie(sys)
{
	hp = initHp();
}


