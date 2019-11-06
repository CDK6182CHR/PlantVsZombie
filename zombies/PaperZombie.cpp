#include "PaperZombie.h"

int PaperZombie::speed() const
{
	if (hasPaper())
		return timestamp > normalSpeedTime ? speed1 : speed1 / 2;
	else
		return timestamp > normalSpeedTime ? speed2 : speed2 / 2;
}

PaperZombie::PaperZombie(System& system):NormalZombie(system)
{
	hp = initHp();
}

std::string PaperZombie::getStatus() const
{
	if (hasPaper())
		return "(ÓÐ±¨Ö½)";
	else
		return NormalZombie::getStatus();
}

bool PaperZombie::hasPaper() const
{
	return hp > 10;
}
