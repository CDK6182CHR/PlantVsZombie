/*
联系场地对象与yard的桥梁。
*/
#pragma once

class Yard;
class Block;
class Position
{
	Yard& yard;
	int row, colpix; //行方向上精确到具体的列，用pix-像素以示区别。
public:
	Position(Yard& yd);
	Block* target();
	void move(int dcol, int drow = 0);//移动位置，以像素为单位
	void setRow(int r);
	void setColpix(int c);
	void setPos(int row, int colpix);
	void setBlock(int row, int col);//设置格子为单位的行列，col数据指向最左的列。
	inline int getRow()const { return row; }
	inline int getColpix()const { return colpix; }
};

