#pragma once
#include "NormalZombie.h"
class RoadblockZombie :
	public NormalZombie
{
	static const int initHp = 20;
protected:
	//virtual inline int damage()const { return 2; }
	//virtual inline int speed()const { return -1; }
public:
	RoadblockZombie(System& sys);
	virtual inline std::string toString()const { return "Â·ÕÏ½©Ê¬"; }
	//virtual std::string getStatus()const;

};

