#include "systems/CollisionSystem.h"

#include "components/Health.h"
#include "components/Transform.h"
#include "components/Velocity.h"

namespace StarWarrior {

using namespace hecate;

CollisionSystem::CollisionSystem() {
}

void CollisionSystem::initialize() {
	Transform t;
	Velocity v;
	Health h(100);

	transformMapper = new ComponentMapper<Transform>(&t, world);
	velocityMapper = new ComponentMapper<Velocity>(&v, world);
	healthMapper = new ComponentMapper<Health>(&h, world);
}

void CollisionSystem::processEntities(std::set<hecate::Entity *> entities) {
}

bool CollisionSystem::checkProcessing() {
	return true;
}

bool CollisionSystem::collisionExists(hecate::Entity *e1, hecate::Entity *e2) {
	Transform *t1 = transformMapper->get(*e1);
	Transform *t2 = transformMapper->get(*e2);

	return t1->getDistanceTo(*t2) < 15;
}

}
