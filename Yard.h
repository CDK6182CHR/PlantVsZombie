/*
����ͥԺ������block�ļ��ϡ�
*/
#pragma once
#include "Block.h"

#define ROWS 5
#define COLS 7

class Yard
{
	Block blocks[ROWS][COLS];
public:
	void diaplay()const;
	void update();//ʱ���������
};

