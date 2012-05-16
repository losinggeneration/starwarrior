#ifndef STARWARRIOR_HEALTH_H
#define STARWARRIOR_HEALTH_H

#include "hecate/Component.h"

namespace StarWarrior {

class Health : public hecate::Component {
	Health(float health);
	float getHealth() const;
	float getMaximumHealth() const;
	int getHealthPercentage() const;
	void addDamage(int damage);
	bool isAlive() const;

private:
	float health;
	float maximumHealth;
};

}

#endif
