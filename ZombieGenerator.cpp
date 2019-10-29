#include "ZombieGenerator.h"
#include "zombies/NormalZombie.h"
#include "zombies/RoadblockZombie.h"

ZombieGenerator::ZombieGenerator(System& sys):system(sys)
{
	factories[0] = new Factory<NormalZombie>(system);
	factories[1] = new Factory<RoadblockZombie>(system);
}

ZombieGenerator::~ZombieGenerator()
{
	for (int i = 0; i < N; i++)
		delete factories[i];
}
