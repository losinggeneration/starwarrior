#include "components/Transform.h"

namespace StarWarrior {

Transform::Transform() {
}

Transform::Transform(float x, float y) {
	init(x, y);
}

Transform::Transform(float x, float y, float rotation) {
	init(x, y);
	this->rotation = rotation;
}

void Transform::addX(float x) {
	this->x += x;
}

void Transform::addY(float y) {
	this->y += y;
}

float Transform::getX() {
	return x;
}

void Transform::setX(float x) {
	this->x = x;
}

float Transform::getY() {
	return y;
}

void Transform::setY(float y) {
	this->y = y;
}

void Transform::setLocation(float x, float y) {
	this->x = x;
	this->y = y;
}

float Transform::getRotation() {
	return rotation;
}

void Transform::setRotation(float rotation) {
	this->rotation = rotation;
}

void Transform::addRotation(float angle) {
// 	rotation = (rotation + angle) % 360;
}

float Transform::getRotationAsRadians() {
// 	return (float) Math.toRadians(rotation);
}

float Transform::getDistanceTo(const Transform &t) {
// 	return Utils.distance(t.getX(), t.getY(), x, y);
}

void Transform::init(float x, float y) {
	this->x = x;
	this->y = y;
}

}