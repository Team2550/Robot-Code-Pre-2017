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

Robot::Robot() : driver(0), drive(0, 1), defaultNormalSpeed(0.4), defaultBoostSpeed(0.65),
                 launcher(1), launch(3, 4, 5, 2, 3, 6, 7, 8, 9, 90.0, 90.0, 2.0),
                 lift(2, 0, 1, 8, 9, 0.15)
{
}

Robot::~Robot()
{
}


void Robot::RobotInit()
{
	// If the dashboard class works as the documentation states, this next line should be meaningless. I'm
	// going to leave it in anyway...
	drive.setSpeeds(defaultNormalSpeed, defaultBoostSpeed);

	lw = LiveWindow::GetInstance();
	SmartDashboard::PutNumber("normalSpeed", defaultNormalSpeed);
	SmartDashboard::PutNumber("boostSpeed", defaultBoostSpeed);

	lw->Run();
}

void Robot::AutonomousInit()
{
    autoTime.Start();
    drive.driveForward(.25);

}

void Robot::AutonomousPeriodic()
{
    if(autoTime.HasPeriodPassed(2.0)) //in seconds
		drive.stop();
}

void Robot::TeleopInit()
{
	lw->Run();
	drive.setSpeeds(SmartDashboard::GetNumber("normalSpeed", defaultNormalSpeed),
	                SmartDashboard::GetNumber("boostSpeed", defaultBoostSpeed));
}

void Robot::TeleopPeriodic() {
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),      // Left Tank
					  driver.GetRawAxis(xbox::axis::rightY),     // Right Tank
					  driver.GetRawButton(xbox::btn::rb),        // Boost
					  driver.GetRawButton(xbox::btn::lb));       // Auto Portcullis

    launch.remoteLaunch(launcher.GetRawButton(xbox::btn::y),     // Launch
                        launcher.GetRawButton(xbox::btn::x),     // Intake
						launcher.GetRawButton(xbox::btn::rb),    // Launcher Up
						launcher.GetRawButton(xbox::btn::lb),    // Launcher Down
						driver.GetRawButton(xbox::btn::a),	     // Turtle
						driver.GetRawButton(xbox::btn::lb),      // Auto Portcullis
						launcher.GetRawAxis(xbox::axis::rightX), // Camera Gimble Yaw
						launcher.GetRawAxis(xbox::axis::rightY));// Camera Gimble Pitch

    lift.remoteLift(driver.GetRawButton(xbox::btn::a),		     // Turtle
					driver.GetRawButton(xbox::btn::lb),          // Auto Portcullis
					launcher.GetRawAxis(xbox::axis::leftY));     // Lifter
}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{

}

START_ROBOT_CLASS(Robot);

