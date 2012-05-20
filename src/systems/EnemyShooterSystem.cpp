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
	Enemy *e;
	Transform *t;
	Weapon *w;
	componentSet_t s;
	s.insert(e);
	s.insert(w);
	setupRequiredTypes(e, s);
}

void EnemyShooterSystem::initialize() {
	weaponMapper = new ComponentMapper<Weapon>(Weapon(), world);
	transformMapper = new ComponentMapper<Transform>(Transform(), world);
}

void EnemyShooterSystem::begin() {
	now = SDL_GetTicks();
}

void EnemyShooterSystem::process(Entity *e) {
	Weapon *weapon = weaponMapper->get(*e);

	if (weapon->getShotAt() + 2000 < now) {
		Transform *transform = transformMapper->get(*e);

		Entity *missile = EntityFactory::createMissile(world);
		missile->getComponent<Transform>(Transform())->setLocation(transform->getX(), transform->getY() + 20);
// 		missile->getComponent(Velocity.class).setVelocity(-0.5f);
// 		missile->getComponent(Velocity.class).setAngle(270);
		missile->getComponent<Velocity>(Velocity());
		missile->refresh();

		weapon->setShotAt(now);
	}

}

}
