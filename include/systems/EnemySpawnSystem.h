#ifndef STARWARRIOR_ENEMYSPAWNSYSTEM_H
#define STARWARRIOR_ENEMYSPAWNSYSTEM_H

#include "hecate/ComponentMapper.h"
#include "hecate/IntervalEntitySystem.h"

namespace StarWarrior {

class Transform;
class Weapon;

class EnemySpawnSystem : public hecate::IntervalEntitySystem {
public:
	EnemySpawnSystem(int interval, int width);
	void initialize();

protected:
	void processEntities(const hecate::entitySet_t &entities);

private:
	hecate::ComponentMapper<Transform> transformMapper;
	hecate::ComponentMapper<Weapon> weaponMapper;
	long now;
	int width;
};

}

#endif
