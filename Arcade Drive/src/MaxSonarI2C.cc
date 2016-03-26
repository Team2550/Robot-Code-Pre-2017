#include "MaxSonarI2C.hh"

MaxSonarI2C::MaxSonarI2C() : write(I2C::kOnboard, 0xE0), read(I2C::kOnboard, 0xE1)
{
	range = -1;
	timer.Start();
}

bool MaxSonarI2C::ping()
{
	unsigned char code = 0x51;
	bool error = false;

	if (timer.HasPeriodPassed(0.2)) {
		error = write.WriteBulk(&code, 1);
		setRange();
		std::cout << "Ping: " << !error << '\n';
	}

	return !error;
}

void MaxSonarI2C::setRange()
{
	unsigned char range_byte[2];
	bool error;

	error = read.ReadOnly(2, range_byte);

	std::cout << "Initialized\n";
	if (!error) {
		range = (range_byte[0] * 256) + range_byte[1];
		std::cout << "Got range\n";
		range /= 2.54;
	}

	range = -1;
}

float MaxSonarI2C::getRange()
{
	return range;
}
