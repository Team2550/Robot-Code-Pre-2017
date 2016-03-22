#include "MaxSonarI2C.hh"

MaxSonarI2C::MaxSonarI2C() : I2C(kOnboard, 0xe0)
{

}

bool MaxSonarI2C::ping()
{
	unsigned char code = 0x51;
	bool error;
	error = WriteBulk(&code, 1);
	timer.Reset();
	timer.Start();
	return !error;
}

float MaxSonarI2C::getRange()
{
	static int range = -1;
	unsigned char range_byte[2];
	bool error;

	if (timer.Get() > 0.08) {
		error = ReadOnly(2, range_byte);

		if (!error) {
			range = (range_byte[0] * 256) + range_byte[1];
		}
	}

	return range / 2.54;
}
