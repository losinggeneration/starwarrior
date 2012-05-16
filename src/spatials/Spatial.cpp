#include "spatials/Spatial.h"

namespace SpaceWarrior {

using namespace hecate;

Spatial::Spatial(World *w, Entity *o) : world(w), owner(o) {
}

}