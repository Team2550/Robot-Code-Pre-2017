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
	void move(float direction);
	void stop();
	void goTo(int boxes);
	void remoteLift(float axis, bool leftButton, bool rightButton);
	void update();
};




#endif /* SRC_LIFT_HH_ */
