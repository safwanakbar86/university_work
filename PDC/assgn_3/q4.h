#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

double start_time;
double end_time;
int size = 100;

int** matrix1;
int** matrix2;
int** result;

void print_matrix(int** m)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d  ", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

void matrix_multiplication(int r)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[r][i] += matrix1[r][j] * matrix2[j][i];
}
