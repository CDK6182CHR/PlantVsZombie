#pragma once

#include "../Placeable.h"

class Yard;

class Plant:
	public Placeable
{
protected:
	int hp;//����ֵ��ÿ����������һ��static������ֵ����ʼ��ʱ�Զ��Ž�ȥ��
public:
	Plant(System& sys);
	void place();//����
	void remove();//��Yard��ɾ����������ɾ������
	virtual inline bool eatable() { return true; }//�ش̲��ܱ���, �����Ļ����϶���true
	void eaten(int dh);//����ʱ���á��������eatable��ִ���κβ�����
	void setBlock(int row, int col); //��ֲ����˵��ʵ�����ھ�����У����õ�ָ�����оͿ����ˡ�
	virtual inline bool available()const = 0;//������ȴʱ�䣬���Թ���
	virtual inline std::string getStatus()const = 0;
	virtual inline std::string toString()const = 0;//Լ��������һ����
};

