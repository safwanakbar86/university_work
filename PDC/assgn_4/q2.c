#include <stdio.h>
#include <math.h>

void one_to_all_broadcast(int steps, int node, int srcnode)
{
	int virtual = node ^ srcnode;
	int mask = (int)(pow(2, steps) - 1);
	
	for (int i = steps - 1; i >= 0; i--)
	{
		mask = mask ^ (int)pow(2, i);
	
		if ((virtual & mask) == 0)
		{
			if ((virtual & (int)pow(2, i)) == 0)
			{
				int dst = virtual ^ (int)pow(2, i);
				printf("Node %d sends message to destination node %d in step %d\n", node, (dst ^ srcnode), steps - i);
			}
	
			else
			{
				int src = virtual ^ (int)pow(2, i);
				printf("Node %d receives message from source node %d in step %d\n", node, (src ^ srcnode), steps - i);
			}
		}
	}
}

int main()
{
    int steps = 3;
    int nodes = (int)pow(2, steps);
        
    for (int x = 0; x < nodes; x++)
    {
		printf("Source node: %d\n", x);
		for (int y = 0; y < nodes; y++)
		{
			one_to_all_broadcast(steps, y, x);
			printf("\n");	
		}
		printf("\n\n");
    }
	
    return 0;
}
