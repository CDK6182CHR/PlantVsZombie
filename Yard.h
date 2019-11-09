/*
整个庭院对象。是block的集合。
*/
#pragma once
#include "Block.h"
#include <sstream>
#include <list>

#define ROWS 5
#define COLS 8
class Terminal;

class Yard
{
	Block blocks[ROWS][COLS];
	Terminal* terminal;
public:
	Yard();
	void updateUI();
	void update();//时间更新引起，在所有植物僵尸更新之后调用
	Block* blockAt(int row, int col);
	bool selectBlock(int& row, int& col);  //用户交互，选择地块。返回是否确定。
	Block* upperNeighbor(Block* b);
	Block* downNeighbor(Block* b);
	std::list<Block*> neighborBlocks(Block* b);
private:
	void printHLine();
	int blockWiseRow(int pixelWiseRow)const;
};

