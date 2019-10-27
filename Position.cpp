#include "Position.h"

Position::Position(Yard& yd):yard(yd),row(-1),colpix(-1)
{
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

