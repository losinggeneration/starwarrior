#ifndef SPACEWARRIOR_MISSILE_H
#define SPACEWARRIOR_MISSILE_H

#include "SDL.h"
#include "spatials/Spatial.h"

namespace StarWarrior {

class Transform;

class Missile : public Spatial {
public:
	Missile(hecate::World *world, hecate::Entity *owner);
	void initialize();
	void render(SDL_Surface *s);

private:
	Transform *transform;
};

}

#endif
