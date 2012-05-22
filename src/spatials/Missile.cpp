#include "spatials/Missile.h"

#include "components/Transform.h"

#include "hecate/ComponentMapper.h"

#include "SDL_gfxPrimitives.h"

namespace StarWarrior {

using namespace hecate;

Missile::Missile(World *w, Entity *e) : Spatial(w, e) {
}

void Missile::initialize() {
	ComponentMapper<Transform> transformMapper(Transform(), world);
	transform = transformMapper.get(*owner);
}

void Missile::render(SDL_Surface *s) {
	rectangleRGBA(s, transform->getX(), transform->getY(), transform->getX() + 2, transform->getY() + 6, 255, 255, 255, 255);
}

}
