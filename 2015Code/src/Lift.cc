#include "Lift.hh"

Lift::Lift() : liftMotor(2) {
	liftMotor.SetPositionMode(CANJaguar::QuadEncoder, 256, 1, 1, 1);
	liftMotor.EnableControl();
}

void Lift::bottom() {
	liftMotor.Set(0);
}

void Lift::top() {
	//to be written
}

double Lift::getPosition() {
	return liftMotor.GetPosition();
}

void Lift::setPosition(double dist) {
	liftMotor.Set(dist);
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
