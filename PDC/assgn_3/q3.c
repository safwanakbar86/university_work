#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
  int N = rand() % 31;
  int* arr;
  arr = (int*)malloc(sizeof(int)* N);
  printf("Array:\n");
  
  for (int i = 0; i < N; i++)
  {
    arr[i] = rand() % 10;
    printf("%d   ", arr[i]);
  }
      
  int key = rand() % 10;
  int count = 0;
  omp_set_dynamic(1);
  
  #pragma omp parallel for reduction(+:count)
  for (int i = 0; i < N; i++)
    if (key == arr[i])
      count++;
  
  printf("\nKey: %d", key);
  printf("\nCount: %d\n", count);
  
  return 0;
}
