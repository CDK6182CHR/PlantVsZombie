#include "ZombieGenerator.h"
#include "zombies/zombies.h"
#include "Yard.h"
#include <stdlib.h>
#include <time.h>

ZombieGenerator::ZombieGenerator(System& sys) :system(sys),
factories{
	new ZombieFactory<NormalZombie>(system,10,50),
	new ZombieFactory<RoadblockZombie>(system,10,80),
	new ZombieFactory<BucketZombie>(system, 8, 120),
	new ZombieFactory<PaperZombie>(system,6,140),
	new ZombieFactory<ToyZombie>(system,4,200),
	new ZombieFactory<RugbyZombie>(system, 6, 250),
	new ZombieFactory<FlagZombie>(system, 0, 400),
}
{
	srand(time(nullptr));
}

/*
每个时钟周期以30%的概率产生僵尸
*/
void ZombieGenerator::generate()
{
	int avtw;
	int tw = totalWeight(avtw);
	double rt = rate() * avtw / tw;
	if (Placeable::timestamp % GroupInterval == GroupInterval - GroupLength - 1)
		makeZombie(factories[4]);
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
	//产生概率从0.2至0.6渐进增加
	else {
		return 0.4;
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
