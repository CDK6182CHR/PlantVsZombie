#pragma once
#include "Seed.h"
class Watermelon :
	public Seed
{
public:
	Watermelon(System& system, Plant& parent);
	virtual inline char toChar()const override { return 'O'; }
	virtual inline int damage()const override { return 5; }
	virtual inline int speed()const override { return 6; }
	virtual void explode()override;
};

