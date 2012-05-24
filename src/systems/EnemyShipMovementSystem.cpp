#include "systems/EnemyShipMovementSystem.h"

#include "components/Enemy.h"
#include "components/Transform.h"
#include "components/Velocity.h"

using namespace hecate;

namespace StarWarrior {

EnemyShipMovementSystem::EnemyShipMovementSystem(int width) {
	Enemy e;
	Transform t;
	Velocity v;
	componentList_t l;

	l.push_back(&e);
	l.push_back(&v);
	setupRequiredTypes(&t, l);

	this->width = width;
}

EnemyShipMovementSystem::~EnemyShipMovementSystem() {
	delete transformMapper;
	delete velocityMapper;
}

void EnemyShipMovementSystem::initialize() {
	transformMapper = new ComponentMapper<Transform>(Transform(), world);
	velocityMapper = new ComponentMapper<Velocity>(Velocity(), world);
}

void EnemyShipMovementSystem::process(Entity *e) {
	Transform *transform = transformMapper->get(*e);
	Velocity *velocity = velocityMapper->get(*e);

	if((transform->getX() > width || transform->getX() < 0) && velocity) {
		velocity->addAngle(180);
	}
}

}
