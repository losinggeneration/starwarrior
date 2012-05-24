#include "SDL.h"
#include "SDL_ttf.h"
#include "hecate/hecate.h"
#include <cstdlib>
#include <ctime>

#include "EntityFactory.h"
#include "components/Health.h"
#include "components/Player.h"
#include "components/SpatialForm.h"
#include "components/Transform.h"
#include "components/Velocity.h"
#include "systems/CollisionSystem.h"
#include "systems/EnemyShipMovementSystem.h"
#include "systems/EnemyShooterSystem.h"
#include "systems/EnemySpawnSystem.h"
#include "systems/ExpirationSystem.h"
#include "systems/HealthBarRenderSystem.h"
#include "systems/HudRenderSystem.h"
#include "systems/MovementSystem.h"
#include "systems/PlayerShipControlSystem.h"
#include "systems/RenderSystem.h"

#define STARWARRIOR_WIDTH 1024
#define STARWARRIOR_HEIGHT 768
#define STARWARRIOR_FONT "/usr/share/fonts/TTF/FreeSans.ttf"

using namespace std;
using namespace hecate;
using namespace StarWarrior;

SDL_Surface *screen, *blank;
TTF_Font *font;
World *world;
EntitySystem *collisionSystem;
EntitySystem *enemyShipMovementSystem;
EntitySystem *enemyShooterSystem;
EntitySystem *enemySpawnSystem;
EntitySystem *expirationSystem;
EntitySystem *healthBarRenderSystem;
EntitySystem *hudRenderSystem;
EntitySystem *movementSystem;
EntitySystem *controlSystem;
EntitySystem *renderSystem;

void initialize();
void initEnemyShips();
void initPlayerShip();
void update(int delta);
void render();
void gameLoop();
void quit();

Uint32 passTime() {
	static Uint32 nextTime = 0;
	Uint32 now = SDL_GetTicks();

	if (nextTime <= now) {
		nextTime = now + 30;

		return 0;
	}

	return nextTime - now;
}

void delay() {
	SDL_Delay(passTime());
}

void initialize() {
	srand((unsigned)time(0));
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	screen = SDL_SetVideoMode(STARWARRIOR_WIDTH, STARWARRIOR_HEIGHT, 32, SDL_SWSURFACE);
	blank = SDL_CreateRGBSurface(SDL_SWSURFACE, STARWARRIOR_WIDTH, STARWARRIOR_HEIGHT, 32, 0, 0, 0, 0);
	font = TTF_OpenFont(STARWARRIOR_FONT, 12);

	SystemManager *systemManager = world->getSystemManager();
	collisionSystem = systemManager->setSystem(new CollisionSystem());
	enemyShipMovementSystem = systemManager->setSystem(new EnemyShipMovementSystem(STARWARRIOR_WIDTH));
	enemyShooterSystem = systemManager->setSystem(new EnemyShooterSystem());
	enemySpawnSystem = systemManager->setSystem(new EnemySpawnSystem(500, STARWARRIOR_WIDTH));
	expirationSystem = systemManager->setSystem(new ExpirationSystem());
	healthBarRenderSystem = systemManager->setSystem(new HealthBarRenderSystem(screen, font));
	hudRenderSystem = systemManager->setSystem(new HudRenderSystem(screen, STARWARRIOR_HEIGHT, font));
	movementSystem = systemManager->setSystem(new MovementSystem());
	controlSystem = systemManager->setSystem(new PlayerShipControlSystem());
	renderSystem = systemManager->setSystem(new RenderSystem(screen, STARWARRIOR_WIDTH, STARWARRIOR_HEIGHT));

	systemManager->initializeAll();

	initPlayerShip();
	initEnemyShips();
}

void initEnemyShips() {
	for (int i = 0; 10 > i; i++) {
		Entity *e = EntityFactory::createEnemyShip(world);

		e->getComponent(Transform())->setLocation(rand()%STARWARRIOR_WIDTH, rand()%400+50);
		e->getComponent(Velocity())->setVelocity(0.05f);
		e->getComponent(Velocity())->setAngle((rand()%2) ? 0 : 180);

		e->refresh();
	}
}

void initPlayerShip() {
	Entity *e = world->createEntity();
	e->setGroup("SHIPS");
	e->addComponent(new Transform(STARWARRIOR_WIDTH / 2, STARWARRIOR_HEIGHT - 40));
	e->addComponent(new SpatialForm("PlayerShip"));
	e->addComponent(new Health(30));
	e->addComponent(new Player());

	e->refresh();
}

void update(int delta) {
	world->loopStart();

	world->setDelta(delta);

	controlSystem->process();
	movementSystem->process();
	enemyShooterSystem->process();
	enemyShipMovementSystem->process();
	collisionSystem->process();
	enemySpawnSystem->process();
	expirationSystem->process();
}

void render() {
	SDL_BlitSurface(blank, NULL, screen, NULL);
	renderSystem->process();
	healthBarRenderSystem->process();
	hudRenderSystem->process();

	SDL_Flip(screen);
}

void gameLoop() {
	bool quit = false;
	Uint32 lastTime, thisTime;
	SDL_Event event;
	PlayerShipControlSystem *pscs = dynamic_cast<PlayerShipControlSystem*>(controlSystem);

	while(!quit) {
		update(thisTime-lastTime);
		render();
		lastTime = SDL_GetTicks();
		delay();
		thisTime = SDL_GetTicks();
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_KEYDOWN:
					pscs->keyPressed(event.key.keysym.sym);
					break;
				case SDL_KEYUP:
					if(event.key.keysym.sym == SDLK_ESCAPE) {
						quit = true;
					}

					pscs->keyReleased(event.key.keysym.sym);
					break;
			}
		}
	}
}

void quit() {
	SDL_FreeSurface(blank);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
}

int main(int argc, char *argv[]) {
	world = new World();

	initialize();
	gameLoop();
	quit();

	delete world;

	return 0;
}
