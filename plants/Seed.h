/*
�㶹��֮��ģ�ֲ����ӵ�
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
	Seed(System& sys,Plant& parent);//��Ҫ��plant��ȡposition��Ϣ
	virtual void remove();
	inline virtual int damage() = 0;
	inline virtual int speed() = 0;
	virtual void explode();//��ը��Ĭ���ǶԸ�����Ľ�ʬ����damage()���˺����������remove��
	virtual void update();//����λ�ã����������ʬ���ñ�ը
	virtual inline char toChar()const=0;
};

