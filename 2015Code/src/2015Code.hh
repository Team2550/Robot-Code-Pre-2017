#ifndef SRC_2015CODE_HH_
#define SRC_2015CODE_HH_

#include "WPILib.h"

class Robot: public IterativeRobot {
private:
	LiveWindow *lw;
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif /* SRC_2015CODE_HH_ */
