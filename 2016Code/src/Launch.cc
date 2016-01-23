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
#include "Launch.hh"

Launch::Launch(int leftPort, int rightPort) :
    left(leftPort), right(rightPort)
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

void Launch::remoteLaunch(bool launch, bool intake, bool stop)
{
    if(stop)
        feedStop();
    else if(launch)
        feedLaunch();
    else if(intake)
        feedIntake();
}

void Launch::rotateTheLauncherUp()
{ // note to self: rotating might be backwards.
    relay.set(relay::value::kReverse);
}
void Launch::rotateTheLauncherDown()
{
    relay.set(relay::value::kForward);
}
void Launch::stopRotate()
{
    relay.set(relay::value::kOff);
}
