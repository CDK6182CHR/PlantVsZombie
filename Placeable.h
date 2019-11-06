/*
所有可放在画面上的基类。
抽象地，也包括子弹。
*/
#pragma once
#include "Position.h"
#include <string>

class Yard;
class Block;
class System;

class Placeable
{
protected:
	Position position;//组合关系
	System& system;
	bool active;
public:
	static int timestamp;
	Placeable(System& sys);
	virtual void update() = 0; //不负责修改时间戳
	virtual void place() = 0;
	virtual void remove() = 0; //Seed和其他类的remove方法会有不同，故此
	inline bool isActive()const {
		return active;
	}
	Position& getPosition();
	Block* getBlock();
	int getRow();
	int getColpix();
	void setPosition(int row, int colpix);
};

