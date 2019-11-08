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
	virtual inline std::string toString()const override { return "玩偶盒僵尸"; }
	virtual void update()override;  //除了爆炸都继承。
	virtual inline int score()const override { return 3; }
private:
	void explode();
	int rate()const;//返回爆炸可能性的百分数。
};

