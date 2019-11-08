#pragma once
#include "NormalZombie.h"
#include "protectors.h"

template <typename BaseZombie,typename Protector>
class ProtectedZombie:
	public BaseZombie 
{
	Protector protector;
public:
	ProtectedZombie(System& system);
	virtual std::string toString()const override;
	virtual std::string getStatus()const override;
	virtual inline int score()const override {
		return BaseZombie::score() + protector.score();
	}
	virtual void attacked(int dh)override;
};

template<typename BaseZombie, typename Protector>
inline ProtectedZombie<BaseZombie, Protector>::ProtectedZombie(System& system):
	BaseZombie(system)
{
}

template<typename BaseZombie, typename Protector>
inline std::string ProtectedZombie<BaseZombie, Protector>::toString() const
{
	if (protector.isActive()) {
		return protector.toString() + BaseZombie::toString();
	}
	else
		return BaseZombie::toString();
}

template<typename BaseZombie, typename Protector>
inline std::string ProtectedZombie<BaseZombie, Protector>::getStatus() const
{
	if (protector.isActive()) {
		int total = BaseZombie::initHp() + protector.initValue();
		int current = BaseZombie::hp + protector.getValue();
		int rate = int(100.0 * current / total);
		char buffer[100];
		sprintf_s(buffer,100, "(%d%%)", rate);
		return std::string(buffer);
	}
	else
		return BaseZombie::getStatus();
}

template<typename BaseZombie, typename Protector>
inline void ProtectedZombie<BaseZombie, Protector>::attacked(int dh)
{
	if (protector.isActive())
		protector.attacked(dh);
	else
		BaseZombie::attacked(dh);
}
