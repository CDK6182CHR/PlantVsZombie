#pragma once
#include <string>

class AbstractProtector {
protected:
	int value;
public:
	AbstractProtector();
	virtual inline int initValue()const = 0;
	virtual inline std::string toString()const = 0;
	virtual inline int score()const = 0;
	void attacked(int dv);//dv>0����
	inline bool isActive()const {
		return value > 0;
	}
	inline int getValue()const {
		return value; 
	}
};

class RoadBlock :public AbstractProtector {
public:
	RoadBlock();
	virtual inline int initValue()const override { return 10; }
	virtual inline std::string toString()const override { return "·��"; }
	virtual inline int score()const override { return 1; }
};

class Bucket :public AbstractProtector {
public:
	Bucket();
	virtual inline int initValue()const override { return 30; }
	virtual inline std::string toString()const override { return "��Ͱ"; }
	virtual inline int score()const override { return 3; }
};

class Door :public AbstractProtector {
public:
	Door();
	virtual inline int initValue()const override { return 40; }
	virtual inline std::string toString()const override { return "�Ű�"; }
	virtual inline int score()const override { return 4; }
};