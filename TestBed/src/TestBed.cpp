#include "WPILib.h"
#include "TestBed.h"

Robot::Robot() : driver(0), drive(1, 0, 2, 3)
{
}

Robot::~Robot()
{
}


void Robot::RobotInit()
{

}

void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{

}

void Robot::TeleopInit()
{

}

void Robot::TeleopPeriodic() {
	drive.remoteDrive(driver.GetRawAxis(xbox::axis::leftY),       // Left Stick
					  driver.GetRawAxis(xbox::axis::rightY));     // Right Stick
}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{

}

START_ROBOT_CLASS(Robot);
