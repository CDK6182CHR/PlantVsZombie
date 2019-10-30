#pragma once
#include "plants/Plant.h"
#include "plants/Seed.h"
#include "Terminal.h"
#include "PlantFactory.h"

class System;
class Yard;
class Shop
{
	System& system;
	Terminal* terminal;
	Yard& yard;
	const static int LengthPerPlant = 40,//�̵���ÿ��ֲ��ĳ��ȣ��ַ�
		PlantsPerRow = 2, //ÿ����ʾ����ֲ��
		N = 1; //һ��������ֲ��
	AbstractPlantFactory* factories[N];
public:
	Shop(System& sys);
	void buy();//�漰������������yard���ֲ��
	~Shop();
	void updateUI();
	friend class Terminal;
private:
	void initUI();
	void plantChanged(int i);//�ı�ѡ���ֲ���ʾ��Ϣ��
	bool keyPressed(ControlKey key,int& curIndex); // ����true��ʾ�˳�����
	bool addNewPlant(AbstractPlantFactory* factory);  //�����Ƿ�Ҫ�˳�
};

