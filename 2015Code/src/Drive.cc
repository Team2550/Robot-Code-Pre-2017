#include "Drive.hh"

Drive::Drive() : left(0), right(1) {
	speedMult = .4;
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
		speedMult = 1;
	else
		speedMult = .4;
}

/*
 * FUNCTION: getSpeedMult
 * RETURN: speed multiplier of Drive object
 */
float Drive::getSpeedMult() {
	return speedMult;
}
