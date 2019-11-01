#include "Terminal.h"
#include "Block.h"
#include "Yard.h"
#include "Shop.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

Terminal* Terminal::instance = nullptr;

Terminal::Terminal():
	hout(GetStdHandle(STD_OUTPUT_HANDLE)),
	coord(),csbi(),sunrayCol(0),splitCol(0),scorePos(),cci(),timePos()
{
	cci.dwSize = 25; cci.bVisible = false;
	setCursorVisible();
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

void Terminal::setCursorVisible()
{
	SetConsoleCursorInfo(hout, &cci);
}

void Terminal::setCursorVisible(bool v)
{
	cci.bVisible = v;
	SetConsoleCursorInfo(hout,&cci);
}

void Terminal::setCursorPos(const COORD& c)
{
	SetConsoleCursorPosition(hout, c);
	setCursorVisible();
}

void Terminal::locateToCol(int x)
{
	GetConsoleScreenBufferInfo(hout, &csbi);
	coord.X = x;
	coord.Y = csbi.dwCursorPosition.Y;
	SetConsoleCursorPosition(hout,coord);
	setCursorVisible();
}

void Terminal::locateToRow(int row)
{
	int r = YardStartRow + row * Block::PIXES_PER_ROW;
	coord.X = 0;
	coord.Y = r;
	SetConsoleCursorPosition(hout, coord);
	setCursorVisible();
}

void Terminal::locateToPixelRow(int rowpix)
{
	coord.X = 0;
	coord.Y = rowpix;
	SetConsoleCursorPosition(hout, coord);
	setCursorVisible();
}

void Terminal::locateToBlock(int row, int col)
{
	coord.X = Block::PIXES_PER_COL * col+1;
	coord.Y = Block::PIXES_PER_ROW * row+1;
	SetConsoleCursorPosition(hout, coord);
	setCursorVisible();
}

int Terminal::getTimeRow()const
{
	return Block::PIXES_PER_ROW * ROWS+1;
}

void Terminal::locateToPlant(int index)
{
	int localRow = index / Shop::PlantsPerRow;
	int globalRow = Block::PIXES_PER_ROW * ROWS + 5 + localRow;
	coord.Y = globalRow;
	coord.X = (index % Shop::PlantsPerRow) * Shop::LengthPerPlant;
	SetConsoleCursorPosition(hout,coord);
	setCursorVisible();
}

void Terminal::locateToTimeStamp()
{
	SetConsoleCursorPosition(hout, timePos);
	setCursorVisible();
}

void Terminal::locateToScorePos()
{
	SetConsoleCursorPosition(hout,scorePos);
	setCursorVisible();
}

void Terminal::markSunrayPos()
{
	sunrayPos.X = getCurrentCol();
	sunrayPos.Y = getCurrentRow();
}

void Terminal::setTimePos(int r, int c)
{
	timePos.X = c;
	timePos.Y = r;
	statusPos.X = 0;
	statusPos.Y = r;
}

void Terminal::updateTimeStamp()
{
	locateToTimeStamp();
	cout << Placeable::timestamp;
}

void Terminal::updateSunray(int s)
{
	setCursorPos(sunrayPos);
	cout << "     ";
	setCursorPos(sunrayPos);
	cout << s;
}

void Terminal::clearStatus()
{
	int len = timePos.X - 10;
	setCursorPos(statusPos);
	cout << setw(len) << ' ';
}

void Terminal::showStatus(const std::string& msg)
{
	clearStatus();
	setCursorPos(statusPos);
	cout << msg;
}

ControlKey Terminal::getKey()
{
	int k = _getch();
	if (k == 0xE0)
		k = _getch();
	switch (k) {
	case 'b':return BuyPlant;
	case 'c':return RemovePlant;
	case 'x':return GiveUp;
	case 'q':return Quit;
	case 72:return KeyUp;
	case 80:return KeyDown;
	case 75:return KeyLeft;
	case 77:return KeyRight;
	case 13:return KeyEnter;
	default:return Invalid;
	}
}
