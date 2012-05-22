#include "systems/HealthBarRenderSystem.h"

#include "components/Health.h"
#include "components/Transform.h"

#include <sstream>

using namespace hecate;

namespace StarWarrior {

HealthBarRenderSystem::HealthBarRenderSystem(SDL_Surface *screen, TTF_Font *font) {
	Health h;
	Transform t;
	componentList_t l;

	l.push_back(&h);
	l.push_back(&t);
	setupTypes(l);

	this->screen = screen;
	this->font = font;
}

void HealthBarRenderSystem::initialize() {
	healthMapper = new ComponentMapper<Health>(Health(), world);
	transformMapper = new ComponentMapper<Transform>(Transform(), world);
}

void HealthBarRenderSystem::process(Entity *e) {
	Health *health = healthMapper->get(*e);
	Transform *transform = transformMapper->get(*e);
	std::string text;
	SDL_Color white = {255, 255, 255};
	SDL_Rect r;

	if(health) {
		std::stringstream ss;
		ss << health->getHealthPercentage() << "%";
		ss >> text;

		SDL_Surface *rendered = TTF_RenderText_Solid(font, text.c_str(), white);
		r.w = rendered->w;
		r.h = rendered->h;
		r.x = transform->getX() - 10;
		r.y = transform->getY() - 30;
		SDL_BlitSurface(screen, &r, rendered, NULL);
	}
}

}
