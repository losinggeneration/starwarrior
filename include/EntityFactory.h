#ifndef STARWARRIOR_ENTITYFACTORY_H
#define STARWARRIOR_ENTITYFACTORY_H

namespace hecate {

class Entity;
class World;

}

namespace StarWarrior {

namespace EntityFactory {

hecate::Entity *createMissile(hecate::World *world);
hecate::Entity *createEnemyShip(hecate::World *world);
hecate::Entity *createBulletExplosion(hecate::World *world, float x, float y);
hecate::Entity *createShipExplosion(hecate::World *world, float x, float y);

}

}

#endif
