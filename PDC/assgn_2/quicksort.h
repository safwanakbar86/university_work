#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int r;
int c;
int sum;
int index_array[3];
int** matrix;

void swap_values(int* first, int* second);
int decompose_array(int sortRow, int l, int h);
void print_matrix();

int decompose_array(int row, int beg, int end)
{
    int p = matrix[row][end];
    int i = beg - 1;

    for (int j = beg; j <= end - 1; j++)
        if (matrix[row][j] < p)
        {
            i++;
            swap_values(&(matrix[row][i]), &(matrix[row][j]));
        }

    swap_values(&(matrix[row][i + 1]), &(matrix[row][end]));
    return (i + 1);
}

void print_matrix()
{
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
            printf("%d  ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

void swap_values(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}
