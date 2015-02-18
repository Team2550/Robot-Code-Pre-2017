#ifndef SRC_LIFT_HH_
#define SRC_LIFT_HH_
#include <cstdint> //shortened type names
#include <cmath>
#include "WPILib.h"

enum LiftMode {
    BOTTOM,
    TOP,
    SET_POS,
    SET_BOX,
    MOVE_DIST,
    READY
};

struct LiftTask {
    LiftMode mode;
    uint8_t position, goal;
    float speed;
};

class Lift {
private:
	CANJaguar liftMotor;
	LiftTask task;
public:
	Lift();
	Lift(uint8_t jagID, uint16_t encoderTicks);
	const LiftTask stop();
	const LiftTask bottom();
	const LiftTask top();
	const LiftTask moveDist(uint32_t dist);
	const LiftTask setPosition(uint32_t position);
	const LiftTask setBox(uint8_t boxLevel);
	const LiftTask remoteLift(float stick, bool upButton, bool downButton, bool stopButton);
};
#endif /* SRC_LIFT_HH_ */
