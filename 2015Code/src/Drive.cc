#include "Drive.hh"

Drive::Drive() : left(0), right(1) {
	speedMult = .5;
}

Drive::Drive(int leftPort, int rightPort, float defaultSpeed = .5) :
    left(leftPort), right(rightPort)
{
    speedMult = defaultSpeed;
}

void Drive::move(float leftSpeed, float rightSpeed) {
	left.Set(leftSpeed);
	right.Set(-rightSpeed);
}

/*
 * FUNCTION: stop
 * DESCRIPTION: stops all Drive motors
 */
void Drive::stop() {
	left.Set(0);
	right.Set(0);
}

/*
 * FUNCTION: remoteDrive
 * AUTHOR: Caleb Reister
 * DESCRIPTION:
 * 	Handles movement based on joystick input.
 * 	Currently configured for xbox controllers.
 */
void Drive::remoteDrive(float leftStick, float rightStick, bool boost) {
	//basic movements
	//fabs(float) is the float version of abs()
	static int speedCounter2;
	static int speedCounter;
	if (fabs(leftStick) > 0.2) //number accounts for dead zone
		left.Set(-leftStick * speedMult);
	else
		left.Set(0);
	if (fabs(rightStick) > 0.2)
		right.Set(rightStick * speedMult);
	else
		right.Set(0);

	//speed limiting
	if (boost)
	{
		speedMult = .75;
	}
	else
	{
		speedCounter = 0;
		speedCounter2 = 0;
		speedMult = .5;
	}
}

/*
 * FUNCTION: getSpeedMult
 * RETURN: speed multiplier of Drive object
 */
float Drive::getSpeedMult() {
	return speedMult;
}
