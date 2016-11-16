#include "Flag.h"

pneumaticFlag::pneumaticFlag(int solenoidPort1, int solenoidPort2) :
           doubleSolenoid(solenoidPort1, solenoidPort2)
{

}

void pneumaticFlag::remoteFlag(bool leftButton, bool rightButton)
{
	if(leftButton)
		doubleSolenoid.Set(DoubleSolenoid::Value::kForward);
	else if(rightButton)
		doubleSolenoid.Set(DoubleSolenoid::Value::kReverse);
	else
		doubleSolenoid.Set(DoubleSolenoid::Value::kOff);
}
