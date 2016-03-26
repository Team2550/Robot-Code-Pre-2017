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
			   int pushPortA, int pushPortB, int cameraMountPort,
			   float topAngle, float bottomAngle)
			   :
               left(leftLauncherPort), right(rightLauncherPort),
			   tilt(rotatePort),
	           topLaunchSwitch(topLauncherSwitchPort),
			   bottomLaunchSwitch(bottomLauncherSwitchPort),
			   pushA(pushPortA), pushB(pushPortB),
			   cameraMount(cameraMountPort)

			   // pushA = port #6
			   // pushB = port #7

{
	launchPause.Reset();
	launching = false;
	targetHeight = 85;
	targetHeight *= targetHeight;
	distance = 0;
	top = topAngle;
	bottom = bottomAngle;
}

Launch::~Launch()
{

}

void Launch::feedIntake()
{
    left.Set(-0.65);
    right.Set(-0.65);
    pushA.Set(1); // Value needs to be changed
    pushB.Set(0.03);
}

void Launch::feedStop()
{
    left.Set(0);
    right.Set(0);
    pushA.Set(1);
    pushB.Set(0.03);
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
    if (launchPause.Get() > 0.5)
    {
    	pushA.Set(0.65);
    	pushB.Set(0.38);
    }
    else
    {
        pushA.Set(1);
        pushB.Set(0.03);
    }
    // Add more things here e.g. something to push
    // the lauched item into the wheels after a
    // period of time
}

void Launch::remoteLaunch(bool launch, bool intake, bool upButton, bool downButton,
						  bool turtleButton, bool autoPortcullis)
{
	//ultra.ping();

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
    	rotateLauncherUp(0.7);
    else
    {
    	if (autoPortcullis)
    		rotateLauncherDown(0.45);
    	else
    	{
			// rotation control
			if(upButton)
				rotateLauncherUp(0.7);
			else if(downButton)
				rotateLauncherDown(0.45);
			else
				stopRotate();
    	}
    }

	if (upButton) {
		tiltCameraUp();
	} else if (downButton) {
		tiltCameraDown();
	}
	std::cout << cameraMount.GetAngle() << '\n';
    //distance = ultra.getRange();
	//SmartDashboard::PutNumber("Horizontal Distance", distance);

	//if (distance > 0) {
	//	distance = sqrt(distance * distance + targetHeight); // Needs to take into account height of sensor and distance between target and wall
	//	SmartDashboard::PutNumber("Target Distance (Ultrasonic)", distance);
    //    SmartDashboard::PutBoolean("Ultrasonic Ready?", true);
    //} else {
    //    SmartDashboard::PutBoolean("Ultrasonic Ready?", false);
    //}
}

void Launch::tiltCameraUp()
{
	cameraMount.SetAngle(top);
	std::cout << cameraMount.GetAngle() << '\n';
}
void Launch::tiltCameraDown()
{
	cameraMount.SetAngle(bottom);
	std::cout << cameraMount.GetAngle() << '\n';
}

/*void Launch::tiltCamera() {
	camPitch += speed;

	if (camPitch > 90.0) {
		camPitch = 90.0;
	}
	if (camPitch < 0.0) {
		camPitch = 0.0;
	}
}*/


void Launch::rotateLauncherUp(float speed)
{ // note to self: rotating might be backwards.

    /*if (topLaunchSwitch.Get() && !SmartDashboard::GetBoolean("Ignore Limit Switches?", true))
    	stopRotate();
    else*/
    	tilt.Set(speed);

}
void Launch::rotateLauncherDown(float speed)
{
    /*if (bottomLaunchSwitch.Get() && !SmartDashboard::GetBoolean("Ignore Limit Switches?", true))
    	stopRotate();
    else*/
    	tilt.Set(-speed);

}
void Launch::stopRotate()
{
    tilt.Set(0);
}
