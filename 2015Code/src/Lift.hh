#ifndef SRC_LIFT_HH_
#define SRC_LIFT_HH_
#include <cstdint> //shortened type names
#include <cmath>
#include "WPILib.h"

/*enum LiftMode {
    BOTTOM,
    TOP,
    SET_POS,
    SET_BOX,
    MOVE_DIST,
    READY
};

struct LiftTask {
    LiftMode current;
    uint8_t position, goal;
    float speed;
};*/

class Lift {
private:
	Talon liftMotor;
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
