/*
ϵͳ��������
*/
#pragma once
#include "Yard.h"
#include <list>
#include "Placeable.h"
#include "plants\Seed.h"
#include "Shop.h"

class System
{
	int sunrays, scores;
	std::list<Placeable*> items;
	std::list<Seed*> seeds;
	static const int SunrayInterval = 20, SunrayUnit = 25;
	Shop shop; //ֵ
public:
	Yard yard; //ֵ
	System();
	void mainLoop();//���¼�ѭ��
	void update();//�����޸�ʱ������������ж�W���update
	void addItem(Placeable* item);
	void removeItem(Placeable* item);
	void addSeed(Seed* seed);
	void removeSeed(Seed* seed);
	void gameOver(Zombie* winner);
	void addSunray(int ds);
private:
	//���û�ָ��ֱ�ӵ��õĺ���
	void buyPlant();
	void removePlant();
};

