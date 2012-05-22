#ifndef STARWARRIOR_ENEMYSHIPMOVEMENTSYSTEM_H
#define STARWARRIOR_ENEMYSHIPMOVEMENTSYSTEM_H

#include "hecate/ComponentMapper.h"
#include "hecate/Entity.h"
#include "hecate/EntityProcessingSystem.h"

namespace StarWarrior {

class Enemy;
class Transform;
class Velocity;

class EnemyShipMovementSystem : public hecate::EntityProcessingSystem {
public:
	EnemyShipMovementSystem(int width);
	virtual ~EnemyShipMovementSystem();
	virtual void initialize();

protected:
	virtual void process(hecate::Entity *e);

private:
	hecate::ComponentMapper<Transform> *transformMapper;
	hecate::ComponentMapper<Velocity> *velocityMapper;

	Enemy *e;
	Transform *t;
	Velocity *v;

	int width;
};

}

#endif
