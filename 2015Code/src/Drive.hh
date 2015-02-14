#ifndef DRIVE_H
#define DRIVE_H
#include <math.h>
#include "WPILib.h"

class Drive {
private:
	Victor left;
	Victor right;
	float speedMult;
public:
	Drive(int leftPort, int rightPort, float defaultSpeed);
	void remoteDrive(float leftStick, float rightStick, bool boost);
	void stop();
};

#endif





