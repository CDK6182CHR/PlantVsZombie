#pragma once
#include "Plant.h"
#include <string>
class Yard;

class PeaShooter :
	public Plant
{
	static const int initHp = 10, sunrays = 100, interval = 4, coldPeriod = 30;
	static int nextAvailableTime;
	int nextShootTime;
public:
	PeaShooter(System& sys);
	virtual void update();
	virtual inline std::string toString()const { return "豌豆射手"; }
	virtual inline bool available()const { return timestamp >= nextAvailableTime; }
	virtual std::string getStatus()const;
private:
	void shoot();//创建一个豌豆对象，把它加入到Yard中。只负责发射。原则上只能自己调用
};

