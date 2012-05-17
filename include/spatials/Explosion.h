#ifndef SPACEWARRIOR_EXPLOSION_H
#define SPACEWARRIOR_EXPLOSION_H

#include "SDL.h"
#include "spatials/Spatial.h"

namespace StarWarrior {

class Expires;
class Transform;

class Explosion : public Spatial {
public:
	Explosion(hecate::World *world, hecate::Entity *owner, int radius);
	void initialize();
	void render(SDL_Surface *s);

private:
	Transform *transform;
	Expires *expires;
	SDL_Color color;
	Uint8 alpha;
	int initialLifeTime;
	int radius;
};

}

#endif
