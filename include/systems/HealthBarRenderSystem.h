#ifndef STARWARRIOR_HEALTHBARRENDERSYSTEM_H
#define STARWARRIOR_HEALTHBARRENDERSYSTEM_H

#include "hecate/ComponentMapper.h"
#include "hecate/EntityProcessingSystem.h"

#include "SDL.h"
#include "SDL_ttf.h"

namespace StarWarrior {

class Health;
class Transform;

class HealthBarRenderSystem : public hecate::EntityProcessingSystem {
public:
	HealthBarRenderSystem(SDL_Surface *screen, TTF_Font *font);
	virtual ~HealthBarRenderSystem();
	virtual void initialize();

protected:
	virtual void process(hecate::Entity *e);

private:
	SDL_Surface *screen;
	TTF_Font *font;
	hecate::ComponentMapper<Health> *healthMapper;
	hecate::ComponentMapper<Transform> *transformMapper;
};

}

#endif
