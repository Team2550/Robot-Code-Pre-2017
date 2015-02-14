#include "Lift.hh"

Lift::Lift() : liftMotor(2), bottomSwitch(0), topSwitch(1){
}

/*const LiftTask Lift::bottom() {
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
}*/

double Lift::getPosition() {
	//program for encoder separate from motor controller
	return 0;
}

void Lift::bottom(){
	if(bottomSwitch.Get() == 0)
	{
		liftMotor.SetSpeed(.45);
	}
	else
	{
		stop();
	}
}

void Lift::top(){
	if(topSwitch.Get() == 0)
	{
		liftMotor.SetSpeed(-.6);
	}
	else
	{
		stop();
	}
}
void Lift::setPosition(double pos, float speed) {
	speed = fabs(speed);
	if(pos < getPosition())
	{
		liftMotor.Set(speed);
	}
	else if(pos > getPosition())
	{
		liftMotor.Set(-speed);
	}
	else if(topSwitch.Get() == 1 || bottomSwitch.Get() == 1 || pos == getPosition())
	{
		liftMotor.Set(0);
	}
}

void Lift::setPosition(int boxLevel) {
}

//Replace up and down with single move function accepting +-1 which determines
//speed and direction
void Lift::move(float speed) {
    liftMotor.Set(speed);
}

//Speed accepts speed and direction
void Lift::moveDist(int dist, float speed) {
}

void Lift::stop()
{
	liftMotor.Set(0);
}

void Lift::remoteLift(float stick, bool upButton, bool downButton, bool stopButton) {
    //Needs to make sure it is not interrupting anything
	static int counter;
	if(stick < -.2 && topSwitch.Get())
	{
		liftMotor.Set(stick);
	}
	else if(stick > .2 && bottomSwitch.Get() == 0)
	{
			liftMotor.Set(stick);
	}
	else if(downButton == true)
	{
		bottom();
	}
	else if(upButton == true)
	{
		top();
	}
	else if(stopButton == 1)
	{
		stop();
		if(counter == 1)
		{
			liftMotor.Set(-.25);
			counter = 0;
		}
		counter++;
	}
	else
	{
	stop();
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

