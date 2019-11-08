#include "Shop.h"
#include "System.h"
#include "plants/plants.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

Shop::Shop(System& sys) :
	system(sys), yard(sys.yard), terminal(Terminal::getInstance()),
	factories{
		new PlantFactory<Sunflower>(sys,5,50,"向日葵"),
		new PlantFactory<PeaShooter>(sys,5,100,"豌豆射手"),
		new PlantFactory<IceShooter>(sys,10,175,"寒冰射手"),
		new PlantFactory<DoubleShooter>(sys,10,200,"双发射手"),
		new PlantFactory<WatermelonThrower>(sys,20,300,"西瓜投手"),
		new PlantFactory<NutWall>(sys,40,50,"坚果墙"),
		new PlantFactory<Thorn>(sys,20,100,"地刺"),
		new PlantFactory<PotatoMine>(sys,50,25,"土豆雷"),
		new PlantFactory<SpicyPepper>(sys,50,300,"火爆辣椒"),
		new PlantFactory<CherryBomb>(sys,50,300,"樱桃炸弹"),
	}
{
	initUI();
}

void Shop::buy()
{
	terminal->setCursorVisible(true);
	plantChanged(0);
	int curIndex = 0;
	while (true) {
		if (_kbhit()) {
			if (keyPressed(terminal->getKey(), curIndex))
				break;
		}
	}
	terminal->setCursorVisible(false);
	terminal->clearStatus();
}

Shop::~Shop()
{
	for (int i = 0; i < N; i++)
		delete factories[i];
}

void Shop::updateUI()
{
	terminal->locateToScorePos();
	cout << system.getScore();
	terminal->updateSunray(system.getSunray());
	//更新每种植物的状态
	for (int i = 0; i < N; i++) {
		AbstractPlantFactory* apf = factories[i];
		//terminal->locateToPlant(i);
		//cout << setw(LengthPerPlant) << ' ';
		terminal->locateToPlant(i);
		cout << apf->getName();
		if (apf->available())
			cout << "  " <<setw(3)<< apf->getCost();
		else
			cout << " " <<setw(3)<< apf->getRate() << "%";
	}
	terminal->setCursorVisible(false);
}

void Shop::initUI()
{
	int totalWidth = COLS * Block::PIXES_PER_COL;
	cout << endl;//第一行留给时间戳
	for (int i = 0; i < totalWidth; i++)
		cout << '=';
	cout << endl;
	cout << "[商店]";
	//得分15列，分界线1列，阳光总数20列
	for (int i = 0; i < totalWidth - 36; i++)
		cout << ' ';
	cout << "阳光总数: ";
	terminal->markSunrayPos();
	cout << system.getSunray();
	terminal->setSplitCol(totalWidth - 16);
	terminal->locateToCol(terminal->getSplitCol());
	cout << '|';
	cout << setw(16) << setiosflags(ios::left) << "   [得分]" << endl;
	for (int i = 0; i < totalWidth; i++)
		cout << '-';
	cout << endl;
	terminal->setScorePos(terminal->getCurrentRow(), totalWidth - 9);
	int rows = (N - 1) / PlantsPerRow + 1;
	for (int row = 0; row < rows; row++) {
		for (int i = 0; i < PlantsPerRow; i++) {
			int t = i + row * PlantsPerRow;
			if (t >= N)
				break;
			terminal->locateToPlant(t);
			cout << factories[t]->getName();
			if (factories[t]->available())
				cout << ' ' << factories[t]->getCost();
			else
				cout << factories[t]->getStatus();
		}
		terminal->locateToCol(terminal->getSplitCol());
		cout << '|';
		cout << endl;
	}
	terminal->locateToPixelRow(ROWS * Block::PIXES_PER_ROW + rows + 5);
	for (int i = 0; i < totalWidth; i++)
		cout << '=';
	terminal->locateToScorePos();
	cout << system.getScore();
}

void Shop::plantChanged(int i)
{
	terminal->showStatus(string("按方向键选择，回车键确认。当前：") +
		factories[i]->getName());
	terminal->locateToPlant(i);
}

bool Shop::keyPressed(ControlKey key, int& curIndex)
{
	switch (key) {
	case KeyDown: {
		curIndex += PlantsPerRow;
		if (curIndex >= N)
			curIndex = N - 1;
		plantChanged(curIndex);
		break;
	}
	case KeyUp: {
		if (curIndex >= PlantsPerRow) {
			curIndex -= PlantsPerRow;
			plantChanged(curIndex);
		}
		break;
	}
	case KeyLeft: {
		if (curIndex % PlantsPerRow != 0) {
			curIndex -= 1;
			plantChanged(curIndex);
		}
		break;
	}
	case KeyRight: {
		if (curIndex % PlantsPerRow != PlantsPerRow - 1) {
			curIndex += 1;
			if (curIndex >= N)
				curIndex = N - 1;
			plantChanged(curIndex);
		}
		break;
	}
	case KeyEnter: {
		AbstractPlantFactory* apf = factories[curIndex];
		return (addNewPlant(apf));
	}
	case GiveUp:return true;
	}
	return false;
}

bool Shop::addNewPlant(AbstractPlantFactory* factory)
{
	if (!factory->available()) {
		terminal->showStatus(factory->getName() + "尚未装载完成! ");
		return false;
	}
	else if (factory->getCost() > system.getSunray()) {
		terminal->showStatus("对不起，阳光不足！");
		return false;
	}
	terminal->showStatus(
		string("选中") + factory->getName() + ",方向键选择，x取消，ENTER确认");
	int curRow = 0, curCol = 0;
	bool flag = yard.selectBlock(curRow, curCol);
	if (flag) {//确认选择
		Block* block = yard.blockAt(curRow,curCol);
		Plant* p = block->currentPlant();
		if (p != nullptr) {
			terminal->showStatus("该位置已有植物，不可种植！");
			return false;
		}
		else {
			p = (Plant*)factory->newInstance();
			system.useSunray(factory->getCost());
			p->setBlock(curRow, curCol);
			p->place();
			return true;
		}
	}
	return false;
}
