#include "components/Weapon.h"

namespace StarWarrior {

Weapon::Weapon() {
	setType(this);
}

void Weapon::setShotAt(long shotAt) {
	this->shotAt = shotAt;
}

long Weapon::getShotAt() const {
	return shotAt;
}

}
