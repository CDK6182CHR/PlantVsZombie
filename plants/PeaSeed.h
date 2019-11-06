#pragma once
#include "Seed.h"

class System;
class Plant;
class PeaSeed :
	public Seed
{
public:
	PeaSeed(System& sys,Plant& pl);
	virtual inline int damage()const override { return 2; }
	virtual inline int speed()const override { return 6; }
	virtual inline char toChar() const override{ return 'o'; }
};

