#pragma once
#include "plants/Plant.h"
#include "plants/Seed.h"

class System;
class Yard;
class Shop
{
	System& system;
	Yard& yard;
public:
	Shop(System& sys);
	Plant* buy();//�漰������������yard���ֲ��
};

