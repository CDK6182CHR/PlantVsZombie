#include "ToyZombie.h"
#include <cstdlib>
#include <list>
#include "../System.h"
using namespace std;

ToyZombie::ToyZombie(System& system):NormalZombie(system)
{
	hp = initHp();
}

void ToyZombie::update()
{
	int r = rand() % 100;
	if (r <= rate())
		explode();
	else
		NormalZombie::update();
}

void ToyZombie::explode()
{
	Block* block = position.target();
	if (block->currentPlant())
		block->currentPlant()->remove();
	block->setStatus(BlockStatus::WholeExploded);
	list<Block*> neighbors = system.yard.neighborBlocks(position.target());
	for (Block* block : neighbors) {
		if (block->currentPlant() != nullptr)
			block->currentPlant()->remove();
		block->setStatus(BlockStatus::WholeExploded);
	}
	remove();
}

//�Ա��ĸ��ʰ���20~100%������������������
int ToyZombie::rate() const
{
	int totalColpixes = COLS * Block::PIXES_PER_COL;
	int currentColpix = position.getColpix();
	return int((totalColpixes - currentColpix) * 80.0 / totalColpixes + 20);
}
