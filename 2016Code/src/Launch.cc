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
		       int topLauncherSwitchPort, int bottomLauncherSwitchPort,
			   int pushPortA, int pushPortB, int cameraMountYawPort, int cameraMountPitchPort,
			   float cameraStartPitch, float cameraSpeed)
			   :
               left(leftLauncherPort), right(rightLauncherPort),
			   tilt(rotatePort),
	           topLaunchSwitch(topLauncherSwitchPort),
			   bottomLaunchSwitch(bottomLauncherSwitchPort),
			   pushA(pushPortA), pushB(pushPortB),
			   cameraMountYaw(cameraMountYawPort), cameraMountPitch(cameraMountPitchPort)

			   // pushA = port #6
			   // pushB = port #7

{
	launchPause.Reset();
	launching = false;
	camPitch = cameraStartPitch;
	camSpeed = cameraSpeed;
}

Launch::~Launch()
{

}

void Launch::feedIntake()
{
    left.Set(-.5);
    right.Set(-.5);
    pushA.Set(0.95); // Value needs to be changed
    pushB.Set(0.08);
}

void Launch::feedStop()
{
    left.Set(0);
    right.Set(0);
    pushA.Set(0.95);
    pushB.Set(0.08);
}

void Launch::feedLaunch()
{
	if (!launching)
	{
		launchPause.Reset();
		launchPause.Start();
	}
    left.Set(1.0);
    right.Set(1.0);
    if (launchPause.Get() > 0.3)
    {
    	pushA.Set(0.65);
    	pushB.Set(0.38);
    }
    else
    {
        pushA.Set(0.95);
        pushB.Set(0.08);
    }
    // Add more things here e.g. something to push
    // the lauched item into the wheels after a
    // period of time
}

void Launch::remoteLaunch(bool launch, bool intake, bool upButton, bool downButton,
						  bool turtleButton, bool autoPortcullis, float cameraPitch)
{
    if(launch)
    {
        feedLaunch();
    	launching = true;
    }
    else if(intake)
    {
        feedIntake();
    	launching = false;
		launchPause.Stop();
    }
    else
    {
        feedStop();
        launching = false;
		launchPause.Stop();
    }

    if (turtleButton)
    	rotateLauncherUp();
    else
    {
    	if (autoPortcullis)
    		rotateLauncherDown();
    	else
    	{
			// rotation control
			if(upButton)
				rotateLauncherUp();
			else if(downButton)
				rotateLauncherDown();
			else
				stopRotate();
    	}
    }

    if (fabs(cameraPitch) > 0.2) {
    	tiltCamera(cameraPitch * camSpeed);
    }

    cameraMountYaw.SetAngle(105.0); // Remove before competition
    cameraMountPitch.SetAngle(camPitch);
    SmartDashboard::PutNumber("Camera Pitch", camPitch);
}

void Launch::rotateLauncherUp()
{ // note to self: rotating might be backwards.

    if (topLaunchSwitch.Get())
    	stopRotate();
    else
    	tilt.Set(0.6);

}
void Launch::rotateLauncherDown()
{
    if (bottomLaunchSwitch.Get())
    	stopRotate();
    else
    	tilt.Set(-0.45);

}
void Launch::stopRotate()
{
    tilt.Set(0);
}

void Launch::tiltCamera(float speed) {
	camPitch += speed;

	if (camPitch > 160.0) {
		camPitch = 160.0;
	}
	if (camPitch < 75.0) {
		camPitch = 75.0;
	}
}
