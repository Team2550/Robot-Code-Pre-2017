#include "Flag.h"

Flag::Flag(int solenoidPort) :
           doubleSolenoid(solenoidPort)
{

}

void Flag::remoteFlag(bool leftButton, bool rightButton)
{
	/*if(leftButton)
		doubleSolenoid.set(DoubleSolenoid.Value.kForward);
	else if(rightButton)
		doubleSolenoid.set(DoubleSolenoid.Value.kReverse);
	else
		doubleSolenoid.set(DoubleSolenoid.Value.kOff);*/
}
