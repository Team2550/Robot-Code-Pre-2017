#include "2015Code.hh"

Robot::Robot() : driver(0), liftControl(1), drive(0, 1, 0.5), lift() {

}

Robot::~Robot() {
}

void Robot::RobotInit() {
}

void Robot::AutonomousInit() {
	Timer currentTime;
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
	while(currentTime.Get() < 2.8) { //Use 2.5 for no bump, and 2.8(experimental) for bump
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
	currentTime.Stop();
}

void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),
					  driver.GetRawAxis(xbox::axis::rightY),
					  driver.GetRawButton(xbox::btn::rb));
	lift.remoteLift(liftControl.GetRawButton(xbox::btn::rb),
					liftControl.GetRawButton(xbox::btn::lb),
					liftControl.GetRawButton(xbox::btn::a),
					liftControl.GetRawButton(xbox::btn::y));
	//Lift motor ~4-6A when on stall, ~23-28A when running.
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot);

