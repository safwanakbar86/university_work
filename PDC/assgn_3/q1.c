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
  
  printf("Odd Numbers Array:\n");
  for (int i = 0; i < N; i++)
  {
    random_num = rand() % 10;
    while (random_num % 2 == 0)
      random_num = rand() % 10;
    odd[i] = random_num;
    prime[i] = true;
    printf("%d   ", random_num);
  }
  
  #pragma omp parallel for num_threads(P) schedule(dynamic, 1)
  for (int i = 0; i < N; i++)
  {
    int square_root = odd[i] * odd[i];
    for (int j = 3; j < square_root; j++)
      if (odd[i] != j)
        if (odd[i] % j == 0)
          prime[i] = false;
  }
  
  printf("\nPrime Odd Numbers:\n");
  for (int i = 0; i < N; i++)
    if (prime[i] == true)
      printf("%d   ", odd[i]);
  
  printf("\n");
  return 0;
}
