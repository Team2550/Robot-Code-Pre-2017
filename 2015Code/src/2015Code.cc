#include "2015Code.hh"

Robot::Robot() : driver(0), liftControl(1), drive(0, 1, 0.5), lift() {
	//creates solenoid objects for the LEDs
	//WhiteLED = new Solenoid(0);
	//RedLED = new Solenoid(1);

	// create an image
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
}

Robot::~Robot() {
}

void Robot::RobotInit() {


}

void Robot::AutonomousInit() {
	//LED code that blinks the LEDs at higher frequencies as autonamous time runs out. May or may not be used.
	/*for(int x = 0; x < 3; x++)
		{
			RedLED->Set(true);
			WhiteLED->Set(false);
			Wait(1);
			RedLED->Set(false);
			WhiteLED->Set(true);
			Wait(1);
		}
	for(int x = 0; x < 5; x++)
	{
		RedLED->Set(true);
		WhiteLED->Set(false);
		Wait(0.5);
		RedLED->Set(false);
		WhiteLED->Set(true);
		Wait(0.5);
	}
	for(int x = 0; x < 8; x++)
	{
		RedLED->Set(true);
		WhiteLED->Set(false);
		Wait(0.25);
		RedLED->Set(false);
		WhiteLED->Set(true);
		Wait(0.25);
	} */

	/*Timer currentTime;
	currentTime.Start();
	while(currentTime.Get() < 1.5) {
		lift.remoteLift(1, 0, 0, 0);
	}
	currentTime.Reset();
	while(currentTime.Get() < 1.1) {
		lift.remoteLift(0, 0, 1, 0);
		drive.remoteDrive(-.8, .8, 0);
	}
	currentTime.Reset();
	while(currentTime.Get() < 1.5) { //Use 2.5 for no bump, and 2.9 for bump
		drive.remoteDrive(.8, .85, 0);
	}
	currentTime.Reset();
	while(currentTime.Get() < .2) {
		drive.remoteDrive(0, 0, 0);
	}
	currentTime.Reset();
	while(currentTime.Get() < 1) {
		lift.remoteLift(0, 0, 0, 0);
	}
	currentTime.Stop();*/
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
    // create an image
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	//the camera name (ex "cam0") can be found through the roborio web interface
	imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
	}
	imaqError = IMAQdxConfigureGrab(session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
	}
    // acquire images
	IMAQdxStartAcquisition(session);
}

void Robot::TeleopPeriodic() {
	//calls drive & lift functions
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),
					  driver.GetRawAxis(xbox::axis::rightY),
					  driver.GetRawButton(xbox::btn::rb),
					  driver.GetRawButton(xbox::btn::lb),
					  10);
	lift.remoteLift(liftControl.GetRawButton(xbox::btn::rb),
					liftControl.GetRawButton(xbox::btn::lb),
					liftControl.GetRawButton(xbox::btn::a),
					liftControl.GetRawButton(xbox::btn::y));
	//Lift motor ~4-6A when on stall, ~23-28A when running.

    // grab an image, draw the circle, and provide it for the camera server which will
    // in turn send it to the dashboard.
	IMAQdxGrab(session, frame, true, NULL);
	if(imaqError != IMAQdxErrorSuccess)
	{
		DriverStation::ReportError("IMAQdxGrab error (haha, fail): " + std::to_string((long)imaqError) + "\n");
	}
	else
	{
		imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
		CameraServer::GetInstance()->SetImage(frame);
	}
}

void Robot::DisabledInit() {
    // stop image acquisition
	IMAQdxStopAcquisition(session);
}

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot);

