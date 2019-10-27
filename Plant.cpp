#include "plants\Plant.h"
#include "Block.h"
#include "System.h"
#include "Position.h"

Plant::Plant(System& sys):Placeable(sys),hp(0)
{
}

/*
precondition: position所示位置没有植物
*/
void Plant::place()
{
	Block* pBlock = position.target();
	if (pBlock->currentPlant() == nullptr) {
		pBlock->setPlant(this);
	}
	system.addItem(this);
}

void Plant::remove()
{
	Block* pBlock = position.target();
	if (pBlock->currentPlant() == this)
		pBlock->removePlant();
	system.removeItem(this);
}

void Plant::eaten(int dh)
{
	hp -= dh;
	if (hp <= 0)
		remove();
}

void Plant::setBlock(int row, int col)
{
	position.setBlock(row, col);
}
