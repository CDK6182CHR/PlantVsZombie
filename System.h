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
	std::list<Placeable*> toRemove;
	static const int SunrayInterval = 40, SunrayUnit = 25;
public:
	Yard yard; //ֵ�����뱣֤yard��shop֮ǰ���졣
private:
	Shop shop; //ֵ
	ZombieGenerator zombieGenerator;  //ֵ
	Terminal* terminal;
public:
	System();
	void mainLoop();//���¼�ѭ��
	void update();//�����޸�ʱ������������ж����update
	void addItem(Placeable* item);
	void removeItem(Placeable* item);
	void gameOver(Zombie* winner);
	void addSunray(int ds);
	void useSunray(int ds);
	void addScore(int ds);
	inline int getSunray()const {
		return sunrays;
	}
	inline int getScore()const {
		return scores;
	}
private:
	void commitRemove();
	//���û�ָ��ֱ�ӵ��õĺ���
	void buyPlant();
	void removePlant();
	bool quit();
};

