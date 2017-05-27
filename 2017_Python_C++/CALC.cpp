#include "CALC.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>

void _CALC(double *DATA, int *RESULT, int N,  double treshold)
{
	printf("C++ start\n");

	RESULT[0] = 0;
	for (int a = 0; a < N; a++)
	{
		for (int b = a+1; b < N; b++)
		{
			for (int c = b+1; c < N; c++)
			{
				if (fabs(DATA[a] + DATA[b] + DATA[c] - 1) < treshold)
				{
					RESULT[0]++;
				}
			}
		}
	}

	printf("C++ finish\n");
}


