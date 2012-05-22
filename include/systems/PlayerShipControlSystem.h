#ifndef STARWARRIOR_PLAYERSHIPCONTROLSYSTEM_H
#define STARWARRIOR_PLAYERSHIPCONTROLSYSTEM_H

#include "hecate/ComponentMapper.h"
#include "hecate/EntityProcessingSystem.h"

#include "SDL.h"

namespace StarWarrior {

class Transform;

class PlayerShipControlSystem : public hecate::EntityProcessingSystem {
public:
	PlayerShipControlSystem();
	virtual ~PlayerShipControlSystem();
	virtual void initialize();
	void keyPressed(SDLKey key);
	void keyReleased(SDLKey key);

protected:
	virtual void process(hecate::Entity *e);

private:
	bool moveRight;
	bool moveLeft;
	bool shoot;
	hecate::ComponentMapper<Transform> *transformMapper;
};

}

#endif
