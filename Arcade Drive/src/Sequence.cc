#include "Sequence.hh"

Sequence::Sequence(double periods[])
{
	//pers = periods;
	//size = (sizeof(pers)/sizeof(*pers));
}

int Sequence::per(Timer time)
{
	double cur = time.Get();
	double prev = 0;

	//for (int i = 0; i < size; i++) {
		//prev += pers[i];

		//if (cur < prev)
		//	return i;
	//}

	//return size;
	return 0;
}
