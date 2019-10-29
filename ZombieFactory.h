#pragma once
#include "Placeable.h"

class System;
class AbstractZombieFactory
{
protected:
	System& system;
public:
	AbstractZombieFactory(System& sys);
	virtual Placeable* newInstance() = 0;
	virtual inline int getWeight()const = 0;
	virtual inline bool available()const = 0;
};

template <typename T>
class ZombieFactory :
	public AbstractZombieFactory
{
	int weight; //随机产生时候的权重，只对僵尸有效
	int availableTime;//可以开始产生的时间戳，只对僵尸有效
public:
	ZombieFactory(System& sys,int w=0,int tm=0);
	virtual T* newInstance()override;
	virtual inline int getWeight()const override {
		return weight; 
	}
	virtual inline bool available()const override {
		return Placeable::timestamp >= availableTime; 
	}
};

template<typename T>
inline ZombieFactory<T>::ZombieFactory(System& sys,int w,int tm):
	AbstractZombieFactory(sys),weight(w),availableTime(tm)
{
}

template<typename T>
inline T* ZombieFactory<T>::newInstance()
{
	return new T(system);
}
