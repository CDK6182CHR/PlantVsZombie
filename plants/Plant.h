#pragma once

#include "../Placeable.h"

class Yard;

class Plant:
	public Placeable
{
protected:
	int hp;//��ǰ����ֵ
	virtual inline int initHp()const = 0;
public:
	Plant(System& sys);
	void place();//����
	void remove();//��Yard��ɾ����������ɾ������
	virtual inline bool eatable()const { return true; }//�ش̲��ܱ���, �����Ļ����϶���true
	void eaten(int dh);//����ʱ���á��������eatable��ִ���κβ�����
	void setBlock(int row, int col); //��ֲ����˵��ʵ�����ھ�����У����õ�ָ�����оͿ����ˡ�
	virtual inline bool hasStatus()const { return true; }
	virtual inline std::string getStatus()const;
	virtual inline std::string toString()const = 0;//Լ��������һ����
};

