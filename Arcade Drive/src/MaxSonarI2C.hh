#ifndef MAXSONARI2C_HH
#define MAXSONARI2C_HH
#include "WPILib.h"
#include <iostream>

class MaxSonarI2C
{
private:
	I2C write;
	I2C read;
	Timer timer;
	float range;
	void setRange();

public:
	MaxSonarI2C();
	bool ping();
	float getRange();
};

#endif
