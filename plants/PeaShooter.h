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
	virtual inline std::string toString()const { return "�㶹����"; }
	virtual inline bool available()const { return timestamp >= nextAvailableTime; }
	virtual std::string getStatus()const;
private:
	void shoot();//����һ���㶹���󣬰������뵽Yard�С�ֻ�����䡣ԭ����ֻ���Լ�����
};

