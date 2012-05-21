#ifndef STARWARRIOR_EXPIRATIONSYSTEM_H
#define STARWARRIOR_EXPIRATIONSYSTEM_H

#include "hecate/ComponentMapper.h"
#include "hecate/EntityProcessingSystem.h"

namespace StarWarrior {

class Expires;

class ExpirationSystem : public hecate::EntityProcessingSystem {
public:
	ExpirationSystem();
	void initialize();

protected:
	void process(hecate::Entity *e);

private:
	hecate::ComponentMapper<Expires> *expiresMapper;
};

}

#endif
