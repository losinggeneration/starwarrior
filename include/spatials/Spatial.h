#ifndef SPACEWARRIOR_SPATIAL_H
#define SPACEWARRIOR_SPATIAL_H

#include "SDL.h"
#include "hecate/Entity.h"
#include "hecate/World.h"

namespace SpaceWarrior {

class Spatial {
public:
	Spatial(hecate::World *world, hecate::Entity *owner);
	virtual void initalize() = 0;
	virtual void render(SDL_Surface *s) = 0;

protected:
	hecate::World *world;
	hecate::Entity *owner;
};

}

#endif
