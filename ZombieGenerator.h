/*
��Ӧ��shop�Ľ�ʬ�����ࡣ
*/
#pragma once
#include "ZombieFactory.h"
class System;
class ZombieGenerator
{
	System& system;
	static const int N = 4;
	AbstractZombieFactory* factories[N];
public:
	ZombieGenerator(System& sys);
	void generate();
	~ZombieGenerator();
private:
	int totalWeight()const;
	AbstractZombieFactory* getFactory(int x);
	void makeZombie(AbstractZombieFactory* factory);
};

