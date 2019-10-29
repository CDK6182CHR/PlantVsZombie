/*
对应于shop的僵尸产生类。
*/
#pragma once
#include "Factory.h"
class System;
class ZombieGenerator
{
	System& system;
	static const int N = 2;
	AbstractFactory* factories[N];
public:
	ZombieGenerator(System& sys);
	void generate();
	~ZombieGenerator();
private:
	int totalWeight()const;
	AbstractFactory* getFactory(int x);
	void makeZombie(AbstractFactory* factory);
};

