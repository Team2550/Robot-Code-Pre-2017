#include "2016Code.hh"

Robot::Robot() : driver(0), drive(0, 1) {

}

Robot::~Robot() {
}

void Robot::RobotInit() {

}

void Robot::AutonomousInit() {
<<<<<<< HEAD

}

void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),
						  driver.GetRawAxis(xbox::axis::rightY),
						  driver.GetRawButton(xbox::btn::rb),
						  driver.GetRawButton(xbox::btn::lb),
						  driver.GetRawButton(xbox::btn::y),
						  0.1);
=======
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),
					  driver.GetRawAxis(xbox::axis::rightY),
					  driver.GetRawButton(xbox::btn::rb),
					  driver.GetRawButton(xbox::btn::lb),
					  0.2);
>>>>>>> origin/master
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot);

