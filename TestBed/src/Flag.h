#ifndef SRC_FLAG_H_
#define SRC_FLAG_H_

#include "WPILib.h"

class pneumaticFlag {
private:
	DoubleSolenoid doubleSolenoid;
public:
	pneumaticFlag(int solenoidPort1, int solenoidPort2);
	void remoteFlag(bool leftButton, bool rightButton);
};

#endif /* SRC_FLAG_H_ */
