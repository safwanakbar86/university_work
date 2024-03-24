#include "q5.h"
#include <omp.h>

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
