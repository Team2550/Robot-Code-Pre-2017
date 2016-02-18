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

Robot::Robot()
    : driver(0), drive(0, 1), launcher(1), launch(2, 3, 4, 5, 0, 1, 2, 5) /*launching ports need revisions*/ {

}

Robot::~Robot() {
}
void Robot::RobotInit() {
}

void Robot::AutonomousInit() {
    autoTime.start();
    drive.DriveForRev(.25)
//nothing to initalize

}

void Robot::AutonomousPeriodic() {
    if(autoTime.hasPeriodPassed(2.0)); //in seconds
	drive.DriveForRev(0.0);
    //

}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),
						  driver.GetRawAxis(xbox::axis::rightY),
						  driver.GetRawButton(xbox::btn::rb));
	SmartDashboard::PutNumber(llvm::StringRef("ultrasonic_label"),(double)123.00);
    launch.remoteLaunch(launcher.GetRawButton(xbox::btn::y),
                        launcher.GetRawButton(xbox::btn::x),
                        launcher.GetRawButton(xbox::btn::b),
						launcher.GetRawButton(xbox::btn::lb),
						launcher.GetRawButton(xbox::btn::rb),
						launcher.GetRawAxis(xbox::axis::leftY),
						launcher.GetRawButton(xbox::btn::a));
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot);

