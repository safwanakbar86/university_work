#include "quicksort.h"
#include <pthread.h>

void* quick_sort(void* ptr)
{
    int* t1 = (int*) ptr;
    pthread_t id1, id2;
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
        
        pthread_create(&id1, NULL, quick_sort, (void*) t2);
        pthread_join(id1, NULL);
        
        pthread_create(&id2, NULL, quick_sort, (void*) t3);
        pthread_join(id2, NULL);
    }
}

int main()
{
    printf("Enter rows: ");
    scanf("%d", &r);
    
    printf("Enter columns: ");
    scanf("%d", &c);
    
    pthread_t* id = (pthread_t*)malloc(sizeof(pthread_t)* r);
    matrix = (int**)malloc(sizeof(int*)* r);

    for (size_t i = 0; i < r; i++)
        matrix[i] = (int*)malloc(sizeof(int)* c);

    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            matrix[i][j] = rand() % 21;
    
    printf("\nMatrix before quicksort:\n");
    print_matrix();

    for (size_t i = 0; i < r; i++)
    {
        index_array[0] = 0;
        index_array[1] = c - 1;
        index_array[2] = i;
        pthread_create(&id[i], NULL, quick_sort, (void*) index_array);
        pthread_join(id[i], NULL);
    }
    
    printf("Matrix after quicksort:\n");
    print_matrix();
    
    return 0;
}
