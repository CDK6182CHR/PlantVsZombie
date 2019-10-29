#include "Terminal.h"
#include "Block.h"
#include "Yard.h"
#include "Shop.h"

Terminal* Terminal::instance = nullptr;

Terminal::Terminal():
	hout(GetStdHandle(STD_OUTPUT_HANDLE)),
	coord(),csbi(),sunrayCol(0),splitCol(0)
{
	//控制台隐藏光标
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hout, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(hout, &CursorInfo);
}

Terminal* Terminal::getInstance()
{
	if (instance == nullptr)
		instance = new Terminal();
	return instance;
}

int Terminal::getCurrentCol()
{
	GetConsoleScreenBufferInfo(hout, &csbi);
	return csbi.dwCursorPosition.X;
}

int Terminal::getCurrentRow()
{
	GetConsoleScreenBufferInfo(hout, &csbi);
	return csbi.dwCursorPosition.Y;
}

void Terminal::locateToCol(int x)
{
	GetConsoleScreenBufferInfo(hout, &csbi);
	coord.X = x;
	coord.Y = csbi.dwCursorPosition.Y;
	SetConsoleCursorPosition(hout,coord);
}

void Terminal::locateToRow(int row)
{
	int r = YardStartRow + row * Block::PIXES_PER_ROW;
	coord.X = 0;
	coord.Y = r;
	SetConsoleCursorPosition(hout, coord);
}

void Terminal::locateToPixelRow(int rowpix)
{
	coord.X = 0;
	coord.Y = rowpix;
	SetConsoleCursorPosition(hout, coord);
}

void Terminal::locateToTimeRow()
{
	int r = Block::PIXES_PER_ROW * ROWS+1;
	coord.X = 0;
	coord.Y = r;
	SetConsoleCursorPosition(hout, coord);
}

void Terminal::locateToPlant(int index)
{
	int localRow = index / Shop::PlantsPerRow;
	int globalRow = Block::PIXES_PER_ROW * ROWS + 5;
	coord.Y = globalRow;
	coord.X = index % Shop::PlantsPerRow * Shop::LengthPerPlant;
	SetConsoleCursorPosition(hout,coord);
}

void Terminal::locateToScorePos()
{
	SetConsoleCursorPosition(hout,scorePos);
}
