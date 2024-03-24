#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

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

int main()
{
    printf("Enter rows: ");
    scanf("%d", &r);
    
    printf("Enter columns: ");
    scanf("%d", &c);
    
    matrix = (int**)malloc(sizeof(int*)* r);
    for (size_t i = 0; i < r; i++)
        matrix[i] = (int*)malloc(sizeof(int)* c);

    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            matrix[i][j] = rand() % 21;
    
    printf("\nMatrix before quicksort:\n");
    print_matrix();
    
    int sum = 0;
    printf("Processors: %d\n", omp_get_num_procs());
    printf("Threads: %d\n", omp_get_max_threads());
    
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < r; i++)
    {
        index_array[0] = 0;
        index_array[1] = c - 1;
        index_array[2] = i;
        quick_sort(index_array);
        if (i == r / 2)
          quick_sort(index_array);
        sum += matrix_addition(i);
    }
        
    printf("\nMatrix after quicksort:\n");
    print_matrix();
    
    printf("Sum after addition: %d\n", sum);
    return 0;
}
