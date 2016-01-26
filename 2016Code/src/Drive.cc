/*
    Copyright (C) 2015, 2016 "Jadon Belezos" "Lance Booth" "Kira Corbet" "Caleb Reister" "Nathan Walker"

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

Drive::Drive(int leftPort, int rightPort/*, float defaultSpeed = .5*/) :
    left(leftPort), right(rightPort)
{
	left.SetInverted(true);
}

void Drive::stop() {
	left.Set(0);
	right.Set(0);
}

void Drive::remoteDrive(float leftStick, float rightStick, bool boost) {

	float speedMult = .5;

	if (boost) {
		speedMult = .75;
	}

	//fabs(float) is the float version of fabs()
	if (fabs(leftStick * speedMult) > 0.2) //number accounts for dead zone
		left.Set(leftStick * speedMult);
	else
		left.Set(0);

	if (fabs(rightStick * speedMult) > 0.2) //number accounts for dead zone
		left.Set(rightStick * speedMult);
	else
		left.Set(0);
}
