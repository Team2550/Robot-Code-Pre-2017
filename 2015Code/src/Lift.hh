#ifndef SRC_LIFT_HH_
#define SRC_LIFT_HH_
#include "WPILib.h"

class Lift {
private:
	CANJaguar liftMotor;
	//Add currentPosition here, it will keep track of exactly where the lift is
	//by counting encoder ticks.
	int distanceRemaining;
	bool done;
public:
	Lift();
	void bottom();
	void top();
	double getPosition();
	void setPosition(double dist);
	void up();
	void down();
	//add stop()
	void goTo(int boxes);
	void remoteLift(float axis, bool leftButton, bool rightButton);
	//What is leftButton and rightButton for?
	void update();
};




#endif /* SRC_LIFT_HH_ */
