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
	void bottom();
	void top();
	void stop();
	void remoteLift(float stick, bool upButton, bool downButton, bool stopButton);
};
#endif /* SRC_LIFT_HH_ */
