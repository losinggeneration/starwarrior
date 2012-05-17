#ifndef STARWARRIOR_ENEMYSHIP_H
#define STARWARRIOR_ENEMYSHIP_H

#include "SDL.h"
#include "spatials/Spatial.h"

namespace StarWarrior {

class Transform;

class EnemyShip : public Spatial {
public:
	EnemyShip(hecate::World *world, hecate::Entity *owner);
	~EnemyShip();
	void initialize();
	void render(SDL_Surface *s);

private:
	Transform *transform;
	SDL_Surface *ship;
};

}

#endif
