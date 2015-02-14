#include "2015Code.hh"

Robot::Robot() : driver(0), liftControl(1), drive(0, 1, 0.4), forkLift() {

}

Robot::~Robot() {
}

void Robot::RobotInit() {
}

void Robot::AutonomousInit() {
	//forkLift.enable(true);
	forkLift.move(.5);
	Wait(.25);
	forkLift.stop();
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),
					  driver.GetRawAxis(xbox::axis::rightY),
					  driver.GetRawButton(xbox::btn::rb));
	forkLift.remoteLift(liftControl.GetRawAxis(xbox::axis::leftY),
						liftControl.GetRawButton(xbox::btn::rb),
						liftControl.GetRawButton(xbox::btn::lb),
						liftControl.GetRawButton(xbox::btn::a));
}

void Robot::DisabledInit() {
	std::cout << "DisabledInit has run.\n";
}

void Robot::DisabledPeriodic() {
	std::cout << forkLift.getPosition() << '\n';
}

START_ROBOT_CLASS(Robot);

