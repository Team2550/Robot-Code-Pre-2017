#include "Sequence.hh"

Sequence::Sequence(double periods[], int numberOfPeriods)
{
	size = numberOfPeriods;

	for(int i = 0; i < size; i++) {
		this-> periods[i] = periods[i];
	}
}

int Sequence::getPeriod(Timer time)
{
	double cur = time.Get();
	double prev = 0;

	for (int i = 0; i < size; i++) {
		prev += periods[i];

		if (cur < prev)
			return i;
	}

	return size;
}
