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
#include "2016Code.hh"

Robot::Robot()
    : driver(0), drive(0, 1)/*, launcher(1), launch(2, 3, 0, 1)*/ /*launching ports need revisions*/ {

}

Robot::~Robot() {
}

void Robot::RobotInit() {

	/*// create an image
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	//the camera name (ex "cam0") can be found through the roborio web interface
	imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
	}
	imaqError = IMAQdxConfigureGrab(session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
	}*/
}

void Robot::AutonomousInit() {

}

void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {
	//IMAQdxStartAcquisition(session);
}

void Robot::TeleopPeriodic() {
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),
						  driver.GetRawAxis(xbox::axis::rightY),
						  driver.GetRawButton(xbox::btn::rb));
    /*launch.remoteLaunch(launcher.GetRawButton(xbox::btn::y),
                        launcher.GetRawButton(xbox::btn::x),
                        launcher.GetRawButton(xbox::btn::b),
						launcher.GetRawButton(xbox::btn::lb),
						launcher.GetRawButton(xbox::btn::rb));*/

    // Image code
    // grab an image, draw the circle, and provide it for the camera server which will
    // in turn send it to the dashboard.
	/*IMAQdxGrab(session, frame, true, NULL);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
	}
	else
	{
		imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
		CameraServer::GetInstance()->SetImage(frame);
	}*/
}

void Robot::DisabledInit() {
	//IMAQdxStopAcquisition(session);
}

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot);

