#ifndef STARWARRIOR_RENDERSYSTEM_H
#define STARWARRIOR_RENDERSYSTEM_H

#include "hecate/ComponentMapper.h"
#include "hecate/EntityProcessingSystem.h"

#include "SDL.h"

namespace StarWarrior {

class Spatial;
class SpatialForm;
class Transform;

class RenderSystem : hecate::EntityProcessingSystem {
public:
	RenderSystem(SDL_Surface *screen, int width, int height);
	void initialize();

protected:
	void process(hecate::Entity *e);
	void added(hecate::Entity *e);
	void removed(hecate::Entity *e);

private:
	typedef std::map<int, Spatial*> spatialMap_t;
	spatialMap_t spatials;
	hecate::ComponentMapper<SpatialForm> spatialFormMapper;
	hecate::ComponentMapper<Transform> transformMapper;
	SDL_Surface *screen;

	int width;
	int height;

	Spatial *createSpatial(hecate::Entity *e);
};

}

#endif
