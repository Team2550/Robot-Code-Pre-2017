#include "Drive.hh"

Drive::Drive(int leftPort, int rightPort, float defaultSpeed = .5) :
    left(leftPort), right(rightPort)
{
    speedMult = defaultSpeed;
}

void Drive::stop() {
	left.Set(0);
	right.Set(0);
}

void Drive::remoteDrive(float leftStick, float rightStick, bool boost) {
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
	{
		speedMult = .75;
	}
	else
	{
		speedMult = .5;
	}
}
