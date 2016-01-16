#include "Drive.hh"

Drive::Drive(int leftPort, int rightPort/*, float defaultSpeed = .5*/) :
    left(leftPort), right(rightPort)
{
    currentSpeedR = 0;
    currentSpeedL = 0;
    currentGoalR = 0;
    currentGoalL = 0;
    brakeOn = false;
}

void Drive::stop() {
	left.Set(0);
	right.Set(0);
}

float getSpeedNeed(float current, float controlVal, float accel, float speedMult) { // Calculates needed motor power for smooth acceleration
	float goal;
	if (fabs(controlVal) > 0.2) //number accounts for dead zone
		goal = controlVal * speedMult;
	else
		goal = 0;

	float dif = goal - current;
	if (fabs(dif) < accel) {
		return goal;
	} else {
		return current + (accel * (dif/fabs(dif)));
	}
}

void Drive::remoteDrive(float leftStick, float rightStick, bool boost, bool brake, bool quick, float accel) {

	float speedMult = .5;
	//speed limiting
	if (boost) {
		speedMult = .75;
	} else if (brake && brakeOn) {
		speedMult = .35;
	}

	//fabs(float) is the float version of abs()
	if (quick) {
		currentSpeedL = leftStick * speedMult;
		currentSpeedR = rightStick * speedMult;
	} else {
		currentSpeedL = getSpeedNeed(currentSpeedL, leftStick, accel, speedMult);
		currentSpeedR = getSpeedNeed(currentSpeedR, rightStick, accel, speedMult);
	}

	if (brake && !brakeOn) {
		currentSpeedL = 0;
		currentSpeedR = 0;

		brakeOn = true;
	} else if (!brake) {
		brakeOn = false;
	}

	left.Set(-currentSpeedL);
	right.Set(currentSpeedR);
}
