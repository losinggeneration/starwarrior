#ifndef STARWARRIOR_WEAPON_H
#define STARWARRIOR_WEAPON_H

#include "hecate/Component.h"

namespace StarWarrior {

class Weapon : public hecate::Component {
public:
	void setShotAt(long shotAt);
	long getShotAt() const;

private:
	long shotAt;
};

}

#endif
