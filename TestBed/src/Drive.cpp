#include "Drive.h"

#include <iostream>

Drive::Drive(int backLeftPort, int backRightPort, int frontLeftPort,
             int frontRightPort, float motorPowerMult) :
             backLeft(backLeftPort), backRight(backRightPort),
             frontLeft(frontLeftPort), frontRight(frontRightPort),
			 motorPower(motorPowerMult)
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
	/* back left: 500rpm
	 * back right: 800rpm
	 * front left:900rpm
	 * front right:700rpm
	 */
	float backLeftPower = 0, backRightPower = 0,
	      frontLeftPower = 0, frontRightPower = 0;

	leftX = fabs(leftX) < 0.2 ? 0 : leftX / 2;
	leftY = fabs(leftY) < 0.2 ? 0 : leftY / 2;
	rightX = fabs(rightX) < 0.2 ? 0 : rightX / 2;

	// Adjust values for strafing
	backLeftPower += leftX;
	backRightPower -= leftX;
	frontLeftPower -= leftX;
	frontRightPower += leftX;

	// Adjust values for normal (forwards and backwards) motion
	backLeftPower += leftY;
	backRightPower += leftY;
	frontLeftPower += leftY;
	frontRightPower += leftY;

	// Adjust values for rotation
	backLeftPower -= rightX;
	backRightPower += rightX;
	frontLeftPower -= rightX;
	frontRightPower += rightX;

	std::cout << leftX << ' ' << leftY << ' ' << rightX << std::endl;
	std::cout << backLeftPower << ' ' << backRightPower << ' ' << frontLeftPower << ' ' << frontRightPower;

	backLeft.Set(backLeftPower * motorPower);
	backRight.Set(backRightPower * motorPower);
	frontLeft.Set(frontLeftPower * motorPower);
	frontRight.Set(frontRightPower * motorPower);

	/*if(leftY > 0.2)
	{
		backLeft.Set(-.5);
		backRight.Set(-.5);
		frontLeft.Set(-.5);
		frontRight.Set(-.5);
	}
	else if(leftY < -0.2)
	{
		backLeft.Set(.5);
		backRight.Set(.5);
		frontLeft.Set(.5);
		frontRight.Set(.5);
	}
	else
		stop();*/
}
