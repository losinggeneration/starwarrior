#ifndef STARWARRIOR_MOVEMENTSYSTEM_H
#define STARWARRIOR_MOVEMENTSYSTEM_H

#include "hecate/ComponentMapper.h"
#include "hecate/EntityProcessingSystem.h"

namespace StarWarrior {

class Transform;
class Velocity;

class MovementSystem : public hecate::EntityProcessingSystem {
public:
	MovementSystem();
	virtual ~MovementSystem();
	virtual void initialize();

protected:
	virtual void process(hecate::Entity *e);

private:
	hecate::ComponentMapper<Velocity> *velocityMapper;
	hecate::ComponentMapper<Transform> *transformMapper;
};

}

#endif
