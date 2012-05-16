#ifndef STARWARRIOR_VELOCITY_H
#define STARWARRIOR_VELOCITY_H

#include "hecate/Component.h"

namespace StarWarrior {

class Velocity : public hecate::Component {
public:
	Velocity();
	Velocity(float vector);
	Velocity(float velocity, float angle);
	float getVelocity();
	void setVelocity(float velocity);
	void setAngle(float angle);
	float getAngle();
	void addAngle(float a);
	float getAngleAsRadians();

private:
	float velocity;
	float angle;
};

}

#endif
