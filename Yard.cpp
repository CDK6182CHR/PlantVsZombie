#include "Yard.h"

Block* Yard::blockAt(int row, int col)
{
	if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
		return &blocks[row][col];
	return nullptr;
}
