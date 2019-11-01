#pragma once
#include "NormalZombie.h"
class BucketZombie :
	public NormalZombie
{
protected:
	virtual inline int initHp()const override { return 40; }
	virtual inline int score()const override { return 4; }
public:
	BucketZombie(System& system);
	virtual inline std::string toString()const override { return "ÌúÍ°½©Ê¬"; }
};

