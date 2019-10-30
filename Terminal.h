/*
��Windows API��װ��һ���ն˲������ࡣ
��������ļ�����ֹ�����ļ�����Windows.h!!
�������������ڼ䣬��ȡ����ģʽ��
*/
#pragma once
#include <Windows.h>
#include <iostream>

enum ControlKey {
	Invalid,
	BuyPlant,//b
	RemovePlant,//c
	GiveUp,//x
	Quit,//q
	KeyUp,
	KeyDown,
	KeyLeft,
	KeyRight,
	KeyEnter,
};

class Terminal
{
	static Terminal* instance;
	HANDLE hout;  //��׼������
	COORD coord;  //��Ļ����
	CONSOLE_SCREEN_BUFFER_INFO csbi;  //��ȡ��Ϣ
	CONSOLE_CURSOR_INFO cci;
	static const int YardStartRow = 0;  //ͥԺ��ʼ��
	int sunrayCol, splitCol;//�̵��е�λ��
	COORD scorePos, timePos, statusPos, sunrayPos;
	//���캯����private
	Terminal();
public:
	static Terminal* getInstance();
	int getCurrentCol();
	int getCurrentRow();
	void setCursorVisible();
	void setCursorVisible(bool v);
	void setCursorPos(const COORD& c);
	void locateToCol(int col);
	void locateToRow(int row);//��λ��ͥԺ��ָ����
	void locateToPixelRow(int rowpix);//��λ��ȷ������
	void locateToBlock(int row, int col);
	int getTimeRow()const;  //��λ����ʾʱ�������
	void locateToPlant(int index);
	void locateToTimeStamp();
	inline void setScorePos(int r, int c) {
		scorePos.X = c;
		scorePos.Y = r;
	}
	void locateToScorePos();
	void markSunrayPos();
	inline int getSunrayCol()const {
		return sunrayCol;
	}
	inline void setSplitCol(int c) {
		splitCol = c;
	}
	inline int getSplitCol()const {
		return splitCol;
	}
	void setTimePos(int r, int c);

	//��λ�����µĺ���
	void updateTimeStamp();
	void updateSunray(int s);
	void clearStatus();
	void showStatus(const std::string& msg);
	ControlKey getKey();
};

