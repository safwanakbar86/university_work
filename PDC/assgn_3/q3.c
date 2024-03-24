/*Implement a simple parallel linear search algorithm using OpenMP. The program works on an
integer array of size N filled with random numbers and a key-value to be searched. Write the
parallel program to divide the search space among the multiple threads. Your program should
output the total number of times the occurrence of the key found in the array.*/

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
  
  printf("\n\nProcessors: %d\n", omp_get_num_procs());
  printf("Threads: %d\n", omp_get_max_threads());
  
  #pragma omp parallel for reduction(+:count)
  for (int i = 0; i < N; i++)
    if (key == arr[i])
      count++;
  
  printf("\nKey: %d", key);
  printf("\nCount: %d\n", count);
  
  return 0;
}
