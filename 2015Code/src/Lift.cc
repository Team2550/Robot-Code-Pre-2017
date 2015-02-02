#include "Lift.hh"

Lift::Lift() : liftMotor(2) { //We may need to change this number
	liftMotor.SetPositionMode(CANJaguar::QuadEncoder, 256, 0, 0, 0);
	//0,0,0 disables PID control
	//Consider making 256 1 so that we don't have to deal with floating point values
	
	/* Instead of setPositionMode, use setPercentMode configured with an encoder.
	   See http://first.wpi.edu/FRC/roborio/release/docs/cpp/classCANJaguar.html#ab6a9023e64d35c639c366401c1c7be12
	   Percent mode is just like running a PWM motor, but we can also read the
	   encoder and check the limit switches via CAN.
	*/
	//PercentMode constructor
	//liftMotor.SetPercentMode(CanJaguar::QuadEncoder, 256);
	
	/* double CANJaguar::GetPosition,
	   bool CANJaguar::GetForwardLimitOK, and
	   bool CANJaguar::GetReverseLimitOK 
	   will be useful later on.
	*/
	
	liftMotor.EnableControl(); //Maybe you should have an enable/disable method
	    //for the whole lift.
	    
	/* We will need to mess with the robot some to figure out how to determine
	   an initial position. I'm not sure if it is better to move the lift to its
	   upper and lower limits first or to make sure that team mebers place it in
	   a known position every time (most likely at the bottom.
	*/

	distanceRemaining = 0;
	done = true;
}

void Lift::bottom() {
	liftMotor.Set(0); //This may not work, I think we need to manually
	//manage the encoder. It is going to run for multiple rotations.
	
}

void Lift::top() {
    /*
    if not at top
        move lift up
        done = false;
    else
        stop motor
        done = true;
    update position (if necessary, we need to experiment)
    */
    //We will probably need to tweak exactly how we manage the done member.
    //In order to protect the hardware, maybe we should not allow the lift to
    //change tasks in the middle of something.
}

double Lift::getPosition() {
	return liftMotor.GetPosition();
}

void Lift::setPosition(double dist) {
	liftMotor.Set(dist);
	//should move the lift motor # of ticks, stops count if limit switch is pressed
	
	/*
	    while (moved < dist && limit switch not pressed)
	        move motor
	        update currentPosition
	    stop motor
	*/
}

//Replace up and down with single move function accepting +-1 which determines
//speed and direction
void Lift::up() {
    //rewrite
	liftMotor.Set(liftMotor.GetPosition() + .1);
}

void Lift::down() {
	liftMotor.Set(liftMotor.GetPosition() - .1);
}

void Lift::goTo(int boxes) { //rename to moveTo
    //We should create a version of this function that accepts the number of
    //ticks from the bottom to move to.
    
    //The box level version may be slightly more complicated, here I will write
    //pcode for the move to position version.
	/*
	distRemaining = (current position) - final position
	if distRemaining == 0 //this will create issues with a float
	    stop
	    done = true
	else if (dist remainging < 0)
	    move down
	    done = false
    else
        move up
        done = false
	*/
}

void Lift::remoteLift(float leftStick, bool leftButton, bool rightButton) {
    //buttons should not be called left/right, they should be called
    //up/downButton
	if(leftStick < -.2)
		up();
	else if(leftStick > .2)
		down();
	else if(leftButton == 1)
		bottom();
	else if(rightButton == 1) {
		top();
	}
}

/*
 * This function is meant to check and update the lift encoder value.
 * In order to multi-task, the lift has to be updated each time the entire
 * IterativeRobot::TeleopPeriodic runs. If control were to be passed to this class
 * whenever the lift was supposed to move to a position, the robot would either stop
 * driving or drive continuously, depending on what the drivers were doing when they
 * pushed the lift button.
 */
void Lift::update() {

}

