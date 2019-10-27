/*
ϵͳ��������
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
	Yard yard; //��ϣ�
	System();
	void update();//�����޸�ʱ������������ж�W���update
	void addItem(Placeable* item);
	void removeItem(Placeable* item);
	void addSeed(Seed* seed);
	void removeSeed(Seed* seed);
};

