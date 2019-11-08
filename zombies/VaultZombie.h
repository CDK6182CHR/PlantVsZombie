#pragma once
#include "NormalZombie.h"
class VaultZombie :
	public NormalZombie
{
	bool hasPole;
protected:
	virtual inline int initHp()const override { return 20; }
public:
	VaultZombie(System& system);
	virtual inline std::string toString()const override { return "³Å¸Ë½©Ê¬"; }
	virtual std::string getStatus()const override;
	virtual void update()override;
};

