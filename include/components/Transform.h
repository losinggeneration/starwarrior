#ifndef STARWARRIOR_TRANSFORM_H
#define STARWARRIOR_TRANSFORM_H

#include "hecate/Component.h"

namespace StarWarrior {

class Transform : public hecate::Component {
public:
	Transform();
	Transform(float x, float y);
	Transform(float x, float y, float rotation);
	void addX(float x);
	void addY(float y);
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
	void setLocation(float x, float y);
	float getRotation() const;
	void setRotation(float rotation);
	void addRotation(float angle);
	float getRotationAsRadians() const;
	float getDistanceTo(const Transform &t) const;

private:
	void init(float x, float y);

	float x;
	float y;
	float rotation;
};

}

#endif
