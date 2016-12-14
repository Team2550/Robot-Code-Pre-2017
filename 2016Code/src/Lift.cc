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
#include "Lift.hh"

Lift::Lift(int liftPort, int liftEncoderPortA, int liftEncoderPortB,
		   int topLimitSwitchPort, int bottomLimitSwitchPort, float liftSpeed) :
           lift(liftPort), liftEncoder(liftEncoderPortA, liftEncoderPortB, false,
	        		       	   	   	   Encoder::EncodingType::k4X),
		   topLimitSwitch(topLimitSwitchPort), bottomLimitSwitch(bottomLimitSwitchPort)
{
    //liftEncoder.SetMaxPeriod(50);
    liftEncoder.Reset();
    lSpeed = liftSpeed;
}

Lift::~Lift()
{

}

void Lift::remoteLift(bool turtleButton, bool autoPortcullis, float liftAxis)
{
	// feed control

    if (turtleButton)
    	liftUp(0.75);
    else
    {
		// lift control
		if (autoPortcullis)
			liftUp(0.15);
		else
		{
			if(liftAxis > .2)
				liftDown(liftAxis * lSpeed);
			else if(liftAxis < -0.2)
				liftUp(-liftAxis * lSpeed);
			else
				stopLift();
		}
    }

    if (topLimitSwitch.Get()) {
    	liftEncoder.Reset();
    }
	SmartDashboard::PutBoolean("Lift Arm", topLimitSwitch.Get());
}

void Lift::liftDown(double speed)
{
    if (liftEncoder.Get() < -140.0 || bottomLimitSwitch.Get()) // Change angle // 360 degrees = 500 pulses
    	stopLift();
    else
    	lift.Set(-speed);
}

void Lift::liftUp(double speed)
{
    if (liftEncoder.Get() > 0.0 || topLimitSwitch.Get()) // Change angle
    	stopLift();
    else
    	lift.Set(speed);
}

void Lift::stopLift()
{
	lift.Set(0);
}
