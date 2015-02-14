#include "Lift.hh"

Lift::Lift() : liftMotor(2), bottomSwitch(0), topSwitch(1){
}

void Lift::bottom(){
	if(bottomSwitch.Get() == 0)
	{
		liftMotor.Set(.35);
	}
	else
	{
		liftMotor.Set(0);
	}
}

void Lift::top(){
	if(topSwitch.Get() == 0)
	{
		liftMotor.Set(-.65);
	}
	else
	{
		liftMotor.Set(0);
	}
}

void Lift::remoteLift(float stick, bool upButton, bool downButton, bool stopButton) {
	if(stick < -.2 && !topSwitch.Get())
	{
		liftMotor.Set(stick);
	}
	else if(stick > .2 && !bottomSwitch.Get())
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
	else if(stopButton  && !topSwitch.Get())
	{
		liftMotor.Set(-.2);
	}
	else
	{
		liftMotor.Set(0);
	}
}
