#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

double start_time;
double end_time;

int main()
{
  start_time = omp_get_wtime();
  
  // Code section to be parallelized
  long int win = 0;
  int SIZE = 1000;
  int key = 111;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      for (int k = 0; k < SIZE; k++)
      {
        int x = (i*i*1000/35) % 1000;
        int y = (j*j*1000/36) % 1000;
        int z = (k*k*1000/37) % 1000;
        if (key == (x+y+z))
        {
          win=win+1;
        }
      }
    }
  }
  // Code section to be parallelized
  
  end_time = omp_get_wtime();
  printf("Total wins = %ld\n", win);
  double sequential_time = end_time - start_time;
  printf("Sequential Time: %f\n", sequential_time);
  
  
  start_time = omp_get_wtime();
  win = 0;
  #pragma omp parallel for num_threads(2) private(win) shared(key, SIZE) reduction(+:win)
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      for (int k = 0; k < SIZE; k++)
      {
        #pragma omp critical
        int x = (i*i*1000/35) % 1000;
        int y = (j*j*1000/36) % 1000;
        int z = (k*k*1000/37) % 1000;
        if (key == (x+y+z))
        {
          win=win+1;
        }
      }
    }
  }
  end_time = omp_get_wtime();
  printf("Total wins = %ld\n", win);
  double parallel_2_time = end_time - start_time;
  printf("Parallel Time using 2 threads: %f\n", parallel_2_time);
  
  
  start_time = omp_get_wtime();
  win = 0;
  #pragma omp parallel for num_threads(3) private(win) shared(key, SIZE) reduction(+:win)
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      for (int k = 0; k < SIZE; k++)
      {
        #pragma omp critical
        int x = (i*i*1000/35) % 1000;
        int y = (j*j*1000/36) % 1000;
        int z = (k*k*1000/37) % 1000;
        if (key == (x+y+z))
        {
          win=win+1;
        }
      }
    }
  }
  end_time = omp_get_wtime();
  printf("Total wins = %ld\n", win);
  double parallel_3_time = end_time - start_time;
  printf("Parallel Time using 3 threads: %f\n", parallel_3_time);
  
  
  start_time = omp_get_wtime();
  win = 0;
  #pragma omp parallel for num_threads(4) private(win) shared(key, SIZE) reduction(+:win)
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      for (int k = 0; k < SIZE; k++)
      {
        #pragma omp critical
        int x = (i*i*1000/35) % 1000;
        int y = (j*j*1000/36) % 1000;
        int z = (k*k*1000/37) % 1000;
        if (key == (x+y+z))
        {
          win=win+1;
        }
      }
    }
  }
  end_time = omp_get_wtime();
  printf("Total wins = %ld\n", win);
  double parallel_4_time = end_time - start_time;
  printf("Parallel Time using 4 threads: %f\n", parallel_4_time);
  
  printf("Achieved speedup using 2 threads: %f\n", sequential_time / parallel_2_time);
  printf("Achieved speedup using 3 threads: %f\n", sequential_time / parallel_3_time);
  printf("Achieved speedup using 4 threads: %f\n", sequential_time / parallel_4_time);

  return 0;
}
