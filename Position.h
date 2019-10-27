/*
��ϵ���ض�����yard��������
*/
#pragma once

class Yard;
class Block;
class Position
{
	Yard& yard;
	int row, colpix; //�з����Ͼ�ȷ��������У���pix-������ʾ����
public:
	Position(Yard& yd);
	Block* target();
	void move(int dcol, int drow = 0);//�ƶ�λ�ã�������Ϊ��λ
	void setRow(int r);
	void setColpix(int c);
	void setPos(int row, int colpix);
	void setBlock(int row, int col);//���ø���Ϊ��λ�����У�col����ָ��������С�
	inline int getRow()const { return row; }
	inline int getColpix()const { return colpix; }
};

