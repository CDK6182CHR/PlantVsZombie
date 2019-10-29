/*
系统管理主类
*/
#pragma once
#include "Yard.h"
#include <list>
#include "Placeable.h"
#include "plants\Seed.h"
#include "Shop.h"
#include "ZombieGenerator.h"
#include "Terminal.h"

class System
{
	int sunrays, scores;
	std::list<Placeable*> items;
	std::list<Seed*> seeds;
	static const int SunrayInterval = 20, SunrayUnit = 25;
public:
	Yard yard; //值。必须保证yard在shop之前构造。
private:
	Shop shop; //值
	ZombieGenerator zombieGenerator;  //值
	Terminal* terminal;
public:
	System();
	void mainLoop();//主事件循环
	void update();//负责修改时间戳，调用所有对W象的update
	void addItem(Placeable* item);
	void removeItem(Placeable* item);
	void addSeed(Seed* seed);
	void removeSeed(Seed* seed);
	void gameOver(Zombie* winner);
	void addSunray(int ds);
	void addScore(int ds);
	inline int getSunray()const {
		return sunrays;
	}
	inline int getScore()const {
		return scores;
	}
private:
	//由用户指令直接调用的函数
	void buyPlant();
	void removePlant();
};

