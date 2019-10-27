/*
场地上的一个地块。用数组下标访问，有效域从0开始。
 */
#pragma once
#include <list>

class Plant;
class Zombie;
class Seed;

class Block
{
	std::list<Zombie*> zombies;
	Plant* plant;
	int row, col;
public:
	static const int PIXES_PER_COL = 9, //每一格对应的列数。包含左边界。
		PIXES_PER_ROW = 4;//每一格对应的行数，包含上边界。
	Block();//默认构造，构造后再设置具体参数
	void init(int r, int c);//必须
	void addZombie(Zombie* zombie);
	void removeZombie(Zombie* zombie);
	void setPlant(Plant* plant);
	Plant* currentPlant();
	std::list<Zombie*>& getZombies();
	void removePlant();
};

