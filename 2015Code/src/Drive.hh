#ifndef DRIVE_H
#define DRIVE_H
#include <math.h>
#include "WPILib.h"

class Drive {
private:
	Victor left;
	Victor right;
	float speedMult; //speed multiplier
public:
	Drive();
	Drive(int leftPort, int rightPort, float defaultSpeed);
	void move(float leftSpeed, float rightSpeed);
	void remoteDrive(float leftStick, float rightStick, bool boost);
	void stop();
	float getSpeedMult();
};

#endif





