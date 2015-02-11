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

/*struct LiftTask {
    LiftMode current;
    uint8_t position, goal;
    float speed;
};*/

class Lift {
private:
	CANJaguar liftMotor;
	LiftMode task;
	//LiftTask task;
public:
	Lift();
	const LiftTask bottom();
	const LiftTask top();
	double getPosition();
	const LiftTask setPosition(double pos, float speed);
	const LiftTask setPosition(int boxLevel);
	void move(float speed);
	const LiftTask moveDist(int dist, float speed);
	void stop();
	void remoteLift(float stick, bool upButton, bool downButton, bool stopButton);
	const LiftTask update();
	//End-user of class should not be able to change a task without stopping
	//the currently running one first.
	//All move members should make sure they are not interrupting a task
};
#endif /* SRC_LIFT_HH_ */
