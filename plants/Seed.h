/*
豌豆，之类的，植物的子弹
*/

#pragma once
#include "..\Placeable.h"

class Plant;
class System;
class Seed :
	public Placeable
{
protected:
	Plant& parent;
public:
	Seed(System& sys,Plant& parent);//需要从plant获取position信息
	virtual void remove();
	inline virtual int damage() = 0;
	inline virtual int speed() = 0;
	virtual void explode();//爆炸，默认是对格子里的僵尸产生damage()的伤害。负责调用remove。
	virtual void update();//更新位置，如果遇到僵尸调用爆炸
	virtual inline char toChar()const=0;
};

