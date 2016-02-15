#include "2015Code.hh"

Robot::Robot() : driver(0), liftControl(1), drive(0, 1, 0.5), lift() {
	//creates solenoid objects for the LEDs
	//WhiteLED = new Solenoid(0);
	//RedLED = new Solenoid(1);
}

Robot::~Robot() {

}

void Robot::RobotInit() {


}

void Robot::AutonomousInit() {
	//LED code that blinks the LEDs at higher frequencies as autonomous time runs out. May or may not be used.
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


	SmartDashboard::PutString("DB/String 1", "The goal is 200 meters ahead.");
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot);

