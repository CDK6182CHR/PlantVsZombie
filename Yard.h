/*
整个庭院对象。是block的集合。
*/
#pragma once
#include "Block.h"

#define ROWS 5
#define COLS 7

class Yard
{
	Block blocks[ROWS][COLS];
public:
	void diaplay()const;
	void update();//时间更新引起
};

