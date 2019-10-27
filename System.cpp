#include "System.h"

System::System():sunrays(0),scores(0)
{
}

void System::update()
{
	Placeable::timestamp++;
	for (Placeable* p : items)
		p->update();
	for (Seed* p : seeds)
		p->update();
}

void System::addItem(Placeable* item)
{
	items.push_back(item);
}

void System::removeItem(Placeable* item)
{
	items.remove(item);
	delete item;
}

void System::addSeed(Seed* seed)
{
	seeds.push_back(seed);
}

void System::removeSeed(Seed* seed)
{
	seeds.remove(seed);
	delete seed;
}
