#pragma once

#include "../Placeable.h"

class Yard;

class Plant:
	public Placeable
{
protected:
	int hp;//生命值。每个子类设置一个static的生命值，初始化时自动放进去。
public:
	Plant(System& sys);
	void place();//放置
	void remove();//从Yard中删除，不负责删除自身。
	virtual inline bool eatable() { return true; }//地刺不能被吃, 其他的基本上都是true
	void eaten(int dh);//被吃时调用。如果不是eatable则不执行任何操作。
	void setBlock(int row, int col); //对植物来说其实不存在具体的列，设置到指定的行就可以了。
};

