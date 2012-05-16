#ifndef STARWARRIOR_EXPIRES_H
#define STARWARRIOR_EXPIRES_H

#include "hecate/Component.h"

namespace StarWarrior {

class Expires : public hecate::Component {
public:
	Expires(int lifeTime);
	int getLifeTime() const;
	void setLifeTime(int lifeTime);
	void reduceLifeTime(int lifeTime);
	bool isExpired() const;

private:
	int lifeTime;
};

}

#endif
