#ifndef DRIVE_H
#define DRIVE_H
#include <math.h>
#include "WPILib.h"

class Drive {
private:
	Victor left;
	Victor right;
	float speedMult;
	float currentSpeedR;
	float currentSpeedL;
    float currentGoalR;
    float currentGoalL;
	bool braked;
public:
	Drive(int leftPort, int rightPort, float defaultSpeed);
	void remoteDrive(float leftStick, float rightStick, bool boost, bool brake, float accelDiv);
	void stop();
};

#endif





