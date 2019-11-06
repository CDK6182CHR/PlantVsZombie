#include "Placeable.h"
#include "System.h"

int Placeable::timestamp = 0;

Placeable::Placeable(System& sys):system(sys),position(sys.yard),active(true)
{
}

Position& Placeable::getPosition()
{
	return position;
}

Block* Placeable::getBlock()
{
	return position.target();
}

int Placeable::getRow()
{
	return position.getRow();
}

int Placeable::getColpix()
{
	return position.getColpix();
}

void Placeable::setPosition(int row, int colpix)
{
	position.setPos(row, colpix);
}
