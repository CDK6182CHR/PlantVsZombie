#pragma once

#include "../Placeable.h"

class Yard;

class Plant:
	public Placeable
{
protected:
	int hp;//当前生命值
	virtual inline int initHp()const = 0;
public:
	Plant(System& sys);
	void place();//放置
	void remove();//从Yard中删除，不负责删除自身。
	virtual inline bool eatable()const { return true; }//地刺不能被吃, 其他的基本上都是true
	void eaten(int dh);//被吃时调用。如果不是eatable则不执行任何操作。
	void setBlock(int row, int col); //对植物来说其实不存在具体的列，设置到指定的行就可以了。
	virtual inline bool hasStatus()const { return true; }
	virtual inline std::string getStatus()const;
	virtual inline std::string toString()const = 0;//约定不超过一格宽度
};

