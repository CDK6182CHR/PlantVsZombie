/*
�ش̣��������������ص��ǲ����Ա��ԡ�
*/
#pragma once
#include "Plant.h"
class Thorn :
	public Plant
{
	static const int damage = 1;
protected:
	virtual inline int initHp()const { return 1; }
public:
	Thorn(System& system);
	virtual inline std::string toString()const override { return "�ش�"; }
	virtual inline bool eatable()const override { return false; }
	virtual inline bool hasStatus()const override { return false; } //����Ҫ״̬��
	virtual void update()override;
};

