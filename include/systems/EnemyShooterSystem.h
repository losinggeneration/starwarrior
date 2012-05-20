#ifndef STARWARRIOR_ENEMYSHOOTERSYSTEM_H
#define STARWARRIOR_ENEMYSHOOTERSYSTEM_H

#include "SDL.h"

#include "hecate/ComponentMapper.h"
#include "hecate/EntityProcessingSystem.h"

namespace hecate {

class Entity;

}

namespace StarWarrior {

class Transform;
class Weapon;

class EnemyShooterSystem : public hecate::EntityProcessingSystem {
public:
	EnemyShooterSystem();
	void initialize();

protected:
	void begin();
	void process(hecate::Entity *e);

private:
	hecate::ComponentMapper<Transform> transformMapper;
	hecate::ComponentMapper<Weapon> weaponMapper;
	Uint32 now;
};

}

#endif
