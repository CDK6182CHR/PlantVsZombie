#pragma once
#include "NormalZombie.h"
class RoadblockZombie :
	public NormalZombie
{
protected:
	//virtual inline int damage()const { return 2; }
	//virtual inline int speed()const { return -1; }
	virtual inline int initHp()const override { return 20; }
	virtual inline int score()const override { return 2; }
public:
	RoadblockZombie(System& sys);
	virtual inline std::string toString()const { return "Â·ÕÏ½©Ê¬"; }
	//virtual std::string getStatus()const;

};

