#ifndef SRC_DRIVE_H_
#define SRC_DRIVE_H_

#include "WPILib.h"

class Drive {
private:
	Victor backLeft;
	Victor backRight;
	Victor frontLeft;
	Victor frontRight;
	const float motorPower;
public:
	Drive(int backLeftPort, int backrightPort, int frontLeftPort,
	      int frontRightPort, float motorPowerMult);
	void remoteDrive(float leftX, float leftY, float rightX);
	void stop();
};

#endif /* SRC_DRIVE_H_ */
