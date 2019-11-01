#include "IcePeaSeed.h"
#include "../zombies/Zombie.h"
IcePeaSeed::IcePeaSeed(System& sys, Plant& parent):PeaSeed(sys,parent)
{
}

void IcePeaSeed::attactZombie(Zombie* zombie)
{
	Seed::attactZombie(zombie);
	zombie->slowDown(5);
}
