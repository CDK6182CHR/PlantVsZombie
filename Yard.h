/*
����ͥԺ������block�ļ��ϡ�
*/
#pragma once
#include "Block.h"
#include <sstream>
#include <list>

#define ROWS 5
#define COLS 8
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
	bool selectBlock(int& row, int& col);  //�û�������ѡ��ؿ顣�����Ƿ�ȷ����
	Block* upperNeighbor(Block* b);
	Block* downNeighbor(Block* b);
	std::list<Block*> neighborBlocks(Block* b);
private:
	void printHLine();
	int blockWiseRow(int pixelWiseRow)const;
};

