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
						  driver.GetRawButton(xbox::btn::rb),
						  driver.GetRawButton(xbox::btn::lb),
						  driver.GetRawButton(xbox::btn::y),
						  0.1);
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

