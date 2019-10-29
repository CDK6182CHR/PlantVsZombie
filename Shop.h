#pragma once
#include "plants/Plant.h"
#include "plants/Seed.h"
#include "Terminal.h"
#include "PlantFactory.h"

class System;
class Yard;
class Shop
{
	System& system;
	Terminal* terminal;
	Yard& yard;
	const static int LengthPerPlant = 40,//商店中每个植物的长度，字符
		PlantsPerRow = 2, //每行显示多少植物
		N = 1; //一共多少种植物
	AbstractPlantFactory* factories[N];
public:
	Shop(System& sys);
	Plant* buy();//涉及交互，负责向yard添加植物
	~Shop();
	void updateUI();
	friend class Terminal;
private:
	void initUI();
};

