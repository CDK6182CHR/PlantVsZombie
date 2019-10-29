#include "RoadblockZombie.h"

RoadblockZombie::RoadblockZombie(System& sys):Zombie(sys)
{
	hp = initHp;
}

std::string RoadblockZombie::getStatus() const
{
	char buffer[100];
	sprintf_s(buffer, "(%d%%)", int(hp * 100.0 / initHp));
	return std::string(buffer);
}
