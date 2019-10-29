/*
����ͥԺ������block�ļ��ϡ�
*/
#pragma once
#include "Block.h"
#include <sstream>


#define ROWS 5
#define COLS 7

class Yard
{
	Block blocks[ROWS][COLS];
public:
	Yard();
	void display();
	void update();//ʱ���������������ֲ�ｩʬ����֮�����
	Block* blockAt(int row, int col);
	std::stringstream sout;
private:
	void printHLine();
	int blockWiseRow(int pixelWiseRow)const;
};

