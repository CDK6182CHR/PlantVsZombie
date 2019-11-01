#pragma once
#include "Plant.h"
#include <string>
class Yard;

class PeaShooter :
	public Plant
{
	static const int interval = 4;
	int nextShootTime;
protected:
	virtual inline int initHp()const override { return 10; }
public:
	PeaShooter(System& sys);
	virtual void update();
	virtual inline std::string toString()const { return "�㶹����"; }
protected:
	virtual void shoot();//����һ���㶹���󣬰������뵽Yard�С�ֻ�����䡣ԭ����ֻ���Լ�����
};

