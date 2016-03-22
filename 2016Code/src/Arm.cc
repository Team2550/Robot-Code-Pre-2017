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
#include <Arm.hh>

Arm::Arm(int armPort, int armEncoderPortA, int armEncoderPortB, float armUpSpeed, float armDownSpeed) :
           arm(armPort), armEncoder(armEncoderPortA, armEncoderPortB, false,
	        		       	   	   	   Encoder::EncodingType::k1X)
{
    armEncoder.SetMinRate(0);
    armEncoder.SetDistancePerPulse(1);
    armEncoder.SetSamplesToAverage(5);
    armEncoder.Reset();
    upSpeed = armUpSpeed;
    downSpeed = armDownSpeed;
    blink.Start();
}

Arm::~Arm()
{

}

void Arm::remoteArm(bool turtleButton, bool autoPortcullis, float armAxis)
{
    if (turtleButton)
    	armUp(0.75);
    else
    {
		// arm control
		if (autoPortcullis)
			armUp(0.15);
		else
		{
			if(armAxis > .2)
				armDown(armAxis * downSpeed);
			else if(armAxis < -0.2)
				armUp(-armAxis * upSpeed);
			else
				stopArm();
		}
    }

    if (!(armEncoder.Get() > -10.0)) {
    	SmartDashboard::PutBoolean("Arm Safe?", true);
    } else {
    	bool doBlink = round(blink.Get()) - floor(blink.Get()) < 0.5;
    	SmartDashboard::PutBoolean("Safe to rotate?", doBlink);
    }
	SmartDashboard::PutBoolean("Arm Safe?", armEncoder.Get() > -10.0);
	SmartDashboard::PutNumber("Arm Position", armEncoder.Get());
}

void Arm::armDown(double speed)
{
    if (armEncoder.Get() < -140.0) // Change angle // 360 degrees = 500 pulses
    	stopArm();
    else
    	arm.Set(-speed);
}

void Arm::armUp(double speed)
{
    if (armEncoder.Get() > 0.0) // Change angle
    	stopArm();
    else
    	arm.Set(speed);
}

void Arm::stopArm()
{
	arm.Set(0);
}
