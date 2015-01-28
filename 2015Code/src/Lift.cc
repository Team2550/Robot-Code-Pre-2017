#include "Lift.hh"

Lift::Lift() : liftMotor(2) { //We will probably need to change this numbers
	liftMotor.SetPositionMode(CANJaguar::QuadEncoder, 256, 0, 0, 0);
	//0,0,0 disables PID control
	//Consider making 256 1 so that we don't have to deal with floating point values
	
	liftMotor.EnableControl(); //Maybe we should have an enable/disable method
	    //for the whole lift.

	distanceRemaining = 0;
	done = true;
}

void Lift::bottom() {
	liftMotor.Set(0); //This may not work, I think we need to manually
	//manage the encoder. It is going to run for multiple rotations.
	
	/*
	    while (bottom limit switch is not pressed)
	        move lift down
	    stop motor
	*/
}

void Lift::top() {
	//to be written
}

double Lift::getPosition() {
	return liftMotor.GetPosition(); //this will return the currentPosition member.
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

void Lift::up() {
	liftMotor.Set(liftMotor.GetPosition() + .1);
}

void Lift::down() {
	liftMotor.Set(liftMotor.GetPosition() - .1);
}

void Lift::goTo(int boxes) {
	//also to be written
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

