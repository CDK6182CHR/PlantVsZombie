#pragma once
#include "NormalZombie.h"
class PaperZombie :
	public NormalZombie
{
	static const int speed1 = -2, speed2 = -6;
protected:
	virtual inline int initHp()const override { return 16; }
	virtual int speed()const override;
public:
	PaperZombie(System& system);
	virtual inline std::string toString()const override { return "¶Á±¨½©Ê¬"; }
	virtual std::string getStatus()const override;
private:
	bool hasPaper()const;
};

