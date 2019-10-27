#pragma once
#include "../Placeable.h"

class Plant;
class Zombie:
	public Placeable
{
protected:
	int hp;
	virtual inline int damage()const = 0;
	virtual inline int speed()const = 0;//��֤ÿ��ʱ�����ڲ��ܳ���һ�����ϡ�
public:
	Zombie(System& sys);
	void place();
	void remove();
	void eat(Plant* plant);
	virtual void update();
	void attacked(int dh);
};

