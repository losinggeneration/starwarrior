#ifndef STARWARRIOR_UTILS_H
#define STARWARRIOR_UTILS_H

#include <cmath>
#include <fstream>
#include <string>
#include <sstream>

namespace StarWarrior {
namespace Utils {

const double pi = 3.1415926535897932384626433832795029L;

float toDegrees(float x) {
	return x*180/pi;
}

float toRadians(float x) {
	return x*pi/180;
}

float cosDeg(float x) {
	return cos(toDegrees(x));
}

float sinDeg(float x) {
	return sin(toDegrees(x));
}

float cubicInterpolation(float v0, float v1, float v2, float v3, float t) {
	float t2 = t * t;
	float a0 = v3 - v2 - v0 + v1;
	float a1 = v0 - v1 - a0;
	float a2 = v2 - v0;
	float a3 = v1;

	return (a0 * (t * t2)) + (a1 * t2) + (a2 * t) + a3;
}

float quadraticBezierInterpolation(float a, float b, float c, float t) {
	return (((1.0f - t) * (1.0f - t)) * a) + (((2.0f * t) * (1.0f - t)) * b) + ((t * t) * c);
}

float euclideanDistanceSq2D(float x1, float y1, float x2, float y2) {
	float dx = x1 - x2;
	float dy = y1 - y2;
	return dx * dx + dy * dy;
}

float manhattanDistance(float x1, float y1, float x2, float y2) {
	return std::abs(x1 - x2) + std::abs(y1 - y2);
}

float euclideanDistance(float x1, float y1, float x2, float y2) {
	float a = x1 - x2;
	float b = y1 - y2;

	return (float) sqrt(a * a + b * b);
}

float distance(float x1, float y1, float x2, float y2) {
	return euclideanDistance(x1, y1, x2, y2);
}

float lengthOfQuadraticBezierCurve(float x0, float y0, float x1, float y1, float x2, float y2) {
	if ((x0 == x1 && y0 == y1) || (x1 == x2 && y1 == y2)) {
		return distance(x0, y0, x2, y2);
	}

	float ax, ay, bx, by;
	ax = x0 - 2 * x1 + x2;
	ay = y0 - 2 * y1 + y2;
	bx = 2 * x1 - 2 * x0;
	by = 2 * y1 - 2 * y0;
	float A = 4 * (ax * ax + ay * ay);
	float B = 4 * (ax * bx + ay * by);
	float C = bx * bx + by * by;

	float Sabc = 2.0f * (float) sqrt(A + B + C);
	float A_2 = (float) sqrt(A);
	float A_32 = 2.0f * A * A_2;
	float C_2 = 2.0f * (float) sqrt(C);
	float BA = B / A_2;

	return (A_32 * Sabc + A_2 * B * (Sabc - C_2) + (4.0f * C * A - B * B) * (float) log((2 * A_2 + BA + Sabc) / (BA + C_2))) / (4 * A_32);
}

float lerp(float a, float b, float t) {
	if (t < 0)
		return a;
	return a + t * (b - a);
}

bool doCirclesCollide(float x1, float y1, float radius1, float x2, float y2, float radius2) {
	float dx = x2 - x1;
	float dy = y2 - y1;
	float d = radius1 + radius2;
	return (dx * dx + dy * dy) < (d * d);
}

float angleInDegrees(float originX, float originY, float targetX, float targetY) {
	return (float) toDegrees(atan2(targetY - originY, targetX - originX));
}

float angleInDegrees(float ownerRotation, float x1, float y1, float x2, float y2) {
	return (int)std::abs(ownerRotation - angleInDegrees(x1, y1, x2, y2)) % 360;
}

float angleInRadians(float originX, float originY, float targetX, float targetY) {
	return (float) atan2(targetY - originY, targetX - originX);
}

bool shouldRotateCounterClockwise(float angleFrom, float angleTo) {
	float diff = (int)(angleFrom - angleTo) % 360;
	return diff > 0 ? diff < 180 : diff < -180;
}

float getRotatedX(float currentX, float currentY, float pivotX, float pivotY, float angleDegrees) {
	float x = currentX - pivotX;
	float y = currentY - pivotY;
	float xr = (x * cosDeg(angleDegrees)) - (y * sinDeg(angleDegrees));
	return xr + pivotX;
}

float getRotatedY(float currentX, float currentY, float pivotX, float pivotY, float angleDegrees) {
	float x = currentX - pivotX;
	float y = currentY - pivotY;
	float yr = (x * sinDeg(angleDegrees)) + (y * cosDeg(angleDegrees));
	return yr + pivotY;
}

float getXAtEndOfRotatedLineByOrigin(float x, float lineLength, float angleDegrees) {
	return x + cosDeg(angleDegrees) * lineLength;
}

float getYAtEndOfRotatedLineByOrigin(float y, float lineLength, float angleDegrees) {
	return y + sinDeg(angleDegrees) * lineLength;
}

bool collides(float x1, float y1, float radius1, float x2, float y2, float radius2) {
	float d = distance(x1, y1, x2, y2);

	d -= radius1 + radius2;

	return d < 0;
}

std::string readFileContents(std::string file) {
	std::ifstream is(file.c_str());
	std::string contents;
	char c;

	if(is.good()) {
		while(!is.eof()) {
			c = is.get();
			if(is.good()) {
				contents += c;
			}
		}

		is.close();
	}

	return contents;
}

}

}

#endif