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
};

