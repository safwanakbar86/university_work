# Assignment 3

The following programs are written in C using OpenMP.

## Odd Number Factors

1. Test each odd number up to a specified limit for divisibility by all the factors from 3 to the square root of that number
2. The program takes two main parameters from the command line
3. P - the number of processors (numProcs in the code) and N - the problem size (size in the code)
4. Takes arguments that outputs all of the primes generated either to a file or standard out
5. Main data structure of the program is an array which holds boolean values indicating whether the corresponding numbers are prime

## Count Total Wins

1. Parallelize the piece of code using OpenMP with SIZE=1000
2. Comment above and below the piece of code to be parallelized
3. Report sequential and parallel execution time using 2, 3, and 4 threads along with the achieved speedup
4. Identify private variables, shared variables, critical section(s), and need for reduction to avoid semantic inconsistencies

## Linear Search

1. Implement linear search on an integer array of size N filled with random numbers
2. Divide the search space among the multiple threads
3. Output the total number of times the occurrence of the key found in the array

## Matrix Multiplication

1. Parallelize a 100x100 matrix multiplication program in different ways (course-grain / fine-grain)
2. Report the execution time for each program by calling the function "omp_get_wtime()"
3. Write a parallel program with default number of threads and default scheduling running it with static and dynamic schedule for loop
4. Change program to explicitly create the number of threads equal to number of elements in the output matrix
5. Each thread will be assigned the task to perform the calculation for one element (fine grain composition)

## Quicksort

1. Take a matrix of size (m x n) values are taken as input from the user
2. Initialize the matrix by some random values
3. Create number of threads equal to the number of rows (m)
4. Each thread will sort a row using quicksort in ascending order
5. Implement quicksort using recursive decomposition
6. Each subtask will need to be done by a new thread
