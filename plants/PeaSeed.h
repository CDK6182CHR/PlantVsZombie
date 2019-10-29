#pragma once
#include "Seed.h"

class System;
class Plant;
class PeaSeed :
	public Seed
{
public:
	PeaSeed(System& sys,Plant& pl);
	virtual inline int damage() { return 2; }
	virtual inline int speed() { return 3; }
	virtual inline char toChar() const { return 'o'; }
};

