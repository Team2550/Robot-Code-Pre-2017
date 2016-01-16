#ifndef DRIVE_H
#define DRIVE_H
#include <math.h>
#include "WPILib.h"

class Drive {
private:
	Talon left;
	Talon right;
	float currentSpeedR;
	float currentSpeedL;
    float currentGoalR;
    float currentGoalL;
	bool brakeOn;
public:
	Drive(int leftPort, int rightPort/*, float defaultSpeed*/);
	void remoteDrive(float leftStick, float rightStick, bool boost, bool brake, bool quick, float accel = 0.2);
	void stop();
};

#endif

