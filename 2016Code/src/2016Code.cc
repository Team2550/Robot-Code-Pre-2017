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
#include "2016Code.hh"

Robot::Robot()
    : driver(0), drive(0, 1), launcher(1), launch(2, 3, 0, 1) /*launching ports need revisions*/ {

}

Robot::~Robot() {
}

void Robot::RobotInit() {

}

void Robot::AutonomousInit() {

}

void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),
						  driver.GetRawAxis(xbox::axis::rightY),
						  driver.GetRawButton(xbox::btn::rb));
    launch.remoteLaunch(launcher.GetRawButton(xbox::btn::y),
                        launcher.GetRawButton(xbox::btn::x),
                        launcher.GetRawButton(xbox::btn::b),
						launcher.GetRawButton(xbox::btn::lb),
						launcher.GetRawButton(xbox::btn::rb));
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot);

