#include "NormalZombie.h"

NormalZombie::NormalZombie(System& sys):Zombie(sys)
{
	hp = initHp;
}

std::string NormalZombie::getStatus() const
{
	char buffer[100];
	sprintf_s(buffer, "(%d%%)", int(hp * 100.0 / initHp));
	return std::string(buffer);
}
