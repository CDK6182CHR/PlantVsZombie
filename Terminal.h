/*
��Windows API��װ��һ���ն˲������ࡣ
��������ļ�����ֹ�����ļ�����Windows.h!!
�������������ڼ䣬��ȡ����ģʽ��
*/
#pragma once
#include <Windows.h>
#include <iostream>

class Terminal
{
	static Terminal* instance;
	HANDLE hout;  //��׼������
	COORD coord;  //��Ļ����
	CONSOLE_SCREEN_BUFFER_INFO csbi;  //��ȡ��Ϣ
	static const int YardStartRow = 0;  //ͥԺ��ʼ��
	int sunrayCol, splitCol;//�̵��е�λ��
	COORD scorePos;
	//���캯����private
	Terminal();
public:
	static Terminal* getInstance();
	int getCurrentCol();
	int getCurrentRow();
	void locateToCol(int col);
	void locateToRow(int row);//��λ��ͥԺ��ָ����
	void locateToPixelRow(int rowpix);//��λ��ȷ������
	void locateToTimeRow();  //��λ����ʾʱ�������
	void locateToPlant(int index);
	inline void setScorePos(int r, int c) {
		scorePos.X = c;
		scorePos.Y = r;
	}
	void locateToScorePos();
	inline void setSunrayCol(int c) {
		sunrayCol = c;
	}
	inline int getSunrayCol()const {
		return sunrayCol;
	}
	inline void setSplitCol(int c) {
		splitCol = c;
	}
	inline int getSplitCol()const {
		return splitCol;
	}
};

