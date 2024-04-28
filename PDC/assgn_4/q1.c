#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int dimension = 2;
	int source = 0;
	int message;

	int mask = pow(2, dimension) - 1;
	for (int i = dimension - 1; i >= 0; i--)
	{
		mask = mask XOR pow(2, i);

		if (source AND mask = 0)
		{
			if (source AND 2^i = 0)
			{
				dest = source XOR 2^i
				send message to dest
			}

			else
			{
				src = source XOR 2^i
				get message from src
			}
		}
	}

	return 0;
}
