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
#ifndef DRIVE_H
#define DRIVE_H
#include <math.h>
#include "WPILib.h"

class Drive {
private:
	Talon left;
	Talon right;
	float currentSpeedR;
	float currentSpeedL;
    float currentGoalR;
    float currentGoalL;
	bool brakeOn;
public:
	Drive(int leftPort, int rightPort/*, float defaultSpeed*/);
	void remoteDrive(float leftStick, float rightStick, bool boost, bool brake, bool quick, float accel = 0.2);
	void stop();
};

#endif

