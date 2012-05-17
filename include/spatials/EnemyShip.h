#ifndef SPACEWARRIOR_ENEMYSHIP_H
#define SPACEWARRIOR_ENEMYSHIP_H

#include "SDL.h"
#include "spatials/Spatial.h"

namespace StarWarrior {

class Transform;

class EnemyShip : public Spatial {
	EnemyShip(hecate::World *world, hecate::Entity *owner);
	~EnemyShip();
	void initalize();
	void render(SDL_Surface *s);

private:
	Transform *transform;
	SDL_Surface *ship;
};

}

#endif
