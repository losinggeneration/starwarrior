#ifndef STARWARRIOR_EXPIRATIONSYSTEM_H
#define STARWARRIOR_EXPIRATIONSYSTEM_H

#include "hecate/ComponentMapper.h"
#include "hecate/EntityProcessingSystem.h"

namespace StarWarrior {

class Expires;

class ExpirationSystem : public hecate::EntityProcessingSystem {
public:
	ExpirationSystem();
	virtual ~ExpirationSystem();
	virtual void initialize();

protected:
	virtual void process(hecate::Entity *e);

private:
	hecate::ComponentMapper<Expires> *expiresMapper;
};

}

#endif
