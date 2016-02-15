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
#ifndef LAUNCH_H_INCLUDED
#define LAUNCH_H_INCLUDED
#include "WPILib.h"

class Launch
{
private:
    VictorSP left;
    VictorSP right;
    VictorSP lift; // I have no idea about what kind of motor we'll use. This needs to be changed.
    DigitalInput topLaunchSwitch;
    DigitalInput bottomLaunchSwitch;
    DigitalInput topLiftSwitch;
    DigitalInput bottomLiftSwitch;
    Relay tilt;
public:
    Launch(int leftLauncherPort, int rightLauncherPort, int rotatePort, int liftPort, int topLauncherSwitchPort, int bottomLauncherSwitchPort, int topLiftSwitchPort, int bottomLiftSwitchPort);
    ~Launch();
    void feedIntake();
    void feedStop();
    void feedLaunch();
    void remoteLaunch(bool launch, bool intake, bool stop, bool upButton, bool downButton, float liftAxis);
    void rotateTheLauncherUp();
    void rotateTheLauncherDown();
    void stopRotate();
    void liftUp();
    void liftDown();
};

#endif
