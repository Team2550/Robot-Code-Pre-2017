#include "Lift.hh"

Lift::Lift() : liftMotor(1) { //1 is the board id of the jaguar
	liftMotor.SetPercentMode(CANJaguar::QuadEncoder, 1);
	liftMotor.SetSafetyEnabled(false);
	/* double CANJaguar::GetPosition,
	   bool CANJaguar::GetForwardLimitOK
	   bool CANJaguar::GetReverseLimitOK
	*/

	/* We will need to mess with the robot some to figure out how to determine
	   an initial position. I'm not sure if it is better to move the lift to its
	   upper and lower limits first or to make sure that team members place it in
	   a known position each time (probably at the bottom.)
	*/
}

const LiftTask Lift::bottom() {
	if(!liftMotor.GetReverseLimitOK()) //Good.
	{
		liftMotor.Set(-1);
	}
	//Note: we don't know which direction is up and down yet.
}

const LiftTask Lift::top() {
	if(!liftMotor.GetForwardLimitOK())
	{
		liftMotor.Set(1);
	}
    //We will probably need to tweak exactly how we manage the done member.
    //In order to protect the hardware, it should not allow the lift to
    //change tasks in the middle of something.
}

double Lift::getPosition() {
	return liftMotor.GetPosition();
	//Works for now, but it may be useful to return an absolute position
	//(from the top or bottom).
}

const LiftTask Lift::setPosition(double pos, float speed) {
	speed = fabs(speed);
	if(pos < getPosition())
		liftMotor.Set(speed);
	else if(pos > getPosition())
		liftMotor.Set(-speed);
	else
		liftMotor.Set(0);
	//This one really needs to return something
}

const LiftTask Lift::setPosition(int boxLevel) {
}

//Replace up and down with single move function accepting +-1 which determines
//speed and direction
void Lift::move(float speed) {
    liftMotor.Set(speed);
}

//Speed accepts speed and direction
const LiftTask Lift::moveDist(int dist, float speed) {
}

void Lift::stop()
{
	liftMotor.Set(0);
}

void Lift::remoteLift(float stick, bool upButton, bool downButton, bool stopButton) {
    //Needs to make sure it is not interrupting anything
#include <iostream>
	if(stick < -.2 || stick > .2)
	{
		liftMotor.Set(stick);
		std::cout << "Move: " << stick << '\n';
		std::cout << "The Jaguar is set to " << liftMotor.Get() << '\n';
	}
	/*else if(downButton == true)
		bottom();
	else if(upButton == true)
		top();
	else if(stopButton == true)
		stop();*/
	else
	{
		stop();
		std::cout << "STOP\n";
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
const LiftTask Lift::update() {
    //create an enum with the different actions that can't be finished in one cycle
    //call necessary functions based on what is not done. Accepts an argument that,
    //if false, will reset so that manual control can take over.
}

