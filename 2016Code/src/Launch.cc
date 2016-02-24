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
#include "Launch.hh"

Launch::Launch(int leftLauncherPort, int rightLauncherPort, int rotatePort,
		       int topLauncherSwitchPort, int bottomLauncherSwitchPort, int pushPortA, int pushPortB)
			   :
               left(leftLauncherPort), right(rightLauncherPort),
			   tilt(rotatePort),
	           topLaunchSwitch(topLauncherSwitchPort),
			   bottomLaunchSwitch(bottomLauncherSwitchPort),
			   pushA(pushPortA), pushB(pushPortB)

			   // pushA = port #6
			   // pushB = port #7

{
	launchPause.Reset();
	launching = false;
}

Launch::~Launch()
{

}

void Launch::feedIntake()
{
    left.Set(-.25);
    right.Set(-.25);
    pushA.Set(0.95); // Value needs to be changed
    pushB.Set(0.0526);
}

void Launch::feedStop()
{
    left.Set(0);
    right.Set(0);
    pushA.Set(0.95);
    pushB.Set(0.0526);
}

void Launch::feedLaunch()
{
	if (!launching) {
		launchPause.Reset();
		launchPause.Start();
	}
    left.Set(1.0);
    right.Set(1.0);
    if (launchPause.Get() > 0.3) {
    	pushA.Set(0.65);
    	pushB.Set(0.3527);
    } else {
        pushA.Set(0.95);
        pushB.Set(0.0527);
    }
    // Add more things here e.g. something to push
    // the lauched item into the wheels after a
    // period of time
}

void Launch::remoteLaunch(bool launch, bool intake,
						  bool upButton, bool downButton, bool turtleButton)
{
    if(launch) {
        feedLaunch();
    	launching = true;
    } else if(intake) {
        feedIntake();
    	launching = false;
		launchPause.Stop();
    } else {
        feedStop();
        launching = false;
		launchPause.Stop();
    }

    if (turtleButton) {
    	turtle();
    } else {
		// rotation control
		if(upButton)
			rotateTheLauncherUp();
		else if(downButton)
			rotateTheLauncherDown();
		else
			stopRotate();
    }
}

void Launch::turtle()
{
    if (topLaunchSwitch.Get()) {
    	stopRotate();
    } else
    	tilt.Set(0.5);
}

void Launch::rotateTheLauncherUp()
{ // note to self: rotating might be backwards.

    if (topLaunchSwitch.Get())
    	stopRotate();
    else
    	tilt.Set(0.5);

}
void Launch::rotateTheLauncherDown()
{
    if (bottomLaunchSwitch.Get())
    	stopRotate();
    else
    	tilt.Set(-0.5);

}
void Launch::stopRotate()
{
    tilt.Set(0);
}
