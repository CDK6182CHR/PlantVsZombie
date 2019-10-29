#pragma once
#include "../Placeable.h"

class Plant;
class Zombie:
	public Placeable
{
protected:
	int hp;
	virtual inline int damage()const = 0;
	virtual inline int speed()const = 0;//保证每个时钟周期不能超过一行以上。
public:
	Zombie(System& sys);
	void place();
	void remove();
	virtual void eat(Plant* plant);
	virtual void update();
	void attacked(int dh);
	virtual inline std::string getStatus()const = 0;
	virtual inline std::string toString()const = 0;//约定不超过一格宽度
};

