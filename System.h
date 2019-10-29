/*
ϵͳ��������
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
	Yard yard; //ֵ�����뱣֤yard��shop֮ǰ���졣
private:
	Shop shop; //ֵ
	ZombieGenerator zombieGenerator;  //ֵ
	Terminal* terminal;
public:
	System();
	void mainLoop();//���¼�ѭ��
	void update();//�����޸�ʱ������������ж�W���update
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
	//���û�ָ��ֱ�ӵ��õĺ���
	void buyPlant();
	void removePlant();
};

