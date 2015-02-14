#include "Lift.hh"

Lift::Lift() : liftMotor(1), bottomSwitch(0), topSwitch(1){
	liftMotor.SetPercentMode();
	liftMotor.EnableControl();
}

void Lift::stop(){
	liftMotor.Set(0);
}

void Lift::bottom(){
	if(bottomSwitch.Get() == 0)
	{
		liftMotor.Set(.35);
	}
	else
	{
		stop();
	}
}

void Lift::top(){
	if(topSwitch.Get() == 0)
	{
		liftMotor.Set(-.65);
	}
	else
	{
		stop();
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
		stop();
	}
}
