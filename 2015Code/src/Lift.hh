#ifndef SRC_LIFT_HH_
#define SRC_LIFT_HH_
#include <cstdint> //shortened type names
#include <cmath>
#include "WPILib.h"

/*
    class: Lift 
    
    Desc: 
        lift class maintains the data required to operated the 
        lift and drives the lift up and down.
*/
class Lift {
private:
	Talon liftMotor;
	DigitalInput bottomSwitch;
	DigitalInput topSwitch;
	//LiftMode task; // why is this commented out.
	//LiftTask task;
public:
	Lift();
    // drive the lift downwards
	void bottom(bool boost);
    //drive the lift upwards
	void top(bool boost);
	void stop();
   //update the lift motor and make it move.
	void remoteLift(bool upButton, bool downButton, bool stopButton, bool boost);
};
#endif /* SRC_LIFT_HH_ */
