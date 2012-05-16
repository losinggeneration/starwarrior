#ifndef STARWARRIOR_HEALTH_H
#define STARWARRIOR_HEALTH_H

#include "hecate/Component.h"

namespace StarWarrior {

class Health : public hecate::Component {
	Health(float health);
	float getHealth();
	float getMaximumHealth();
	int getHealthPercentage();
	void addDamage(int damage);
	bool isAlive();

private:
	float health;
	float maximumHealth;
};

}

#endif
