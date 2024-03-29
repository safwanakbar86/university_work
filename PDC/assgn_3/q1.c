//TBU
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <omp.h>

int main(int argc, char* argv[])
{
  int P = atoi(argv[1]);
  int N = atoi(argv[2]);
  
  int random_num;
  int* odd = (int*)malloc(sizeof(int)* N);
  bool* prime = (bool*)malloc(sizeof(bool)* N);
  
  printf("Odd Numbered Array:\n");
  for (int i = 0; i < N; i++)
  {
    random_num = rand() % 10;
    while (random_num % 2 == 0)
      random_num = rand() % 10;
    odd[i] = random_num;
    prime[i] = false;
    printf("%d   ", random_num);
  }
  
  return 0;
}
