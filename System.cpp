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
	///////////��������ѭ�����⿪ʼ////////////
	while (true) {
		Sleep(250);
		if (_kbhit()) {
			ControlKey k = terminal->getKey();
			switch (k)
			{
			case Quit:quit(); return;
			case BuyPlant:buyPlant(); break;
			case RemovePlant:removePlant(); break;
			default:
				break;
			}
		}
		update();
	}
}

void System::update()
{
	//��Щupdate�����ж�����ܻᱻɾ��
	Placeable::timestamp++;
	zombieGenerator.generate();
	if (Placeable::timestamp % SunrayInterval == 1)
		addSunray(SunrayUnit);
	//ǰ��Ķ������ܻ�Ѻ���ĸ��������ܼ򵥵ظ���ѭ��
	for (Placeable* p : list<Placeable*>(items))
		p->update();
	for (Seed* p : list<Seed*>(seeds)) {
		p->update();
	}
	commitRemove();
	yard.update();
	yard.updateUI();
	shop.updateUI();
}

void System::addItem(Placeable* item)
{
	items.push_back(item);
}

void System::removeItem(Placeable* item)
{
	toRemove.push_back(item);
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
	exit(0);
}

void System::addSunray(int ds)
{
	sunrays += ds;
}

void System::useSunray(int ds)
{
	sunrays -= ds;
}

void System::addScore(int ds)
{
	scores += ds;
}

void System::commitRemove()
{
	while (!toRemove.empty()) {
		Placeable* p = toRemove.front();
		toRemove.pop_front();
		items.remove(p);
		delete p;
	}
}

void System::buyPlant()
{
	shop.buy();
}

void System::removePlant()
{
	terminal->showStatus("���ӣ��������ѡ��ؿ飬ENTERȷ�ϣ�xȡ��");
	terminal->setCursorVisible(true);
	terminal->locateToBlock(0, 0);
	int row = 0, col = 0;
	bool flag = yard.selectBlock(row, col);
	if (flag) {
		//��ʾȷ��ɾ��
		Block* block = yard.blockAt(row, col);
		Plant* plant = block->currentPlant();
		if (plant == nullptr) {
			terminal->showStatus("��λ��û��ֲ�");
		}
		block->removePlant();
	}
	terminal->clearStatus();
}

void System::quit()
{
}
