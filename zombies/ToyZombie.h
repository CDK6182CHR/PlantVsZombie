#pragma once
#include "NormalZombie.h"
class ToyZombie :
	public NormalZombie
{
protected:
	virtual inline int speed()const override { return -2; }
	virtual inline int initHp()const override { return 20; }
public:
	ToyZombie(System& system);
	virtual inline std::string toString()const override { return "��ż�н�ʬ"; }
	virtual void update()override;  //���˱�ը���̳С�
	virtual inline int score()const override { return 3; }
private:
	void explode();
	int rate()const;//���ر�ը�����Եİٷ�����
};

