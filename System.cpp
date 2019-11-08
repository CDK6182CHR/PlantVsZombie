#include "System.h"
#include <iostream>
#include <conio.h>
#include "zombies/Zombie.h"
#include "plants/PeaShooter.h"

using namespace std;
System::System():
	sunrays(100),scores(0),shop(*this),zombieGenerator(*this),
	terminal(Terminal::getInstance())
{
}

void System::mainLoop()
{
	//PeaShooter* ps1 = new PeaShooter(*this), * ps2 = new PeaShooter(*this);
	//ps1->setBlock(1, 0);
	//ps1->place();
	//ps2->setBlock(1, 5);
	//ps2->place();
	//NormalZombie* nz = new NormalZombie(*this);
	//nz->setPosition(1, 56);
	//nz->place();
	//RoadblockZombie* rbz = new RoadblockZombie(*this);
	//rbz->setPosition(1, 45);
	//rbz->place();
	///////////真正的主循环从这开始////////////
	while (true) {
		Sleep(250);
		if (_kbhit()) {
			ControlKey k = terminal->getKey();
			switch (k)
			{
			case Quit:if(quit()) return;
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
	//这些update过程中对象可能会被删掉
	Placeable::timestamp++;
	zombieGenerator.generate();
	if (Placeable::timestamp % SunrayInterval == 1)
		addSunray(SunrayUnit);
	//前面的东西可能会把后面的搞死，不能简单地复制循环
	for (Placeable* p : list<Placeable*>(items))
		p->update();
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

void System::gameOver(Zombie* winner)
{
	system("cls");
	string s = "**********************************\n"\
		"*       僵尸吃掉了你的脑子！     *\n"\
		"**********************************";
	cout << s << endl;
	cout << "生存时间：" << Placeable::timestamp << endl;
	cout << "游戏得分：" << scores << endl;
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
	terminal->showStatus("铲子：按方向键选择地块，ENTER确认，x取消");
	terminal->setCursorVisible(true);
	terminal->locateToBlock(0, 0);
	int row = 0, col = 0;
	bool flag = yard.selectBlock(row, col);
	if (flag) {
		//表示确认删除
		Block* block = yard.blockAt(row, col);
		Plant* plant = block->currentPlant();
		if (plant == nullptr) {
			terminal->showStatus("该位置没有植物！");
		}
		plant->remove();
	}
	terminal->clearStatus();
}

/*
用户交互，返回是否真的要退出。
*/
bool System::quit()
{
	terminal->showStatus("按ENTER确认退出，其他任意键取消");
	if (terminal->getKey() == ControlKey::KeyEnter) {
		//显示结束提示
		string s = "*****************************\n"\
			"*         退出游戏          *\n"\
			"*****************************\n";
		system("cls");
		cout << s;
		cout << "游戏时长：" << Placeable::timestamp << endl;
		cout << "游戏得分：" << scores << endl;
		return true;
	}
	terminal->clearStatus();
	return false;
}
