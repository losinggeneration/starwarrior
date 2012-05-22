#ifndef STARWARRIOR_COLLISIONSYSTEM_H
#define STARWARRIOR_COLLISIONSYSTEM_H

#include "hecate/ComponentMapper.h"
#include "hecate/EntitySystem.h"

namespace StarWarrior {

class Health;
class Transform;
class Velocity;

class CollisionSystem : public hecate::EntitySystem {
public:
	CollisionSystem();
	virtual ~CollisionSystem();
	virtual void initialize();

protected:
	virtual void processEntities(const hecate::entitySet_t &entities);
	virtual bool checkProcessing();

private:
	bool collisionExists(hecate::Entity *e1, hecate::Entity *e2);

	hecate::ComponentMapper<Transform> *transformMapper;
	hecate::ComponentMapper<Velocity> *velocityMapper;
	hecate::ComponentMapper<Health> *healthMapper;
};

}

#endif
