#pragma once
#include "Placeable.h"

class System;
class AbstractFactory
{
protected:
	System& system;
public:
	AbstractFactory(System& sys);
	virtual Placeable* newInstance() = 0;
	virtual inline int getWeight()const = 0;
	virtual inline bool available()const = 0;
};

template <typename T>
class Factory :
	public AbstractFactory
{
	int weight; //随机产生时候的权重，只对僵尸有效
	int availableTime;//可以开始产生的时间戳，只对僵尸有效
public:
	Factory(System& sys,int w=0,int tm=0);
	virtual T* newInstance()override;
	virtual inline int getWeight()const override {
		return weight; 
	}
	virtual inline bool available()const override {
		return Placeable::timestamp >= availableTime; 
	}
};

template<typename T>
inline Factory<T>::Factory(System& sys,int w,int tm):
	AbstractFactory(sys),weight(w),availableTime(tm)
{
}

template<typename T>
inline T* Factory<T>::newInstance()
{
	return new T(system);
}
