#include "ZombieGenerator.h"
#include "zombies/NormalZombie.h"
#include "zombies/RoadblockZombie.h"
#include "Yard.h"
#include <stdlib.h>
#include <time.h>

ZombieGenerator::ZombieGenerator(System& sys):system(sys)
{
	srand(time(nullptr));
	factories[0] = new ZombieFactory<NormalZombie>(system,20,20);
	factories[1] = new ZombieFactory<RoadblockZombie>(system,10,50);
}

/*
ÿ��ʱ��������30%�ĸ��ʲ�����ʬ
*/
void ZombieGenerator::generate()
{
	int tw = totalWeight();
	if (tw == 0)
		return;
	int upper = int(tw * 10.0 / 1);
	int r = rand() % upper;
	if (r < tw) {
		makeZombie(getFactory(r));
	}
}

ZombieGenerator::~ZombieGenerator()
{
	for (int i = 0; i < N; i++)
		delete factories[i];
}

int ZombieGenerator::totalWeight() const
{
	int tw = 0;
	for (int i = 0; i < N; i++)
		if (factories[i]->available())
			tw += factories[i]->getWeight();
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
