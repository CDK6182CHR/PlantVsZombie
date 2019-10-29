#include "System.h"
#include <iostream>
#include <conio.h>
#include "zombies/Zombie.h"
#include "plants/PeaShooter.h"
#include "zombies/NormalZombie.h"
#include "zombies/RoadblockZombie.h"

using namespace std;
System::System():
	sunrays(100),scores(0),shop(*this),zombieGenerator(*this),
	terminal(Terminal::getInstance())
{
}

void System::mainLoop()
{
	PeaShooter* ps1 = new PeaShooter(*this), * ps2 = new PeaShooter(*this);
	ps1->setBlock(1, 0);
	ps1->place();
	ps2->setBlock(1, 5);
	ps2->place();
	NormalZombie* nz = new NormalZombie(*this);
	nz->setPosition(1, 56);
	nz->place();
	/*RoadblockZombie* rbz = new RoadblockZombie(*this);
	rbz->setPosition(1, 45);
	rbz->place();*/
	///////////真正的主循环从这开始////////////
	while (true) {
		Sleep(200);
		if (_kbhit()) {
			char ch = _getch();
			switch (ch)
			{
			case 'q':cout << "Bye" << endl; return;
			case 'b':buyPlant(); break;
			case 'c':removePlant(); break;
			default:
				break;
			}
		}
		update();
	}
}

void System::update()
{
	//这些update过程中对象可能会被删掉
	Placeable::timestamp++;
	zombieGenerator.generate();
	for (Placeable* p : list<Placeable*>(items))
		p->update();
	for (Seed* p : list<Seed*>(seeds)) {
		p->update();
	}
	yard.update();
	yard.updateUI();
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

void System::gameOver(Zombie* winner)
{
	cout << "GameOver! " << "winner is " << winner->toString() << endl;
}

void System::addScore(int ds)
{
	scores += ds;
}

void System::buyPlant()
{
	shop.buy();
}

void System::removePlant()
{
	//todo
}
