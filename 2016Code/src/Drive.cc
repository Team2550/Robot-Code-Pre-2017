/*
    Copyright (C) 2015, 2016 "Jadon Belezos" "Lance Booth" "Kira Corbett" "Caleb Reister" "Nathan Walker"

    This file is a part of the Team 2500 Robot Code.

    The Team 2500 Robot Code program is free software: you can redistribute it and/or modify
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

Drive::Drive(int leftPort, int rightPort, float normalSpeed, float boostSpeed, float slowSpeed) :
    left(leftPort), right(rightPort)
{
	left.SetInverted(true);
	this->normalSpeed = normalSpeed;
	this->boostSpeed = boostSpeed;
	this->slowSpeed = slowSpeed;
	speedMult = normalSpeed;
}

void Drive::stop() {
	left.Set(0);
	right.Set(0);
}

void Drive::remoteDrive(float leftStick, float rightStick, bool boost, bool autoPortcullis,
						float slowTurn) {
	if (autoPortcullis) {
		driveForward(0.6);
	} else {
		speedMult = normalSpeed;

		if (boost) {
			speedMult = boostSpeed;
		}

		float power = 0;
		if (fabs(leftStick) > 0.2) //number accounts for dead zone
			power += leftStick * speedMult;
		power -= slowTurn * slowSpeed;

		left.Set(power);

		power = 0;
		if (fabs(rightStick) > 0.2) //number accounts for dead zone
			power += rightStick * speedMult;
		power += slowTurn * slowSpeed;

		right.Set(power);
	}
}

void Drive::driveForward(float speed) { //sets motors to certain drive speed
    left.Set(speed * normalSpeed);
    right.Set(speed * normalSpeed);
}
