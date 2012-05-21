#include "systems/RenderSystem.h"

#include "components/SpatialForm.h"
#include "components/Transform.h"

#include "spatials/EnemyShip.h"
#include "spatials/Explosion.h"
#include "spatials/Missile.h"
#include "spatials/PlayerShip.h"
#include "spatials/Spatial.h"

#include "SDL.h"
#include <cstring>

using namespace hecate;

namespace StarWarrior {

RenderSystem::RenderSystem(SDL_Surface *screen, int width, int height) {
	SpatialForm sf("");
	Transform t;
	componentList_t l;
	l.push_back(&t);
	l.push_back(&sf);
	setupTypes(l);

	this->screen = screen;
	this->width = width;
	this->height = height;
}

void RenderSystem::initialize() {
	spatialFormMapper = new ComponentMapper<SpatialForm>(SpatialForm(""), world);
	transformMapper = new ComponentMapper<Transform>(Transform(), world);
}

void RenderSystem::process(Entity *e) {
	spatialMap_t::iterator it = spatials.find(e->getId());
	Spatial *spatial = NULL;
	Transform *transform = transformMapper->get(*e);

	if(it != spatials.end()) {
		spatial = it->second;
	}

	if (transform->getX() >= 0 && transform->getY() >= 0 && transform->getX() < width && transform->getY() < height && spatial != NULL) {
		spatial->render(screen);
	}
}

void RenderSystem::added(Entity *e) {
	Spatial *spatial = createSpatial(e);
	if (spatial != NULL) {
		spatial->initialize();
		spatials[e->getId()] = spatial;
	}
}

void RenderSystem::removed(Entity *e) {
	spatials.erase(e->getId());
}

Spatial *RenderSystem::createSpatial(Entity *e) {
	SpatialForm *spatialForm = spatialFormMapper->get(*e);
	std::string spatialFormFile = spatialForm->getSpatialFormFile();

	if (strcasecmp("PlayerShip", spatialFormFile.c_str()) == 0) {
		return new PlayerShip(world, e);
	}
// 	} else if (strcasecmp("Missile", spatialFormFile.c_str()) == 0) {
// 		return new Missile(world, e);
// 	} else if (strcasecmp("EnemyShip", spatialFormFile.c_str()) == 0) {
// 		return new EnemyShip(world, e);
// 	} else if (strcasecmp("BulletExplosion", spatialFormFile.c_str()) == 0) {
// 		return new Explosion(world, e, 10);
// 	} else if (strcasecmp("ShipExplosion", spatialFormFile.c_str()) == 0) {
// 		return new Explosion(world, e, 30);
// 	}

	return NULL;
}

}
