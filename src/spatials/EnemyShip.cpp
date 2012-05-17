#include "spatials/EnemyShip.h"
#include "components/Transform.h"

#include "hecate/ComponentMapper.h"
#include "hecate/World.h"

#include "SDL_gfxPrimitives.h"

namespace StarWarrior {

using namespace hecate;

EnemyShip::EnemyShip(World *w, Entity *o) : Spatial(w, o) {
}

EnemyShip::~EnemyShip() {
}

void EnemyShip::initalize() {
	ComponentMapper<Transform> transformMapper(transform, this->world);
	Sint16 x[3] = {0, 20, 10}, y[3] = {20,20,0};

	transform = transformMapper.get(*owner);
	// Should check for NULL after CreateRGBSurface
	ship = SDL_CreateRGBSurface(SDL_SWSURFACE, 20, 20, 32, 0, 0, 0, 0);
	// Should check for 0 (success) or -1 (failure) after filledPolygonRGBAMT
	filledPolygonRGBA(ship, x, y, 3, 255, 0, 0, 0);
}

void EnemyShip::render(SDL_Surface *s) {
	static SDL_Rect r = { 20, 20, 20, 20 };
	r.x = transform->getX();
	r.y = transform->getY();
	SDL_BlitSurface(ship, NULL, s, &r);
}

}
