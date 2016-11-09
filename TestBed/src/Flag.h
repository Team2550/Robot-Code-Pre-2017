#ifndef SRC_FLAG_H_
#define SRC_FLAG_H_

#include "WPILib.h"

class Flag {
private:
	DoubleSolenoid doubleSolenoid;
public:
	Flag(int solenoidPort);
	void remoteFlag(bool leftButton, bool rightButton);
};

#endif /* SRC_FLAG_H_ */
