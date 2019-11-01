#include "Block.h"
#include "plants/Plant.h"
#include "plants/Seed.h"
#include "zombies/Zombie.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

Block::Block():
	plant(nullptr),row(-1),col(-1),itemStrings(nullptr),zombies(),seeds()
{
	itemStrings = new string[PIXES_PER_ROW];//第0个永远是空白，无效的
}

void Block::init(int r, int c)
{
	row = r;
	col = c;
}

void Block::addZombie(Zombie* zombie)
{
	zombies.push_back(zombie);
}

void Block::removeZombie(Zombie* zombie)
{
	zombies.remove(zombie);
}

void Block::addSeed(Seed* seed)
{
	seeds.push_back(seed);
}

void Block::removeSeed(Seed* seed)
{
	seeds.remove(seed);
}

void Block::setPlant(Plant* plant)
{
	if (this->plant == nullptr)
		this->plant = plant;
}

Plant* Block::currentPlant()
{
	return plant;
}

std::list<Zombie*>& Block::getZombies()
{
	return zombies;
}

int Block::zombieCount() const
{
	return zombies.size();
}

void Block::removePlant()
{
	plant = nullptr;
}

std::string Block::getBlockText(int row) const
{
	if (row <= 0 || row > PIXES_PER_ROW)
		return "";
	return itemStrings[row];
}

void Block::update()
{
	updateStrings();
}

Block::~Block()
{
	delete[] itemStrings;
	itemStrings = nullptr;
}

void Block::updateStrings()
{
	//先无条件处理子弹
	//处理Seed。优先按照实际位置放。
	if (!seeds.empty()) {
		char seedLine[PIXES_PER_COL];
		seedLine[PIXES_PER_COL - 1] = (char)0;
		int cb = PIXES_PER_COL - 1;//col-bound
		for (int i = 0; i < cb; i++)
			seedLine[i] = ' ';
		for (Seed* sd : seeds) {
			int c = localColpix(sd->getPosition().getColpix());
			if (seedLine[c] == ' ')
				seedLine[c] = sd->toChar();
			else {
				//优先往左放
				bool found = false;
				for (int i = c - 1; i >= 0; i--) {
					if (seedLine[i] == ' ') {
						seedLine[i] = sd->toChar();
						found = true;
						break;
					}
				}
				if (!found) {
					for (int i = c + 1; i < cb; i++) {
						if (seedLine[i] == ' ') {
							seedLine[i] = sd->toChar();
							found = true;
							break;
						}
					}
				}
			}
		}
		itemStrings[1] = string(seedLine);
	}
	else {
		itemStrings[1] = string("");
	}
	//再设计其他内容
	int originRows = zombies.size();
	const int maxrow = PIXES_PER_ROW - 2;
	if (plant != nullptr)
		originRows += 1;
	bool showZombie = true, showZombieDetail = false;
	bool showPlantDetail = false;
	if (originRows > maxrow) {
		//如果超过，僵尸只写数量
		showZombie = false;
		originRows -= zombies.size() - 1;
	}
	//如果这时候还有空间，优先写植物状态
	if (originRows < maxrow&&plant!=nullptr&&plant->hasStatus()) {
		showPlantDetail = true;
		originRows += 1;
	}
	if (maxrow - originRows >= zombies.size()) {
		//足够写每一只僵尸的状态，则写出所有僵尸状态，否则不写
		showZombieDetail = true;
		originRows += zombies.size();
	}
	//开始写入
	int startRow = 2 + (maxrow - originRows) / 2;
	for (int i = 2; i < startRow; i++)
		itemStrings[i] = string("");
	int t = startRow;
	if (plant != nullptr) {
		itemStrings[t++] = plant->toString();
		if (showPlantDetail)
			itemStrings[t++] = plant->getStatus();
	}
	
	if (showZombie) {
		for (Zombie* zb : zombies) {
			itemStrings[t++] = zb->toString();
			if (showZombieDetail)
				itemStrings[t++] = zb->getStatus();
		}
	}
	else {
		char buffer[100];
		sprintf_s(buffer,100, "%d只僵尸", zombies.size());
		itemStrings[t++] = string(buffer);
	}
	while (t < PIXES_PER_ROW)
		itemStrings[t++] = string("");
}

//返回0对应第1列。
int Block::localColpix(int globalColpix) const
{
	return globalColpix - col * PIXES_PER_COL - 1;
}
