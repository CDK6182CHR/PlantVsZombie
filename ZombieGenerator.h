/*
对应于shop的僵尸产生类。
*/
#pragma once
#include "ZombieFactory.h"
class System;
class ZombieGenerator
{
	System& system;
	static const int N = 7, GroupInterval = 500, GroupLength = 80;
	AbstractZombieFactory* factories[N];
public:
	ZombieGenerator(System& sys);
	void generate();
	~ZombieGenerator();
private:
	int totalWeight(int& availableSum)const;
	AbstractZombieFactory* getFactory(int x);
	void makeZombie(AbstractZombieFactory* factory);
	double rate()const;  //返回当前时钟周期产生僵尸的概率
	bool inGroupMode()const;
	int truns()const;
};

