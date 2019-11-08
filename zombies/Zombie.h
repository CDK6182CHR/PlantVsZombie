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
	virtual inline int speed()const = 0;//保证每个时钟周期不能超过一行以上。
	virtual inline int initHp()const = 0;
	virtual inline int score()const = 0;
	virtual inline int getBiteInterval()const = 0;
public:
	Zombie(System& sys);
	void move(int dcol, int drow = 0);//封装移动格子操作
	void place();
	void remove();
	virtual void eat(Plant* plant);
	virtual void update();
	virtual void attacked(int dh);
	virtual inline std::string getStatus()const;
	virtual inline std::string toString()const = 0;//约定不超过一格宽度
	virtual void slowDown(int tm);
};

