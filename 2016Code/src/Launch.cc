#include "Launch.hh"

Launch::Launch(int leftPort, int rightPort, int topPort, int bottomPort) :
    left(leftPort), right(rightPort), topSwitch(topPort), bottomSwitch(bottomPort)
{
    // One of the motors will have to be inverted;
    // I'm totally guessing as to which one.
    left.SetInverted(true);
}

Launch::~Launch()
{

}

void Launch::feedIntake()
{
    left.Set(-.25);
    right.Set(-.25);
}

void Launch::feedStop()
{
    left.Set(0);
    right.Set(0);
}

void Launch::feedLaunch()
{
    left.Set(1.0);
    right.Set(1.0);
    // Add more things here e.g. something to push
    // the lauched item into the wheels after a
    // period of time
}

void Launch::remoteLaunch(bool launch, bool intake, bool stop, bool upButton, bool downButton)
{
	// feed control
    if(stop)
        feedStop();
    else if(launch)
        feedLaunch();
    else if(intake)
        feedIntake();

    // motor control
    if(upButton)
    	rotateTheLauncherUp();
    else if(downButton)
    	rotateTheLauncherDown();
    else
    	stopRotate();
}

void Launch::rotateTheLauncherUp()
{ // note to self: rotating might be backwards.

    if (topSwitch.Get())
    	stopRotate();
    else
    	relay.set(relay::value::kReverse);

}
void Launch::rotateTheLauncherDown()
{
    if (bottomSwitch.Get())
    	stopRotate();
    else
    	relay.set(relay::value::kReverse);

	relay.set(relay::value::kForward);
}
void Launch::stopRotate()
{
    relay.set(relay::value::kOff);
}
