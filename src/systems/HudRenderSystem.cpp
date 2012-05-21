#include "systems/HudRenderSystem.h"

#include "components/Health.h"
#include "components/Player.h"

#include <sstream>

using namespace hecate;

namespace StarWarrior {

HudRenderSystem::HudRenderSystem(SDL_Surface *screen, int height, TTF_Font *font) {
	Health h;
	Player p;
	componentList_t l;

	l.push_back(&h);
	l.push_back(&p);
	setupTypes(l);

	this->screen = screen;
	this->font = font;
	this->height = height;
}

void HudRenderSystem::initialize() {
	healthMapper = new ComponentMapper<Health>(Health(), world);
}

void HudRenderSystem::process(Entity *e) {
	Health *health = healthMapper->get(*e);
	std::stringstream ss;
	std::string text;
	SDL_Color white = {255,255,255};
	SDL_Rect r;

	ss << "Health: " << health->getHealthPercentage() << "%";
	ss >> text;

	SDL_Surface *render = TTF_RenderText_Solid(font, text.c_str(), white);
	r.w = render->w;
	r.h = render->h;
	r.x = 20;
	r.y = height - 40;

	SDL_BlitSurface(screen, &r, render, NULL);
}

}
