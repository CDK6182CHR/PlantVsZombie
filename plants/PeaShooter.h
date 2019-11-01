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
	virtual inline std::string toString()const { return "豌豆射手"; }
protected:
	virtual void shoot();//创建一个豌豆对象，把它加入到Yard中。只负责发射。原则上只能自己调用
};

