#include "Position.h"
#include "Block.h"
#include "Yard.h"

Position::Position(Yard& yd):yard(yd),row(-1),colpix(-1)
{
}

Block* Position::target()
{
	int bcol = colpix / Block::PIXES_PER_COL + int(colpix % Block::PIXES_PER_COL != 0);
	int brow = row;
	if (bcol >= 0 && bcol < COLS && brow >= 0 && brow < ROWS)
		return yard.blockAt(brow, bcol);
}

void Position::move(int dcol, int drow)
{
	row += drow;
	colpix += dcol;
}

void Position::setRow(int r)
{
	row = r;
}

void Position::setColpix(int c)
{
	colpix = c;
}

void Position::setPos(int row, int colpix)
{
	this->row = row;
	this->colpix = colpix;
}

void Position::setBlock(int row, int col)
{
	colpix = col * Block::PIXES_PER_COL;
	this->row = row;
}

bool Position::inside() const
{
	int bcol = colpix / Block::PIXES_PER_COL + int(colpix % Block::PIXES_PER_COL != 0);
	int brow = row;
	return (bcol >= 0 && bcol < COLS && brow >= 0 && brow < ROWS);
}

