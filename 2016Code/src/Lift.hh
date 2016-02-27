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
#ifndef LIFT_H_INCLUDED
#define LIFT_H_INCLUDED
#include "WPILib.h"

class Lift
{
private:
    Victor lift; // I have no idea about what kind of motor we'll use. This needs to be changed.
    DigitalInput bottomSwitch;
    DigitalInput topSwitch;
    void liftUp(double speed);
    void liftDown(double speed);
    void stopLift();
public:
    Lift(int liftPort, int bottomSwitchPort, int topSwitchPort);
    ~Lift(); // Lift does not use limit switches! Encoder
    void remoteLift(bool turtleButton, bool autoPortcullis, float liftAxis);

};

#endif
