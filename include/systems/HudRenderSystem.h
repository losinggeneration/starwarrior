#ifndef STARWARRIOR_HUDRENDERSYSTEM_H
#define STARWARRIOR_HUDRENDERSYSTEM_H

#include "hecate/ComponentMapper.h"
#include "hecate/EntityProcessingSystem.h"
#include "SDL_ttf.h"

namespace StarWarrior {

class Health;
class Player;

class HudRenderSystem : public hecate::EntityProcessingSystem {
public:
	HudRenderSystem(SDL_Surface *screen, int height, TTF_Font *font);
	virtual ~HudRenderSystem();
	virtual void initialize();

protected:
	virtual void process(hecate::Entity *e);

private:
	SDL_Surface *screen;
	TTF_Font *font;
	int height;
	hecate::ComponentMapper<Health> *healthMapper;
};

}

#endif
