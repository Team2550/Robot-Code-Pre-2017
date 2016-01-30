#ifndef SRC_2015CODE_HH_
#define SRC_2015CODE_HH_

#include <iostream>
#include "WPILib.h"
#include "Drive.hh"
#include "xBox.hh"
#include "Lift.hh"

class Robot : public IterativeRobot {
private:
	//Drive & Lift setup
	Joystick driver;
	Joystick liftControl;
	Drive drive;
	Lift lift;

	//LED setup
	//Solenoid *WhiteLED;
	//Solenoid *RedLED;

	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;

public:
	Robot();
	~Robot();
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void DisabledInit();
	void DisabledPeriodic();
};

#endif /* SRC_2015CODE_HH_ */
