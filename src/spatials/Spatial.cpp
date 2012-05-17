#include "spatials/Spatial.h"

namespace StarWarrior {

using namespace hecate;

Spatial::Spatial(World *w, Entity *o) : world(w), owner(o) {
}

}