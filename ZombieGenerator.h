/*
��Ӧ��shop�Ľ�ʬ�����ࡣ
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
};

