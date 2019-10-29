#pragma once
#include "Placeable.h"

class System;
class AbstractFactory
{
	System& system;
public:
	AbstractFactory(System& sys);
	virtual Placeable* newInstance() = 0;
};

template <typename T>
class Factory :
	public AbstractFactory
{
public:
	Factory(System& sys);
	virtual T* newInstance()override;
};

template<typename T>
inline Factory<T>::Factory(System& sys):AbstractFactory(sys)
{
}

template<typename T>
inline T* Factory<T>::newInstance()
{
	return new T(system);
}
