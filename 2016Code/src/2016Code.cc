#include "2016Code.hh"

Robot::Robot()
    : driver(0), drive(0, 1), launcher(1), launch(2, 3) /*launching ports need revisions*/ {

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
<<<<<<< HEAD
    launch.remoteLaunch(launcher.getRawButton(xbox::btn::y),
                        launcher.getRawButton(xbox::btn::x),
                        launcher.getRawButton(xbox::btn::b));
=======
    launch.remoteLaunch(launcher.GetRawButton(xbox::btn::y),
                        launcher.GetRawButton(xbox::btn::x),
                        launcher.GetRawButton(xbox::btn::b));
>>>>>>> 442a3bca4f438649f4467f8c6cfc41b297d1dd04
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot);

