#include "EntityFactory.h"

#include "components/Enemy.h"
#include "components/Expires.h"
#include "components/Health.h"
#include "components/SpatialForm.h"
#include "components/Transform.h"
#include "components/Velocity.h"
#include "components/Weapon.h"

#include "hecate/Entity.h"
#include "hecate/World.h"

using namespace hecate;

namespace StarWarrior {

namespace EntityFactory {

Entity *createMissile(World *world) {
	Entity *missile = world->createEntity();
	missile->setGroup("BULLETS");

	missile->addComponent(new Transform());
	missile->addComponent(new SpatialForm("Missile"));
	missile->addComponent(new Velocity());
	missile->addComponent(new Expires(2000));

	return missile;
}

Entity *createEnemyShip(World *world) {
	Entity *e = world->createEntity();
	e->setGroup("SHIPS");

	e->addComponent(new Transform());
	e->addComponent(new SpatialForm("EnemyShip"));
	e->addComponent(new Health(10));
	e->addComponent(new Weapon());
	e->addComponent(new Enemy());
	e->addComponent(new Velocity());

	return e;
}

Entity *createBulletExplosion(World *world, float x, float y) {
	Entity *e = world->createEntity();

	e->setGroup("EFFECTS");

	e->addComponent(new Transform(x, y));
	e->addComponent(new SpatialForm("BulletExplosion"));
	e->addComponent(new Expires(1000));

	return e;
}

Entity *createShipExplosion(World *world, float x, float y) {
	Entity *e = world->createEntity();

	e->setGroup("EFFECTS");

	e->addComponent(new Transform(x, y));
	e->addComponent(new SpatialForm("ShipExplosion"));
	e->addComponent(new Expires(1000));

	return e;
}

}

}