#include "components/Weapon.h"

namespace StarWarrior {

void Weapon::setShotAt(long shotAt) {
	this->shotAt = shotAt;
}

long Weapon::getShotAt() const {
	return shotAt;
}

}
