#include "systems/CollisionSystem.h"

#include "components/Health.h"
#include "components/Transform.h"
#include "components/Velocity.h"

#include "EntityFactory.h"

#include "hecate/Entity.h"
#include "hecate/GroupManager.h"

namespace StarWarrior {

using namespace hecate;

CollisionSystem::CollisionSystem() {
	Transform t;
	componentList_t l;
	l.push_back(&t);
	setupTypes(l);
}

CollisionSystem::~CollisionSystem() {
	delete healthMapper;
	delete transformMapper;
	delete velocityMapper;
}

void CollisionSystem::initialize() {
	transformMapper = new ComponentMapper<Transform>(Transform(), world);
	velocityMapper = new ComponentMapper<Velocity>(Velocity(), world);
	healthMapper = new ComponentMapper<Health>(Health(), world);
}

void CollisionSystem::processEntities(const entitySet_t &entities) {
	entitySet_t bullets = world->getGroupManager()->getEntities("BULLETS");
	entitySet_t ships = world->getGroupManager()->getEntities("SHIPS");

	if(!bullets.empty() && !ships.empty()) {
		for(entitySet_t::iterator it = ships.begin(); it != ships.end(); it++) {
			Entity *ship = *it;

			for(entitySet_t::iterator bt = bullets.begin(); bt != bullets.end(); bt++) {
				Entity *bullet = *bt;

				if(collisionExists(bullet, ship)) {
					Transform *tb = transformMapper->get(*bullet);
					EntityFactory::createBulletExplosion(world, tb->getX(), tb->getY())->refresh();
					world->deleteEntity(bullet);

					Health *health = healthMapper->get(*ship);
					health->addDamage(4);

					if(!health->isAlive()) {
						Transform *ts = transformMapper->get(*ship);

						EntityFactory::createShipExplosion(world, ts->getX(), ts->getY())->refresh();

						world->deleteEntity(ship);
						//  break from the inner loop
						break;
					}
				}
			}
		}
	}
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
