#ifndef SRC_LIFT_HH_
#define SRC_LIFT_HH_
#include "WPILib.h"

class Lift {
private:
	CANJaguar motor;
public:
	Lift();
	~Lift();
	void lowerLift();
	void raiseLift();
};




#endif /* SRC_LIFT_HH_ */
