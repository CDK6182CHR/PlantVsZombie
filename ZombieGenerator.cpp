#include "ZombieGenerator.h"
#include "zombies/zombies.h"
#include "Yard.h"
#include <stdlib.h>
#include <time.h>

ZombieGenerator::ZombieGenerator(System& sys) :system(sys),
directFactory(new ZombieFactory<FlagZombie>(system, 0, 400)),
factories{
	new ZombieFactory<NormalZombie>(system,10,50),
	//new ZombieFactory<RoadblockZombie>(system,10,80),
	new ZombieFactory<ProtectedZombie<NormalZombie,RoadBlock>>(system,10,80),
	//new ZombieFactory<BucketZombie>(system, 8, 120),
	new ZombieFactory<ProtectedZombie<NormalZombie,CR200J>>(system,8,100),
	new ZombieFactory<ProtectedZombie<NormalZombie,Bucket>>(system,8,120),
	new ZombieFactory<PaperZombie>(system,6,140),
	new ZombieFactory<ProtectedZombie<NormalZombie,Door>>(system,6,200),
	new ZombieFactory<VaultZombie>(system,5,250),
	new ZombieFactory<ToyZombie>(system,4,320),
	new ZombieFactory<RugbyZombie>(system, 6, 400),
	new ZombieFactory<ProtectedZombie<VaultZombie,RoadBlock>>(system,6,800),
}
{
	srand(time(nullptr));
}

/*
每个时钟周期以30%的概率产生僵尸
*/
void ZombieGenerator::generate()
{
	int avtw = 0;
	int tw = totalWeight(avtw);
	double rt = rate();
	if (Placeable::timestamp % GroupInterval == GroupInterval - GroupLength - 1)
		makeZombie(directFactory);
	else if (avtw == 0 || rt==0.0)
		return;
	int upper = int(avtw /rt);
	for (int i = 0; i < truns(); i++) {
		int r = rand() % upper;
		if (r < avtw) {
			makeZombie(getFactory(r));
		}
	}
}

ZombieGenerator::~ZombieGenerator()
{
	for (int i = 0; i < N; i++)
		delete factories[i];
	delete directFactory;
}

int ZombieGenerator::totalWeight(int& availableSum) const
{
	int tw = 0, avtw = 0;
	for (int i = 0; i < N; i++) {
		tw += factories[i]->getWeight();
		if (factories[i]->available())
			avtw += factories[i]->getWeight();
	}
	availableSum = avtw;
	return tw;
}

AbstractZombieFactory* ZombieGenerator::getFactory(const int x)
{
	int cur = 0;
	for (int i = 0; i < N; i++) {
		if (factories[i]->available()) {
			cur += factories[i]->getWeight();
			if (cur > x) {
				return factories[i];
			}
		}
	}
	return nullptr;
}

void ZombieGenerator::makeZombie(AbstractZombieFactory* factory)
{
	if (factory == nullptr)
		return;
	Zombie* z = (Zombie*)(factory->newInstance());
	int row = rand() % ROWS;
	z->setPosition(row, COLS * Block::PIXES_PER_COL - 1);
	z->place();
}

double ZombieGenerator::rate() const
{
	//每500个时钟周期产生一大波，时长50个时钟周期
	int reducedTime = Placeable::timestamp % GroupInterval;
	if (reducedTime == GroupInterval - GroupLength - 1)
		return 0.0;//产生的前一刻，固定释放摇旗僵尸
	else if (reducedTime > GroupInterval - GroupLength)
		return 0.90;
	else {
		if (Placeable::timestamp < GroupInterval)
			return 0.1 + 0.4 * Placeable::timestamp / GroupInterval;
		else
			return 0.5;
	}
}

bool ZombieGenerator::inGroupMode() const
{
	int reducedTime = Placeable::timestamp % GroupInterval;
	return reducedTime >= GroupInterval - GroupLength;
}

int ZombieGenerator::truns() const
{
	if (!inGroupMode())
		return 1;
	//第一轮时只循环1次，后面渐进增加至5次。
	else {
		int n = Placeable::timestamp / GroupInterval;
		if (n < 5)
			return n+1;
		else
			return 5;
	}
}
