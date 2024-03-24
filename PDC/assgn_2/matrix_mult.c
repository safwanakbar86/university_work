#include "matrix_mult.h"
#include <pthread.h>

void* matrix_multiplication(void* ptr)
{
    int* t = (int*) ptr;
    int row = *t;
    
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            result[row][i] += matrix1[row][j] * matrix2[j][i];
    
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    r = atoi(argv[1]);
    c = atoi(argv[2]);
    
    if (r != c)
    {
      printf("Matrix multiplication cannot take place!\n");
      return 0;
    }
    
    pthread_t* id = (pthread_t*)malloc(sizeof(pthread_t)* r);
    matrix1 = (int**)malloc(sizeof(int*)* r);
    matrix2 = (int**)malloc(sizeof(int*)* r);
    result = (int**)malloc(sizeof(int*)* r);

    for (size_t i = 0; i < r; i++)
    {
        matrix1[i] = (int*)malloc(sizeof(int)* c);
        matrix2[i] = (int*)malloc(sizeof(int)* c);
        result[i] = (int*)malloc(sizeof(int)* c);
    }

    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
        {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
            result[i][j] = 0;
        }

    for (size_t i = 0; i < r; i++)
    {
        pthread_create(&id[i], NULL, matrix_multiplication, (void*)&i);
        pthread_join(id[i], NULL);
    }
    
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    
    printf("Matrix 2:\n");
    print_matrix(matrix2);
    
    printf("Result:\n");
    print_matrix(result);
    
    return 0;
}
