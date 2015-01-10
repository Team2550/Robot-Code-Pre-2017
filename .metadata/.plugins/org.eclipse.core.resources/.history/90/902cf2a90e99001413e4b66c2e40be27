#include "Drive.hh"

Drive::Drive()
{
	//motor creation
	left = new Jaguar(1);
	right = new Jaguar(2);
	speedMult = .65;
}
Drive::~Drive()
{
	delete left;
	delete right;
}

void Drive::move(float leftSpeed, float rightSpeed)
{
	left->Set(leftSpeed);
	right->Set(-rightSpeed);
}

/*
 * FUNCTION: stop
 * DESCRIPTION: stops all Drive motors
 */
void Drive::stop()
{
	left->Set(0);
	right->Set(0);
}

/*
 * FUNCTION: remoteDrive
 * AUTHOR: Caleb Reister
 * DESCRIPTION:
 * 	Handles movement based on joystick input.
 * 	Currently configured for xbox controllers.
 * PARAMETERS:
 * 	(I) stick - the joystick to use for input
 * 		pointed due to WPILib size
 */
void Drive::remoteDrive(float leftStick, float rightStick, bool boost)
{	
	//basic movements
	//fabs() is the float version of abs()
	if (fabs(leftStick) > 0.2)//number accounts for dead zone
		left->Set(-leftStick * speedMult);
	else
		left->Set(0);
	if (fabs(rightStick) > 0.2)
		right->Set(rightStick * speedMult);
	else
		right->Set(0);
	
	//speed limiting
	if (boost)
		speedMult = 1;
	else
		speedMult = .65;
}

/*
 * FUNCTION: getSpeedMult
 * RETURN: speed multiplier of Drive object
 */
float Drive::getSpeedMult()
{
	return speedMult;
}
