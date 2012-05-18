#ifndef STARWARRIOR_UTILS_H
#define STARWARRIOR_UTILS_H

#include <string>

namespace StarWarrior {
namespace Utils {

float toDegrees(float x);
float toRadians(float x);
float cosDeg(float x);
float sinDeg(float x);
float cubicInterpolation(float v0, float v1, float v2, float v3, float t);
float quadraticBezierInterpolation(float a, float b, float c, float t);
float euclideanDistanceSq2D(float x1, float y1, float x2, float y2);
float manhattanDistance(float x1, float y1, float x2, float y2);
float euclideanDistance(float x1, float y1, float x2, float y2);
float distance(float x1, float y1, float x2, float y2);
float lengthOfQuadraticBezierCurve(float x0, float y0, float x1, float y1, float x2, float y2);
float lerp(float a, float b, float t);
bool doCirclesCollide(float x1, float y1, float radius1, float x2, float y2, float radius2);
float angleInDegrees(float originX, float originY, float targetX, float targetY);
float angleInDegrees(float ownerRotation, float x1, float y1, float x2, float y2);
float angleInRadians(float originX, float originY, float targetX, float targetY);
bool shouldRotateCounterClockwise(float angleFrom, float angleTo);
float getRotatedX(float currentX, float currentY, float pivotX, float pivotY, float angleDegrees);
float getRotatedY(float currentX, float currentY, float pivotX, float pivotY, float angleDegrees);
float getXAtEndOfRotatedLineByOrigin(float x, float lineLength, float angleDegrees);
float getYAtEndOfRotatedLineByOrigin(float y, float lineLength, float angleDegrees);
bool collides(float x1, float y1, float radius1, float x2, float y2, float radius2);
std::string readFileContents(std::string file);

}

}

#endif