#include "Shop.h"
#include "System.h"
#include "plants/PeaShooter.h"
#include <iostream>
#include <iomanip>
using namespace std;

Shop::Shop(System& sys):
	system(sys),yard(sys.yard),terminal(Terminal::getInstance()),
	factories{
		new PlantFactory<PeaShooter>(sys,20,"�㶹����"),
	}
{
	initUI();
}

Plant* Shop::buy()
{
	return nullptr;
}

Shop::~Shop()
{
	for (int i = 0; i < N; i++)
		delete factories[i];
}

void Shop::initUI()
{
	int totalWidth = COLS * Block::PIXES_PER_COL;
	cout << endl;//��һ������ʱ���
	for (int i = 0; i < totalWidth; i++)
		cout << '=';
	cout << endl;
	cout << "[�̵�]";
	//�÷�15�У��ֽ���1�У���������20��
	for (int i = 0; i < totalWidth - 36; i++)
		cout << ' ';
	cout << "��������: ";
	terminal->setSunrayCol(terminal->getCurrentCol());
	cout << system.getSunray();
	terminal->setSplitCol(totalWidth - 16);
	terminal->locateToCol(terminal->getSplitCol());
	cout << '|';
	cout << setw(16) << setiosflags(ios::left) << "   [�÷�]" << endl;
	for (int i = 0; i < totalWidth; i++)
		cout << '-';
	cout << endl;
	terminal->setScorePos(terminal->getCurrentRow(), totalWidth - 9);
	int rows = N / PlantsPerRow + int(N % PlantsPerRow != 0);
	for (int row = 0; row < rows; row++) {
		for (int i = 0; i < PlantsPerRow; i++) {
			int t = i + row * PlantsPerRow;
			if (t >= N)
				break;
			terminal->locateToPlant(t);
			cout << setw(LengthPerPlant) << ' ';
			terminal->locateToPlant(t);
			cout << factories[t]->getName();
			if (factories[t]->available())
				cout << "����ռλ��";
			else
				cout << factories[t]->getStatus();
		}
		terminal->locateToCol(terminal->getSplitCol());
		cout << '|';
	}
	terminal->locateToPixelRow(ROWS * Block::PIXES_PER_ROW + rows + 5);
	for (int i = 0; i < totalWidth; i++)
		cout << '=';
	terminal->locateToScorePos();
	cout << system.getScore();
}
