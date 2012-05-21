#include "components/Transform.h"
#include "utils/utils.h"

namespace StarWarrior {

using namespace Utils;

Transform::Transform() {
	setType(this);
}

Transform::Transform(float x, float y) {
	setType(this);
	init(x, y);
}

Transform::Transform(float x, float y, float rotation) {
	setType(this);
	init(x, y);
	this->rotation = rotation;
}

void Transform::addX(float x) {
	this->x += x;
}

void Transform::addY(float y) {
	this->y += y;
}

float Transform::getX() const {
	return x;
}

void Transform::setX(float x) {
	this->x = x;
}

float Transform::getY() const {
	return y;
}

void Transform::setY(float y) {
	this->y = y;
}

void Transform::setLocation(float x, float y) {
	this->x = x;
	this->y = y;
}

float Transform::getRotation() const {
	return rotation;
}

void Transform::setRotation(float rotation) {
	this->rotation = rotation;
}

void Transform::addRotation(float angle) {
	rotation = (int)(rotation + angle) % 360;
}

float Transform::getRotationAsRadians() const {
	return (float) toRadians(rotation);
}

float Transform::getDistanceTo(const Transform &t) const {
	return distance(t.getX(), t.getY(), x, y);
}

void Transform::init(float x, float y) {
	this->x = x;
	this->y = y;
}

}