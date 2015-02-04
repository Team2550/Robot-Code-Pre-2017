#include "Lift.hh"

Lift::Lift() : liftMotor(2) { //We WILL need to change this number
	liftMotor.SetPercentMode(CANJaguar::QuadEncoder, 256);
	/* double CANJaguar::GetPosition,
	   bool CANJaguar::GetForwardLimitOK
	   bool CANJaguar::GetReverseLimitOK
	*/
	
	liftMotor.EnableControl();
	    
	/* We will need to mess with the robot some to figure out how to determine
	   an initial position. I'm not sure if it is better to move the lift to its
	   upper and lower limits first or to make sure that team members place it in
	   a known position each time (probably at the bottom.)
	*/

	distanceRemaining = 0;
	done = true;
}

void Lift::bottom() {
	if(!liftMotor.GetReverseLimitOK())
		{
			liftMotor.Set(-1);
		}
}

void Lift::top() {
	if(!liftMotor.GetForwardLimitOK())
	{
		liftMotor.Set(1);
	}
    //We will probably need to tweak exactly how we manage the done member.
    //In order to protect the hardware, maybe we should not allow the lift to
    //change tasks in the middle of something.
}

double Lift::getPosition() {
	return liftMotor.GetPosition();
}

void Lift::setPosition(double dist) {
	if(dist < getPosition())
		liftMotor.Set(1);
	else if(dist > getPosition())
		liftMotor.Set(-1);
	else
		liftMotor.Set(0);
}

//Replace up and down with single move function accepting +-1 which determines
//speed and direction
void Lift::move(float direction) {
    	liftMotor.Set(direction);
}

void Lift::stop()
{
	liftMotor.Set(0);
}

void Lift::goTo(int boxes) {
    
}

void Lift::remoteLift(float leftStick, bool leftButton, bool rightButton) {
    //buttons should not be called left/right, they should be called
    //up/downButton
    //leftStick should be changed to stick
	if(leftStick < -.2 and leftStick > .2)
		move(leftStick);
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
    //create an enum with the different actions that can't be finished in one cycle
    //call necessary functions based on what is not done. Accepts an argument that,
    //if false, will reset so that manual control can take over.
}

