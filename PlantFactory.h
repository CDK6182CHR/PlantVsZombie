#pragma once
#include "plants/Plant.h"
#include "plants/PeaShooter.h"
#include <string>

class System;

class AbstractPlantFactory
{
protected:
	System& system;
	const int coldPeriod;
	const std::string name;
	int nextAvailableTime;
public:
	AbstractPlantFactory(System& sys, int cold, const std::string& n);
	inline bool available()const {
		return Placeable::timestamp >= nextAvailableTime;
	}
	//装填完成比例，整数
	inline int getRate()const {
		return (nextAvailableTime - Placeable::timestamp) * 100.0 / coldPeriod;
	}
	inline const std::string& getName()const {
		return name;
	}
	std::string getStatus()const;
	std::string toString()const;
	virtual Placeable* newInstance() = 0;
};

template <typename T>
class PlantFactory :
	public AbstractPlantFactory
{
public:
	PlantFactory(System& sys,int coldPeriod, const std::string& name);
	virtual T* newInstance()override;
};

template<typename T>
inline PlantFactory<T>::PlantFactory(System& sys,int coldPeriod, const std::string& name):
	AbstractPlantFactory(sys,coldPeriod,name)
{
}

template<typename T>
inline T* PlantFactory<T>::newInstance()
{
	nextAvailableTime = Placeable::timestamp + coldPeriod;
	return new T(system);
}
