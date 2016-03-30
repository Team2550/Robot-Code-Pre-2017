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
#include "2016Code.hh"

double periods[] = {1.9, 1.5, 0.55, 0.55, 0.5, 0.8, 1.5};
Robot::Robot() : driver(0), drive(0, 1, 0.6, 0.85, 0.3), launcher(1),
				 launch(3, 4, 5, 2, 3, 6, 7, 9, 96.0, 65.0), arm(2, 0, 1, 1.0, 0.5), lift(9, 1.0),
				 sequence(periods, 7)
{
}

Robot::~Robot()
{
}


void Robot::RobotInit()
{
    //SmartDashboard::PutBoolean("Ignore Limit Switches?", false);
    SmartDashboard::PutBoolean("Ultrasonic Ready?", false);
    SmartDashboard::PutNumber("Arm Position", 0);
}

void Robot::AutonomousInit()
{
    autoTime.Start();
    autoTime.Reset();
}

void Robot::AutonomousPeriodic()
{
	/*switch ( seq.per(autoTime, periods) )*/
	if (autoTime.Get() < 1.9) {
	    drive.driveForward(0.9);

	    launch.rotateLauncherDown(0.9);

	} else if (autoTime.Get() < 3.4) {
		launch.rotateLauncherUp(1.0);
	} else if (autoTime.Get() < 3.95) {
		drive.stop();

	} else if (autoTime.Get() < 4.5) {
		drive.turn(1);
		launch.stopRotate();

	} else if(autoTime.Get() < 5) {
		drive.stop();

	} else if(autoTime.Get() < 5.8) {
		drive.driveForward(0.9);

	} else if(autoTime.Get() < 7.3) {
		drive.stop();

		launch.feedLaunch();

	} else {
		launch.feedStop();

	}

}

void Robot::TeleopInit()
{

}

void Robot::TeleopPeriodic() {
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),      // Left Tank
					  driver.GetRawAxis(xbox::axis::rightY),     // Right Tank
					  driver.GetRawButton(xbox::btn::rb),        // Boost
					  driver.GetRawButton(xbox::btn::lb),		 // Brake
					  driver.GetRawAxis(xbox::axis::RT)-		 // Slow Turn
					  driver.GetRawAxis(xbox::axis::LT));

    launch.remoteLaunch(launcher.GetRawButton(xbox::btn::y),     // Launch
                        launcher.GetRawButton(xbox::btn::x),     // Intake
						launcher.GetRawButton(xbox::btn::lb),    // Launcher Up
						launcher.GetRawButton(xbox::btn::rb),    // Launcher Down
						driver.GetRawButton(xbox::btn::b));	     // Turtle

    arm.remoteArm(driver.GetRawButton(xbox::btn::b),		     // Turtle
				  launcher.GetRawAxis(xbox::axis::leftY));       // Arm

    lift.remoteLift(driver.GetRawButton(xbox::btn::x),			 // In
    				driver.GetRawButton(xbox::btn::y));			 // Out
}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{

}

START_ROBOT_CLASS(Robot);

