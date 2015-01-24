#include "Lift.hh"

Lift::Lift() : liftMotor(2) {
	liftMotor.SetPositionMode(CANJaguar::QuadEncoder, 256, 1, 1, 1);
	liftMotor.EnableControl();
}

void Lift::bottom() {
	liftMotor.Set(0);
}

void Lift::top() {

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

}
