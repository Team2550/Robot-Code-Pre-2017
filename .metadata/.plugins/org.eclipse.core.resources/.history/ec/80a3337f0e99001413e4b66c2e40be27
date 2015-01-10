#ifndef DRIVE_H
#define DRIVE_H
#include <math.h>
#include "WPILib.h"
#include "xBox.hh"

class Drive
{
    private:
		//left and right Drive motors
		Jaguar* left;
		Jaguar* right;
		float speedMult;//speed multiplier
		
	public:
		Drive();
		~Drive();

		void move(float leftSpeed, float rightSpeed);
		void remoteDrive(float leftStick, float rightStick, bool boost);
		void stop();
		float getSpeedMult();
};

#endif





