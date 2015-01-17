#include "2015Code.hh"

Robot::Robot() : driver(0) {
	lw = LiveWindow::GetInstance();
}

Robot::~Robot() {
}

void Robot::RobotInit() {
}

void Robot::AutonomousInit() {
	drive.move(1,1);
	Wait(1);
	drive.stop();

}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
	drive.remoteDrive(driver.GetRawAxis(1),
					  driver.GetRawAxis(5),
					  driver.GetRawButton(xbox::btn::rb));
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
