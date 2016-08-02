#ifndef SEQUENCE_HH
#define SEQUENCE_HH
#include "Timer.h"

class Sequence
{
private:
	double periods[];
	int size;

public:
	Sequence(double periods[], int numberOfPeriods);
	int getPeriod(Timer time);
};

#endif
