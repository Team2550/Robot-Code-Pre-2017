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
#include "Lift.hh"

Lift::Lift(int liftPort, int liftEncoderPortA, int liftEncoderPortB) :
           lift(liftPort), liftEncoder(liftEncoderPortA, liftEncoderPortB, false,
	        		       	   	   	   Encoder::EncodingType::k4X)
{
    //liftEncoder.SetMaxPeriod(50);
    liftEncoder.SetMinRate(0);
    liftEncoder.SetDistancePerPulse(360/7.0);
    liftEncoder.SetSamplesToAverage(7);
    liftEncoder.Reset();
    // Put encoder setup here
}

Lift::~Lift()
{

}

void Lift::remoteLift(bool turtleButton, bool autoPortcullis, float liftAxis)
{
	std::cout << liftEncoder.GetDistance() << '\n';
	// feed control

    if (turtleButton)
    	turtle();
    else
    {
		// lift control
		if (autoPortcullis)
			liftUp(0.15);
		else
		{
			if(liftAxis > .2)
				liftUp(0.15);
			else if(liftAxis < -0.2)
				liftDown(0.15);
			else
				stopLift();
		}
    }
    SmartDashboard::PutNumber("Encoder", liftEncoder.GetDistance());
}

void Lift::turtle()
{
    if (liftEncoder.GetDistance() > 45.0) { // Change angle
    	stopLift();
    } else
    	lift.Set(0.75);
}

void Lift::liftUp(double speed)
{
    if (liftEncoder.GetDistance() > 45.0) // Change angle
    	stopLift();
    else
    	lift.Set(speed);
}

void Lift::liftDown(double speed)
{
    if (liftEncoder.GetDistance() < 0) // Change angle
    	stopLift();
    else
    	lift.Set(-speed);
}

void Lift::stopLift()
{
	lift.Set(0);
}
