#include "systems/EnemyShooterSystem.h"

#include "hecate/Entity.h"

#include "EntityFactory.h"

#include "components/Enemy.h"
#include "components/Transform.h"
#include "components/Velocity.h"
#include "components/Weapon.h"

using namespace hecate;

namespace StarWarrior {

EnemyShooterSystem::EnemyShooterSystem() {
	Enemy e;
	Transform t;
	Weapon w;
	componentList_t l;

	l.push_back(&e);
	l.push_back(&w);

	setupRequiredTypes(&t, l);
}

void EnemyShooterSystem::initialize() {
	transformMapper = new ComponentMapper<Transform>(Transform(), world);
	weaponMapper = new ComponentMapper<Weapon>(Weapon(), world);
}

void EnemyShooterSystem::begin() {
	now = SDL_GetTicks();
}

void EnemyShooterSystem::process(Entity *e) {
	Weapon *weapon = weaponMapper->get(*e);

	if (weapon && weapon->getShotAt() + 2000 < now) {
		Transform *transform = transformMapper->get(*e);

		Entity *missile = EntityFactory::createMissile(world);
		missile->getComponent<Transform>(Transform())->setLocation(transform->getX(), transform->getY() + 20);
		missile->getComponent<Velocity>(Velocity())->setVelocity(-0.5f);
		missile->getComponent<Velocity>(Velocity())->setAngle(270.0f);
		missile->refresh();

		weapon->setShotAt(now);
	}
}

}
