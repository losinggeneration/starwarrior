#ifndef STARWARRIOR_PLAYERSHIP_H
#define STARWARRIOR_PLAYERSHIP_H

#include "SDL.h"
#include "spatials/Spatial.h"

namespace StarWarrior {

class Transform;

class PlayerShip : public Spatial {
public:
	PlayerShip(hecate::World *world, hecate::Entity *owner);
	~PlayerShip();
	void initialize();
	void render(SDL_Surface *s);

private:
	Transform *transform;
	SDL_Surface *ship;
};

}

#endif
