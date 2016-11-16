/*
 * TestBed.h
 *
 *  Created on: Nov 8, 2016
 *      Author: 2550
 */

#ifndef SRC_TESTBED_H_
#define SRC_TESTBED_H_

#include "WPILib.h"
#include "Drive.h"
#include "Flag.h"
#include "xBox.h"

class Robot : public IterativeRobot {
private:
	//Drive setup
	Joystick driver;
	Drive drive;
	pneumaticFlag flag;
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

#endif /* SRC_TESTBED_H_ */
