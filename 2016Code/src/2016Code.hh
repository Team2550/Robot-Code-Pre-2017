#ifndef SRC_2016CODE_HH_
#define SRC_2016CODE_HH_

#include <iostream>
#include "WPILib.h"
#include "Drive.hh"
#include "xBox.hh"

class Robot : public IterativeRobot {
private:
	//Drive setup
	Joystick driver;
	Drive drive;

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

#endif /* SRC_2016CODE_HH_ */
