#pragma once
#include "../Placeable.h"

class Plant;
class Zombie:
	public Placeable
{
protected:
	int hp;
	int nextBiteTime, normalSpeedTime;
	virtual inline int damage()const = 0;
	virtual inline int speed()const = 0;//��֤ÿ��ʱ�����ڲ��ܳ���һ�����ϡ�
	virtual inline int initHp()const = 0;
	virtual inline int score()const = 0;
	virtual inline int getBiteInterval()const = 0;
public:
	Zombie(System& sys);
	void place();
	void remove();
	virtual void eat(Plant* plant);
	virtual void update();
	void attacked(int dh);
	virtual inline std::string getStatus()const;
	virtual inline std::string toString()const = 0;//Լ��������һ����
	virtual void slowDown(int tm);
};

