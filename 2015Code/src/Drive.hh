#ifndef DRIVE_H
#define DRIVE_H
#include <math.h>
#include "WPILib.h"

/*
    class:Drive
     
    Desc:
        controls the driving speed of the robot
        as well maintains info on how fast the robot has currently moved.        
*/
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
    // setup all info for the drive object to drive the robot.
	Drive(int leftPort, int rightPort, float defaultSpeed);
    // update the speed of the robot through this method.
	void remoteDrive(float leftStick, float rightStick, bool boost, bool brake, float accelDiv);
	void stop();
};

#endif





