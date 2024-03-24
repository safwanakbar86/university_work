#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int r;
int c;
int sum;
int index_array[3];
int** matrix;

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
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d  ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

int matrix_addition(int row)
{
    int sum = 0;
    for (int j = 0; j < c; j++)
        sum += matrix[row][j];
    return sum;
}

void swap_values(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void quick_sort(int* ptr)
{
    int* t1 = ptr;
    int row = t1[2];
    
    if (t1[0] < t1[1])
    {
        int pivot = decompose_array(t1[2], t1[0], t1[1]);
        int* t2 = (int*)malloc(sizeof(int)* 3);
        int* t3 = (int*)malloc(sizeof(int)* 3);

        t2[0] = t1[0];
        t2[1] = pivot - 1;
        t2[2] = t1[2];
        
        t3[0] = pivot + 1;
        t3[1] = t1[1];
        t3[2] = t1[2];
        
        quick_sort(t2);
        quick_sort(t3);
    }
}
