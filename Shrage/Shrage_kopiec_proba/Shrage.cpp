
#include "Shrage.h"



int calculateC_MAX(Job* jobs, int size) {
	int m = 0, c = 0;
	for (int i = 0; i < size; i++) {
		m = std::max((*(jobs + i)).R, m) + (*(jobs + i)).P;
		c = std::max(c, m + (*(jobs + i)).Q);
	}
	return c;
}

void SolveShrage()
{
	//Job** DANE = wczytaj();
	for (int i = 0; i < 8; ++i)
	{
		Job* Jobs = wczytaj(i);
		int size;
		if (i == 0)size = 4;
		else size = 50;

		for (int j = 0; j < size;++j) {

		}
	}
}