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
#ifndef LAUNCH_H_INCLUDED
#define LAUNCH_H_INCLUDED
#include <math.h>
#include "WPILib.h"
/*#include "MaxSonarI2C.hh"*/

class Launch
{
private:
    VictorSP left;
    VictorSP right;
    TalonSRX tilt;
    DigitalInput topLaunchSwitch;
    DigitalInput bottomLaunchSwitch;
    Servo pushA;
    Servo pushB;
    Servo cameraMount;
    /*MaxSonarI2C ultra;*/
    float distance;
    float targetHeight;
    bool launching;
    Timer launchPause;
    float top;
    float bottom;

public:
    Launch(int leftLauncherPort, int rightLauncherPort,
    	   int rotatePort, int topLauncherSwitchPort,
		   int bottomLauncherSwitchPort,
		   int pushPortA, int pushPortB, int cameraMountPort,
		   float topAngle, float bottomAngle);
    ~Launch(); // Lift does not use limit switches! Encoder
    void feedIntake();
    void feedStop();
    void feedLaunch();
    void remoteLaunch(bool launch, bool intake,
    		          bool upButton, bool downButton,
					  bool turtleButton, bool autoPortcullis,
					  float cameraTilt);
    void rotateLauncherUp(float speed);
    void rotateLauncherDown(float speed);
    void stopRotate();
    void tiltCameraUp();
    void tiltCameraDown();
    void stopCamera();
};

#endif
