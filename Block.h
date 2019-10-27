/*
�����ϵ�һ���ؿ顣�������±���ʣ���Ч���0��ʼ��
 */
#pragma once
#include <list>

class Plant;
class Zombie;
class Seed;

class Block
{
	std::list<Zombie*> zombies;
	Plant* plant;
	int row, col;
public:
	static const int PIXES_PER_COL = 9, //ÿһ���Ӧ��������������߽硣
		PIXES_PER_ROW = 4;//ÿһ���Ӧ�������������ϱ߽硣
	Block();//Ĭ�Ϲ��죬����������þ������
	void init(int r, int c);//����
	void addZombie(Zombie* zombie);
	void removeZombie(Zombie* zombie);
	void setPlant(Plant* plant);
	Plant* currentPlant();
	std::list<Zombie*>& getZombies();
	void removePlant();
};

