#include "PlantFactory.h"
using namespace std;

AbstractPlantFactory::AbstractPlantFactory(System& sys,int cold, const std::string& n):
	system(sys),coldPeriod(cold),name(n),nextAvailableTime(Placeable::timestamp)
{
}

std::string AbstractPlantFactory::getStatus() const
{
	char buffer[100];
	sprintf_s(buffer, 100, "(%d%%)", getRate());
	return std::string(buffer);
}

