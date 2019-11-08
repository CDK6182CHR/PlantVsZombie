#pragma once
#include "Plant.h"
class CherryBomb :
	public Plant
{
	int explodeTime;
protected:
	virtual inline int initHp()const override { return 50; }
public:
	CherryBomb(System& system);
	virtual inline std::string toString()const override { return "”£Ã“’®µØ"; }
	virtual inline bool hasStatus()const override { return false; }
	virtual void update()override;
};

