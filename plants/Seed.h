/*
�㶹��֮��ģ�ֲ����ӵ�
*/

#pragma once
#include "..\Placeable.h"

class Plant;
class System;
class Zombie;

class Seed :
	public Placeable
{
protected:
	Plant& parent;
public:
	Seed(System& sys,Plant& parent);//��Ҫ��plant��ȡposition��Ϣ
	virtual void place()override;
	virtual void remove()override;
	inline virtual int damage()const = 0;
	inline virtual int speed()const = 0;
	virtual void explode();//��ը��Ĭ���ǶԸ�����Ľ�ʬ����damage()���˺����������remove��
	virtual void update();//����λ�ã����������ʬ���ñ�ը
	virtual void attactZombie(Zombie* zombie);
	virtual inline char toChar()const=0;
};

