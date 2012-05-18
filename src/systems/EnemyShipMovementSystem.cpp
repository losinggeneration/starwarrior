#include "systems/EnemyShipMovementSystem.h"

#include "components/Transform.h"

using namespace hecate;

namespace StarWarrior {

EnemyShipMovementSystem::EnemyShipMovementSystem(/*GameContainer container*/) :
EntityProcessingSystem(t, std::set<Component*>()){
}

void EnemyShipMovementSystem::initialize() {
}

void EnemyShipMovementSystem::process(Entity *e) {
}

}
