#ifndef SRC_2015CODE_HH_
#define SRC_2015CODE_HH_

#include "WPILib.h"
#include "Drive.hh"
#include "xBox.hh"
#include "Lift.hh"

class Robot : public IterativeRobot {
private:
	LiveWindow *lw;
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
	void TestPeriodic();
};

#endif /* SRC_2015CODE_HH_ */