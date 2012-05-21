#include "components/Expires.h"

namespace StarWarrior {

Expires::Expires() : lifeTime(100) {
	setType(this);
}

Expires::Expires(int lifeTime) {
	setType(this);
	this->lifeTime = lifeTime;
}

int Expires::getLifeTime() const {
	return lifeTime;
}

void Expires::setLifeTime(int lifeTime) {
	this->lifeTime = lifeTime;
}

void Expires::reduceLifeTime(int lifeTime) {
	this->lifeTime -= lifeTime;
}

bool Expires::isExpired() const {
	return lifeTime <= 0;
}


}