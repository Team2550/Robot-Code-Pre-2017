#ifndef SRC_2015CODE_HH_
#define SRC_2015CODE_HH_

#include <iostream> // I don't believe that is needed here -- if any source file needs it put it in that source file.
#include "WPILib.h"
#include "Drive.hh"
#include "xBox.hh"
#include "Lift.hh"
/*
        this is the main class that controls all of the mechanical 
        pieces of the robot.
        
     see Also: 
        drive
        lift 
        joystick 
 */ 
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

	//AxisCamera setup
	/*IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;
	AxisCamera *camera;
	Timer cameraTime; */

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
