#ifndef MAXSONARI2C_HH
#define MAXSONARI2C_HH
#include "WPILib.h"

class MaxSonarI2C : public I2C
{
private:
	Timer timer;

public:
	MaxSonarI2C();
	bool ping();
	float getRange();
};

#endif
