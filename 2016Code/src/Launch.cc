#include "Launch.hh"

Launch::Launch(int leftPort, int rightPort) :
    left(leftPort), right(rightPort)
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

void Launch::remoteLaunch(bool launch, bool intake, bool stop)
{
    if(stop)
        feedStop();
    else if(launch)
        feedLaunch();
    else if(intake)
        feedIntake();
}
