/*
整个庭院对象。是block的集合。
*/
#pragma once
#include "Block.h"
#include <sstream>


#define ROWS 5
#define COLS 7

class Yard
{
	Block blocks[ROWS][COLS];
public:
	Yard();
	void display();
	void update();//时间更新引起，在所有植物僵尸更新之后调用
	Block* blockAt(int row, int col);
	std::stringstream sout;
private:
	void printHLine();
	int blockWiseRow(int pixelWiseRow)const;
};

