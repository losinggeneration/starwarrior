#include "components/Expires.h"

namespace StarWarrior {

Expires::Expires(int lifeTime) {
	this->lifeTime = lifeTime;
}

int Expires::getLifeTime() {
	return lifeTime;
}

void Expires::setLifeTime(int lifeTime) {
	this->lifeTime = lifeTime;
}

void Expires::reduceLifeTime(int lifeTime) {
	this->lifeTime -= lifeTime;
}

bool Expires::isExpired() {
	return lifeTime <= 0;
}


}