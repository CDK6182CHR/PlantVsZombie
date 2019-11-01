#include "BucketZombie.h"

BucketZombie::BucketZombie(System& system):NormalZombie(system)
{
	hp = initHp();
}
