#ifndef SRC_DRIVE_H_
#define SRC_DRIVE_H_

#include "WPILib.h"

class Drive {
private:
	Victor backLeft;
	Victor backRight;
	Victor frontLeft;
	Victor frontRight;
public:
	Drive(int backLeftPort, int backrightPort, int frontLeftPort, int frontRightPort);
	void remoteDrive(float leftStick, float rightStick);
	void stop();
};

#endif /* SRC_DRIVE_H_ */
