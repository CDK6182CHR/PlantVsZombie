/*
���пɷ��ڻ����ϵĻ��ࡣ
����أ�Ҳ�����ӵ���
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
	Position position;//��Ϲ�ϵ
	System& system;
	bool active;
public:
	static int timestamp;
	Placeable(System& sys);
	virtual void update() = 0; //�������޸�ʱ���
	virtual void place() = 0;
	virtual void remove() = 0; //Seed���������remove�������в�ͬ���ʴ�
	inline bool isActive()const {
		return active;
	}
	Position& getPosition();
	Block* getBlock();
	int getRow();
	int getColpix();
	void setPosition(int row, int colpix);
};

