#include "IceShooter.h"
#include "IcePeaSeed.h"

IceShooter::IceShooter(System& system):PeaShooter(system)
{
}

void IceShooter::shoot()
{
	(new IcePeaSeed(system, *this))->place();
}
