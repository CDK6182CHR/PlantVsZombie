#include "RoadblockZombie.h"

RoadblockZombie::RoadblockZombie(System& sys):NormalZombie(sys)
{
	hp = initHp();
}

