/*
    Copyright (C) 2016 "jadon belezos" "lance booth" "kira corbet" "caleb reister"

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
		}
	else {
		return current + (accel * (dif/fabs(dif)));
	}
}

void Drive::remoteDrive(float leftStick, float rightStick, bool boost, bool brake, bool quick, float accel) {

	float speedMult = .35;
	//speed limiting
	if (boost) {
		speedMult = .75;
	} else if (brake && brakeOn) {
		speedMult = .20;
	}

	//fabs(float) is the float version of fabs()
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
