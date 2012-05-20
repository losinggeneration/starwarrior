#include "systems/ExpirationSystem.h"

#include "components/Expires.h"

using namespace hecate;

namespace StarWarrior {

ExpirationSystem::ExpirationSystem() : expiresMapper(Expires(), world) {
	Expires e;
	componentList_t l;
	l.push_back(&e);
	setupTypes(l);
}

void ExpirationSystem::initialize() {
}

void ExpirationSystem::process(Entity *e) {
	Expires *expires = expiresMapper.get(*e);
	expires->reduceLifeTime(world->getDelta());

	if (expires->isExpired()) {
		world->deleteEntity(e);
	}
}

}
