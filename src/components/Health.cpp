#include "components/Health.h"

namespace StarWarrior {

Health::Health(float health) {
	this->health = this->maximumHealth = health;
}

float Health::getHealth() {
	return health;
}

float Health::getMaximumHealth() {
	return maximumHealth;
}

int Health::getHealthPercentage() {
// 	return Math.round(health / maximumHealth * 100f);
}

void Health::addDamage(int damage) {
	health -= damage;
	if(health < 0)
		health = 0;
}

bool Health::isAlive() {
	return health > 0;
}


}