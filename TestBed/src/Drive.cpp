#include "Drive.h"

Drive::Drive(int backLeftPort, int backRightPort, int frontLeftPort,
             int frontRightPort) :
             backLeft(backLeftPort), backRight(backRightPort),
             frontLeft(frontLeftPort), frontRight(frontRightPort)
{
	backRight.SetInverted(true);
	frontRight.SetInverted(true);
}

void Drive::stop() {
	backLeft.Set(0);
	backRight.Set(0);
	frontLeft.Set(0);
	frontRight.Set(0);
}

void Drive::remoteDrive(float leftX, float leftY, float rightX)
{
	/*float backLeftPower = 0, backRightPower = 0,
	      frontLeftPower = 0, frontRightPower = 0;

	leftX = fabs(leftX) < 0.2 ? 0 : leftX;
	leftY = fabs(leftY) < 0.2 ? 0 : leftY;

	backLeft.Set(backLeftPower);
	backRight.Set(backRightPower);
	frontLeft.Set(frontLeftPower);
	frontRight.Set(frontRightPower);*/

	if(leftY > 0.2)
	{
		backLeft.Set(-.5);
		backRight.Set(-.5);
		frontLeft.Set(-.5);
		frontRight.Set(-.5);
	}
	else if(leftY < 0.2)
	{
		backLeft.Set(.5);
		backRight.Set(.5);
		frontLeft.Set(.5);
		frontRight.Set(.5);
	}
	else
		stop();
}
