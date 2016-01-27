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
#include "Launch.hh"

Launch::Launch(int leftPort, int rightPort, int topPort, int bottomPort) :
    left(leftPort), right(rightPort), topSwitch(topPort), bottomSwitch(bottomPort), tilt(0)
{
    // One of the motors will have to be inverted;
    // I'm totally guessing as to which one.
    left.SetInverted(true);
}

Launch::~Launch()
{

}

void Launch::feedIntake()
{
    left.Set(-.25);
    right.Set(-.25);
}

void Launch::feedStop()
{
    left.Set(0);
    right.Set(0);
}

void Launch::feedLaunch()
{
    left.Set(1.0);
    right.Set(1.0);
    // Add more things here e.g. something to push
    // the lauched item into the wheels after a
    // period of time
}

void Launch::remoteLaunch(bool launch, bool intake, bool stop, bool upButton, bool downButton)
{
	// feed control
    if(stop)
        feedStop();
    else if(launch)
        feedLaunch();
    else if(intake)
        feedIntake();

    // motor control
    if(upButton)
    	rotateTheLauncherUp();
    else if(downButton)
    	rotateTheLauncherDown();
    else
    	stopRotate();
}

void Launch::rotateTheLauncherUp()
{ // note to self: rotating might be backwards.

    if (topSwitch.Get())
    	stopRotate();
    else
    	tilt.Set(Relay::Value::kReverse);

}
void Launch::rotateTheLauncherDown()
{
    if (bottomSwitch.Get())
    	stopRotate();
    else
    	tilt.Set(Relay::Value::kForward);

}
void Launch::stopRotate()
{
    tilt.Set(Relay::Value::kOff);
}
