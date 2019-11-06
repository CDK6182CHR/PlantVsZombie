/*
��Ӧ��shop�Ľ�ʬ�����ࡣ
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
	double rate()const;  //���ص�ǰʱ�����ڲ�����ʬ�ĸ���
	bool inGroupMode()const;
	int truns()const;
};

