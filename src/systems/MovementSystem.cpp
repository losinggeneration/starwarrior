#include "systems/MovementSystem.h"

#include "components/Transform.h"
#include "components/Velocity.h"

#include <cmath>

using namespace hecate;

namespace StarWarrior {

MovementSystem::MovementSystem() {
	Transform t;
	Velocity v;
	componentList_t l;
	l.push_back(&t);
	l.push_back(&v);
	setupTypes(l);
}

MovementSystem::~MovementSystem() {
	delete transformMapper;
	delete velocityMapper;
}

void MovementSystem::initialize() {
	transformMapper = new ComponentMapper<Transform>(Transform(), world);
	velocityMapper = new ComponentMapper<Velocity>(Velocity(), world);
}

void MovementSystem::process(Entity *e) {
	Velocity *velocity = velocityMapper->get(*e);
	if(velocity) {
		float r = velocity->getAngleAsRadians();
		float v = velocity->getVelocity();


		Transform *transform = transformMapper->get(*e);

		if(transform) {
			float xn = transform->getX() + (cos(r) * v * world->getDelta());
			float yn = transform->getY() + (sin(r) * v * world->getDelta());

			transform->setLocation(xn, yn);
		}
	}
}

}
