#include "components/Health.h"

#include <cmath>

namespace StarWarrior {

Health::Health() {
	setType(this);
	health = maximumHealth = 100;
}

Health::Health(float health) {
	setType(this);
	this->health = this->maximumHealth = health;
}

float Health::getHealth() const {
	return health;
}

float Health::getMaximumHealth() const {
	return maximumHealth;
}

int Health::getHealthPercentage() const {
	return round(health / maximumHealth * 100.0f);
}

void Health::addDamage(int damage) {
	health -= damage;
	if(health < 0)
		health = 0;
}

bool Health::isAlive() const {
	return health > 0;
}


}