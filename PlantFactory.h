#pragma once
#include "plants/Plant.h"
#include "plants/PeaShooter.h"
#include <string>

class System;

class AbstractPlantFactory
{
protected:
	System& system;
	const int coldPeriod, cost;
	const std::string name;
	int nextAvailableTime;
public:
	AbstractPlantFactory(System& sys, int cold, int cost,const std::string& n);
	inline bool available()const {
		return Placeable::timestamp >= nextAvailableTime;
	}
	//装填完成比例，整数
	inline int getRate()const {
		return 100-(nextAvailableTime - Placeable::timestamp) * 100.0 / coldPeriod;
	}
	inline const std::string& getName()const {
		return name;
	}
	inline int getCost()const {
		return cost;
	}
	std::string getStatus()const;
	std::string toString()const;
	virtual Plant* newInstance() = 0;
};

template <typename T>
class PlantFactory :
	public AbstractPlantFactory
{
public:
	PlantFactory(System& sys,int coldPeriod,int cst, const std::string& name);
	virtual T* newInstance()override;
};

template<typename T>
inline PlantFactory<T>::PlantFactory(System& sys,int coldPeriod,int cst, const std::string& name):
	AbstractPlantFactory(sys,coldPeriod,cst,name)
{
}

template<typename T>
inline T* PlantFactory<T>::newInstance()
{
	nextAvailableTime = Placeable::timestamp + coldPeriod;
	return new T(system);
}
