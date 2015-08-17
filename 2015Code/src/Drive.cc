#include "Drive.hh"

Drive::Drive(int leftPort, int rightPort, float defaultSpeed = .5) :
    left(leftPort), right(rightPort)
{
    speedMult = defaultSpeed;
    currentSpeedR = 0;
    currentSpeedL = 0;
    currentGoalR = 0;
    currentGoalL = 0;
    braked = false;
}

void Drive::stop() {
	left.Set(0);
	right.Set(0);
}

void Drive::remoteDrive(float leftStick, float rightStick, bool boost, bool brake, float accelDiv = 2) {

	//speed limiting
	if (boost)
	{
		speedMult = .75;
	}
	else if (brake && braked)
	{
		speedMult = .25;
	}
	else
	{
		speedMult = .5;
	}

	//fabs(float) is the float version of abs()
	float goal;
	if (fabs(leftStick) > 0.2) //number accounts for dead zone
		goal = leftStick * speedMult;
	else
		goal = 0;
	currentSpeedL += (goal - currentSpeedL) / accelDiv;
	if (fabs(rightStick) > 0.2)
		goal = rightStick * speedMult;
	else
		goal = 0;
	currentSpeedR += (goal - currentSpeedR) / accelDiv;

	if (brake && !braked) {
		currentSpeedL = 0;
		currentSpeedR = 0;

		braked = true;
	}
	else if (!brake) {
		braked = false;
	}

	left.Set(currentSpeedL);
	right.Set(currentSpeedR);
}
