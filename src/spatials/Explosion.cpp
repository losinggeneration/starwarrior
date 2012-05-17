#include "spatials/Explosion.h"

#include "components/Expires.h"
#include "components/Transform.h"

#include "hecate/ComponentMapper.h"

#include "SDL_gfxPrimitives.h"

namespace StarWarrior {

using namespace hecate;

Explosion::Explosion(World *w, Entity *e, int r) : Spatial(w, e), radius(r) {
}

void Explosion::initialize() {
	ComponentMapper<Transform> transformMapper(transform, world);
	transform = transformMapper.get(*owner);

	ComponentMapper<Expires> expiresMapper(expires, world);
	expires = expiresMapper.get(*owner);
	initialLifeTime = expires->getLifeTime();

	color.r = 255;
	color.g = 255;
	color.b = 0;
}

void Explosion::render(SDL_Surface *s) {
	alpha = (float)expires->getLifeTime()/(float)initialLifeTime;

	filledEllipseRGBA(s, transform->getX() - radius, transform->getY() - radius, radius*2, radius*2, color.r, color.g, color.b, alpha);
}

}
