/*
系统管理主类
*/
#pragma once
#include "Yard.h"
#include <list>
#include "Placeable.h"
#include "plants\Seed.h"

class System
{
	int sunrays, scores;
	std::list<Placeable*> items;
	std::list<Seed*> seeds;
public:
	Yard yard; //组合！
	System();
	void update();//负责修改时间戳，调用所有对W象的update
	void addItem(Placeable* item);
	void removeItem(Placeable* item);
	void addSeed(Seed* seed);
	void removeSeed(Seed* seed);
};

