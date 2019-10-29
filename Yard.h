/*
����ͥԺ������block�ļ��ϡ�
*/
#pragma once
#include "Block.h"
#include <sstream>


#define ROWS 5
#define COLS 7
class Terminal;

class Yard
{
	Block blocks[ROWS][COLS];
	Terminal* terminal;
public:
	Yard();
	void updateUI();
	void update();//ʱ���������������ֲ�ｩʬ����֮�����
	Block* blockAt(int row, int col);
	std::stringstream sout;
private:
	void printHLine();
	int blockWiseRow(int pixelWiseRow)const;
};

