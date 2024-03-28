#include "q4.h"
#include <omp.h>

int main()
{
    matrix1 = (int**)malloc(sizeof(int*)* size);
    matrix2 = (int**)malloc(sizeof(int*)* size);
    result = (int**)malloc(sizeof(int*)* size);

    for (int i = 0; i < size; i++)
    {
        matrix1[i] = (int*)malloc(sizeof(int)* size);
        matrix2[i] = (int*)malloc(sizeof(int)* size);
        result[i] = (int*)malloc(sizeof(int)* size);
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            matrix1[i][j] = rand() % 3;
            matrix2[i][j] = rand() % 3;
            result[i][j] = 0;
        }
    
    omp_set_dynamic(1);
    printf("Maximum (default) threads: %d\n", omp_get_max_threads());
    
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < size; i++)
        matrix_multiplication(i);
    end_time = omp_get_wtime();
    printf("Time taken with default scheduling: %f\n", end_time - start_time); 
    
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        result[i][j] = 0;
    
    start_time = omp_get_wtime();
    #pragma omp parallel for schedule(static) 
    for (int i = 0; i < size; i++)
        matrix_multiplication(i);
    end_time = omp_get_wtime();
    printf("Time taken with static scheduling: %f\n", end_time - start_time);
    
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        result[i][j] = 0;
    
    start_time = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < size; i++)
        matrix_multiplication(i);
    end_time = omp_get_wtime();
    printf("Time taken with dynamic scheduling: %f\n\n", end_time - start_time);
    
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    
    printf("Matrix 2:\n");
    print_matrix(matrix2);
    
    printf("Result:\n");
    print_matrix(result);
    
    return 0;
}
