#include "components/Velocity.h"
#include "utils/utils.h"

namespace StarWarrior {

using namespace Utils;

Velocity::Velocity() {
	setType(this);
}

Velocity::Velocity(float vector) {
	setType(this);
	this->velocity = vector;
}

Velocity::Velocity(float velocity, float angle) {
	setType(this);
	this->velocity = velocity;
	this->angle = angle;
}

float Velocity::getVelocity() const {
	return velocity;
}

void Velocity::setVelocity(float velocity) {
	this->velocity = velocity;
}

void Velocity::setAngle(float angle) {
	this->angle = angle;
}

float Velocity::getAngle() const {
	return angle;
}

void Velocity::addAngle(float a) {
	angle = (int)(angle + a) % 360;
}

float Velocity::getAngleAsRadians() const {
	return (float) toRadians(angle);
}


}