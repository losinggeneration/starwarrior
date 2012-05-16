#include "spatials/EnemyShip.h"
#include "components/Transform.h"

#include "hecate/ComponentMapper.h"
#include "hecate/World.h"

namespace SpaceWarrior {

using namespace hecate;

EnemyShip::EnemyShip(World *w, Entity *o) : Spatial(w, o) {
}

EnemyShip::~EnemyShip() {
}

void EnemyShip::initalize() {
	ComponentMapper<Transform> transformMapper(transform, this->world);
	transform = transformMapper.get(*owner);
}

void EnemyShip::render(SDL_Surface *s) {
}

}