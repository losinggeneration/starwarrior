#include "components/Velocity.h"

namespace StarWarrior {

Velocity::Velocity() {
}

Velocity::Velocity(float vector) {
	this->velocity = vector;
}

Velocity::Velocity(float velocity, float angle) {
	this->velocity = velocity;
	this->angle = angle;
}

float Velocity::getVelocity() {
	return velocity;
}

void Velocity::setVelocity(float velocity) {
	this->velocity = velocity;
}

void Velocity::setAngle(float angle) {
	this->angle = angle;
}

float Velocity::getAngle() {
	return angle;
}

void Velocity::addAngle(float a) {
// 	angle = (angle + a) % 360;
}

float Velocity::getAngleAsRadians() {
// 	return (float) Math.toRadians(angle);
}


}