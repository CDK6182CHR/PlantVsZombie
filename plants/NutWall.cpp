#include "NutWall.h"

NutWall::NutWall(System& system):Plant(system)
{
	hp = initHp();
}
