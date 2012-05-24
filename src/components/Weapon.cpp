#include "components/Weapon.h"

namespace StarWarrior {

Weapon::Weapon() : shotAt(0) {
	setType(this);
}

void Weapon::setShotAt(long shotAt) {
	this->shotAt = shotAt;
}

long Weapon::getShotAt() const {
	return shotAt;
}

}
