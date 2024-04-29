#include <stdio.h>
#include <math.h>

void one_to_all_broadcast(int dimension, int ID)
{
	int mask = (int)(pow(2, dimension) - 1);
	for (int i = dimension - 1; i >= 0; i--)
	{
		mask = mask ^ (int)pow(2, i);

		if ((ID & mask) == 0)
		{
			if ((ID & (int)pow(2, i)) == 0)
			{
				int dest = ID ^ (int)pow(2, i);
				// send message to dest
				printf("Node %d sends message to destination node %d in step %d\n", ID, dest, dimension - i);
			}

			else
			{
				int src = ID ^ (int)pow(2, i);
				// receive message from src
				printf("Node %d receives message from source node %d in step %d\n", ID, src, dimension - i);
			}
		}
	}
}

int main()
{
        int dimension = 3;
        int nodes = (int)pow(2, dimension);
        
	for (int j = 0; j < nodes; j++)
	{
		one_to_all_broadcast(dimension, j);
	        printf("\n");	
	}
	
	return 0;
}
