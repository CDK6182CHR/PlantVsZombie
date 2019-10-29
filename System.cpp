#include "System.h"
#include <iostream>
#include <conio.h>
#include "zombies/Zombie.h"
#include "plants/PeaShooter.h"
#include "zombies/NormalZombie.h"
#include "zombies/RoadblockZombie.h"
#include <windows.h>

using namespace std;
System::System():sunrays(0),scores(0),shop(*this),zombieGenerator(*this)
{
}

void System::mainLoop()
{
	//////////////////////////////����̨���ع��
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_CURSOR_INFO CursorInfo;
	//GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	//CursorInfo.bVisible = false; //���ؿ���̨���
	//SetConsoleCursorInfo(handle, &CursorInfo);
	//////////////////////////////
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
		Sleep(200);
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 'q') {
				cout << "Bye" << endl;
				return;
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
	for (Placeable* p : list<Placeable*>(items))
		p->update();
	for (Seed* p : list<Seed*>(seeds)) {
		p->update();
	}
	yard.update();
	yard.display();
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
