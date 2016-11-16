#include "Drive.h"

#include <iostream>

Drive::Drive(int backLeftPort, int backRightPort, int frontLeftPort,
             int frontRightPort, float motorPowerMult) :
             backLeft(backLeftPort), backRight(backRightPort),
             frontLeft(frontLeftPort), frontRight(frontRightPort),
			 motorPower(motorPowerMult)
{
	backLeft.SetInverted(true);
	frontLeft.SetInverted(true);
}

void Drive::stop() {
	backLeft.Set(0);
	backRight.Set(0);
	frontLeft.Set(0);
	frontRight.Set(0);
}

void Drive::remoteDrive(float leftX, float leftY, float rightX, bool goForward, bool goBackward)
{
	/* back left: 500rpm
	 * back right: 800rpm
	 * front left:900rpm
	 * front right:700rpm
	 */
	if(goForward)
	{
		backLeft.Set(1);
		backRight.Set(1);
		frontLeft.Set(1);
		frontRight.Set(1);
		return;
	}
	if(goBackward)
	{
		backLeft.Set(-1);
		backRight.Set(-1);
		frontLeft.Set(-1);
		frontRight.Set(-1);
		return;
	}

	float backLeftPower = 0, backRightPower = 0,
	      frontLeftPower = 0, frontRightPower = 0;

	leftX = fabs(leftX) < 0.2 ? 0 : leftX / 2;
	leftY = fabs(leftY) < 0.2 ? 0 : -leftY / 2;
	rightX = fabs(rightX) < 0.2 ? 0 : rightX / 2;

	// Adjust values for strafing
	backLeftPower -= leftX;
	backRightPower += leftX;
	frontLeftPower += leftX;
	frontRightPower -= leftX;

	// Adjust values for normal (forwards and backwards) motion
	backLeftPower += leftY;
	backRightPower += leftY;
	frontLeftPower += leftY;
	frontRightPower += leftY;

	// Adjust values for rotation
	backLeftPower += rightX;
	backRightPower -= rightX;
	frontLeftPower += rightX;
	frontRightPower -= rightX;

	//std::cout << leftX << ' ' << leftY << ' ' << rightX << std::endl;
	//static int count = 0;
	//if(count++ % 1000 == 0)
	//	std::cout << backLeftPower << ' ' << backRightPower << ' ' << frontLeftPower << ' ' << frontRightPower;

	backLeft.Set(backLeftPower * motorPower * 2); // Because it's a victor 888
	backRight.Set(backRightPower * motorPower);
	frontLeft.Set(frontLeftPower * motorPower);
	frontRight.Set(frontRightPower * motorPower);


	// Code for Calibration
	/*if(leftY > 0.2)
	{
		backLeft.Set(leftY);
		backRight.Set(leftY);
		frontLeft.Set(leftY);
		frontRight.Set(leftY);
	}
	else if(leftY < -0.2)
	{
		backLeft.Set(leftY);
		backRight.Set(leftY);
		frontLeft.Set(leftY);
		frontRight.Set(leftY);
	}
	else
		stop();*/
}
