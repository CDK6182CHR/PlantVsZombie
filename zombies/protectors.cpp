#include "protectors.h"

AbstractProtector::AbstractProtector():value(0)
{
}

void AbstractProtector::attacked(int dv)
{
	value -= dv;
}

RoadBlock::RoadBlock()
{
	value = initValue();
}

Bucket::Bucket()
{
	value = initValue();
}

Door::Door()
{
	value = initValue();
}

CR200J::CR200J()
{
	value = initValue();
}
