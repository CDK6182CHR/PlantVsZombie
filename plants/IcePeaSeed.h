#pragma once
#include "PeaSeed.h"
class IcePeaSeed :
	public PeaSeed
{
public:
	IcePeaSeed(System& sys, Plant& parent);
	virtual void attactZombie(Zombie* zombie)override;
	virtual inline char toChar()const override { return '*'; }
};

