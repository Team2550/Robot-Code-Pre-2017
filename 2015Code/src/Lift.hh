#ifndef SRC_LIFT_HH_
#define SRC_LIFT_HH_
#include <cstdint> //shortened type names
#include <cmath>
#include "WPILib.h"

class Lift {
private:
	VictorSP liftMotor;
	DigitalInput bottomSwitch;
	DigitalInput topSwitch;
	//LiftMode task;
	//LiftTask task;
public:
	Lift();
	void bottom(bool boost);
	void top(bool boost);
	void stop();
	void remoteLift(bool upButton, bool downButton, bool stopButton, bool boost);
};
#endif /* SRC_LIFT_HH_ */
