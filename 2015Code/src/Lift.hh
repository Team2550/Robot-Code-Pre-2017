#ifndef SRC_LIFT_HH_
#define SRC_LIFT_HH_
#include "WPILib.h"

class Lift {
private:
	CANJaguar liftMotor;
public:
	Lift();
	void bottom();
	void top();
	double getPosition();
	void setPosition(double dist);
	void up();
	void down();
	void goTo(int boxes);
	void remoteLift(float leftStick, bool leftButton, bool rightButton);
};




#endif /* SRC_LIFT_HH_ */
