/*
对Windows API封装成一个终端操作的类。
除了这个文件，禁止其他文件包含Windows.h!!
整个程序运行期间，采取单例模式。
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
	HANDLE hout;  //标准输出句柄
	COORD coord;  //屏幕坐标
	CONSOLE_SCREEN_BUFFER_INFO csbi;  //读取信息
	CONSOLE_CURSOR_INFO cci;
	static const int YardStartRow = 0;  //庭院起始行
	int sunrayCol, splitCol;//商店中的位置
	COORD scorePos, timePos, statusPos, sunrayPos;
	//构造函数是private
	Terminal();
public:
	static Terminal* getInstance();
	int getCurrentCol();
	int getCurrentRow();
	void setCursorVisible();
	void setCursorVisible(bool v);
	void setCursorPos(const COORD& c);
	void locateToCol(int col);
	void locateToRow(int row);//定位到庭院的指定行
	void locateToPixelRow(int rowpix);//定位到确定的行
	void locateToBlock(int row, int col);
	int getTimeRow()const;  //定位到显示时间戳的行
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

	//定位并更新的函数
	void updateTimeStamp();
	void updateSunray(int s);
	void clearStatus();
	void showStatus(const std::string& msg);
	ControlKey getKey();
};

