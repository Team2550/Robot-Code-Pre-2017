#ifndef SEQUENCE_HH
#define SEQUENCE_HH
#include "Timer.h"

class Sequence
{
private:
	double pers[];
	//int size;

public:
	Sequence(double periods[]);
	int per(Timer time);
};

#endif
