#include "VaultZombie.h"
#include "../System.h"
VaultZombie::VaultZombie(System& system):NormalZombie(system),hasPole(true)
{
	hp = initHp();
}

std::string VaultZombie::getStatus() const
{
	if (hasPole)
		return "сп╦к";
	else
		return NormalZombie::getStatus();
}

void VaultZombie::update()
{
	if (!active)
		return;
	Block* block = position.target();
	Plant* plant = block->currentPlant();
	if (hasPole && plant != nullptr) {
		if (block->getCol() == 0)
			system.gameOver(this);
		else {
			move(-Block::PIXES_PER_COL);
			hasPole = false;
		}
	}
	else{
		NormalZombie::update();
	}
}
