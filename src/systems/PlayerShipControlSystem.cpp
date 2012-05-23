#include "systems/PlayerShipControlSystem.h"

#include "EntityFactory.h"
#include "components/Player.h"
#include "components/Transform.h"
#include "components/Velocity.h"

#include "hecate/Entity.h"

using namespace hecate;

namespace StarWarrior {

PlayerShipControlSystem::PlayerShipControlSystem() : moveLeft(false), moveRight(false), shoot(false) {
	Player p;
	Transform t;
	componentList_t l;
	l.push_back(&t);
	l.push_back(&p);
	setupTypes(l);
}

PlayerShipControlSystem::~PlayerShipControlSystem() {
	delete transformMapper;
}

void PlayerShipControlSystem::initialize() {
	transformMapper = new ComponentMapper<Transform>(Transform(), world);
}

void PlayerShipControlSystem::keyPressed(SDLKey key) {
	if (key == SDLK_a) {
		moveLeft = true;
		moveRight = false;
	} else if (key == SDLK_d) {
		moveRight = true;
		moveLeft = false;
	} else if (key == SDLK_SPACE) {
		shoot = true;
	}
}

void PlayerShipControlSystem::keyReleased(SDLKey key) {
	if (key == SDLK_a) {
		moveLeft = false;
	} else if (key == SDLK_d) {
		moveRight = false;
	} else if (key == SDLK_SPACE) {
		shoot = false;
	}
}

void PlayerShipControlSystem::process(Entity *e) {
	Transform *transform = transformMapper->get(*e);

	if (moveLeft) {
		transform->addX(world->getDelta() * -0.3f);
	}
	if (moveRight) {
		transform->addX(world->getDelta() * 0.3f);
	}

	if (shoot) {
		Entity *missile = EntityFactory::createMissile(world);
		missile->getComponent(Transform())->setLocation(transform->getX(), transform->getY() - 20);
		missile->getComponent(Velocity())->setVelocity(-0.5f);
		missile->getComponent(Velocity())->setAngle(90);
		missile->refresh();

		shoot = false;
	}
}

}
