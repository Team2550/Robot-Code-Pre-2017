#include "Lift.hh"

Lift::Lift() : liftMotor(2), bottomSwitch(0), topSwitch(1) {
}

void Lift::bottom(bool boost){
	if(bottomSwitch.Get())
	{
		if(boost)
			liftMotor.Set(.55);
		else
			liftMotor.Set(.45);
	}
	else
	{
		liftMotor.Set(0);
	}
}

void Lift::top(bool boost){
	if(topSwitch.Get())
	{
		if(boost)
			liftMotor.Set(-.8);
		else
			liftMotor.Set(-.65);
	}
	else
	{
		liftMotor.Set(0);
	}
}

void Lift::remoteLift(bool upButton, bool downButton, bool stopButton, bool boost) {
	if(downButton == true)
	{
		bottom(boost);
	}
	else if(upButton == true)
	{
		top(boost);
	}
	else if(stopButton && topSwitch.Get())
	{
		liftMotor.Set(-.2);
	}
	else
	{
		liftMotor.Set(0);
	}
}
