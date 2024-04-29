#include <stdio.h>
#include <math.h>

void one_to_all_broadcast(int dimension, int node)
{
	int mask = (int)(pow(2, dimension) - 1);
	for (int i = dimension - 1; i >= 0; i--)
	{
		mask = mask ^ (int)pow(2, i);
	
		if ((node & mask) == 0)
		{
			if ((node & (int)pow(2, i)) == 0)
			{
				int dst = node ^ (int)pow(2, i);
				printf("Node %d sends message to destination node %d in step %d\n", node, dst, dimension - i);
			}
	
			else
			{
				int src = node ^ (int)pow(2, i);
				printf("Node %d receives message from source node %d in step %d\n", node, src, dimension - i);
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
