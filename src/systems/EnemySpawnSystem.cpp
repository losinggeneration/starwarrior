#include "systems/EnemySpawnSystem.h"

#include "EntityFactory.h"
#include "components/Enemy.h"
#include "components/Transform.h"
#include "components/Velocity.h"
#include "components/Weapon.h"

#include "hecate/Entity.h"

#include <cstdlib>

using namespace hecate;

namespace StarWarrior {

EnemySpawnSystem::EnemySpawnSystem(int interval, int width) : IntervalEntitySystem(interval) {
	Enemy e;
	Transform t;
	Velocity v;
	componentList_t l;

	l.push_back(&t);
	l.push_back(&e);
	l.push_back(&v);
	setupTypes(l);

	this->width = width;
	now = 0;
}

EnemySpawnSystem::~EnemySpawnSystem() {
	delete transformMapper;
	delete weaponMapper;
}

void EnemySpawnSystem::initialize() {
	transformMapper = new ComponentMapper<Transform>(Transform(), world);
	weaponMapper = new ComponentMapper<Weapon>(Weapon(), world);
}

void EnemySpawnSystem::processEntities(const entitySet_t &entities) {
	if(entities.size() < 20) {
		Entity *e = EntityFactory::createEnemyShip(world);

		e->getComponent(Transform())->setLocation(rand()%width, rand()%400+50);
		e->getComponent(Velocity())->setVelocity(0.05f);
		e->getComponent(Velocity())->setAngle((rand()%2) ? 0 : 180);

		e->refresh();
	}
}

}
