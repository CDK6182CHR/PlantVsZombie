#include "Yard.h"
#include "Position.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include "Placeable.h"
#include "Terminal.h"
using namespace std;

Yard::Yard():terminal(Terminal::getInstance())
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			blocks[i][j].init(i,j);
	const int rows = ROWS * Block::PIXES_PER_ROW, cols = COLS * Block::PIXES_PER_COL;
	for (int i = 0; i < rows; i++) {
		int localRow = i % Block::PIXES_PER_ROW;
		int blockRow = blockWiseRow(i);
		if (localRow == 0) {
			printHLine();
		}
		else {
			//内层是对block做循环，循环意义不同。
			for (int t = 0; t < COLS; t++) {
				Block* block = blockAt(blockRow, t);
				cout << '#';
				cout << setw(Block::PIXES_PER_COL - 1) << setiosflags(ios::left) <<
					block->getBlockText(localRow);
			}
			cout << '#' << endl;
		}
	}
	printHLine();
	terminal->locateToPixelRow(terminal->getTimeRow());
	terminal->locateToCol(50);
	cout << "| 当前时间: ";
	terminal->setTimePos(terminal->getCurrentRow(), terminal->getCurrentCol());
	cout << Placeable::timestamp;
}

void Yard::updateUI()
{
	const int rows = ROWS * Block::PIXES_PER_ROW, cols = COLS * Block::PIXES_PER_COL;
	for (int i = 0; i < rows; i++) {
		terminal->locateToPixelRow(i);
		int localRow = i % Block::PIXES_PER_ROW;
		int blockRow = blockWiseRow(i);
		if (localRow!=0){
			//内层是对block做循环，循环意义不同。
			for (int t = 0; t < COLS; t++) {
				Block* block = blockAt(blockRow, t);
				cout << '#';
				
				cout << setw(Block::PIXES_PER_COL - 1) << setiosflags(ios::left) <<
					block->getBlockText(localRow);
			}
			cout << '#' << endl;
		}
	}
	terminal->updateTimeStamp();
}

void Yard::update()
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			blocks[i][j].update();
}

Block* Yard::blockAt(int row, int col)
{
	if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
		return &blocks[row][col];
	return nullptr;
}

bool Yard::selectBlock(int& row, int& col)
{
	terminal->locateToBlock(row, col);
	while (true) {
		ControlKey key = terminal->getKey();
		switch (key)
		{
		case KeyUp: {
			if (row > 0) {
				row--;
				terminal->locateToBlock(row, col);
			}
		}
				  break;
		case KeyDown: {
			if (row < ROWS - 1) {
				row++;
				terminal->locateToBlock(row, col);
			}
		}
					break;
		case KeyLeft: {
			if (col > 0) {
				col--;
				terminal->locateToBlock(row, col);
			}
		}
					break;
		case KeyRight:
			if (col < COLS - 1) {
				col++;
				terminal->locateToBlock(row, col);
			}
			break;
		case KeyEnter: {
			return true;
			
		}
					 break;
		case GiveUp:
			return false;
		}
	}
}

void Yard::printHLine() 
{
	for (int i = 0; i < COLS * Block::PIXES_PER_COL + 1; i++)
		cout << '#';
	cout << endl;
}

int Yard::blockWiseRow(int pixelWiseRow) const
{
	return pixelWiseRow / Block::PIXES_PER_ROW;
}
