#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int r;
int c;
int** matrix1;
int** matrix2;
int** result;

void print_matrix(int** m);

void print_matrix(int** m)
{
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
            printf("%d  ", m[i][j]);
        printf("\n");
    }
    printf("\n");
}
