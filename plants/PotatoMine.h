/*
�����ף�
��ȴ20��ʱ�����ں�ֱ�ӱ�ը��
*/
#pragma once
#include "Plant.h"
class PotatoMine :
	public Plant
{
	static const int prepareTime = 20;
	const int availableTime;
protected:
	virtual inline int initHp()const override { return 10; }
public:
	PotatoMine(System& system);
	virtual inline std::string toString()const override { return "������"; }
	virtual std::string getStatus()const override;
	virtual void update()override;
};

