# Assignment 2

The following programs are written in C using POSIX threads.

## Matrix Multiplication

  1. Take two matrices of size (m x n) as input from the user through command line.
  2. Initialize the matrix by some random values.
  3. Use data decomposition by assigning each row to a new thread.
  4. Perform matrix multiplication in each thread.
  5. Mutual exclusion should be used to modify shared variables.

## Quicksort

  1. Take a matrix of size (m x n) values are taken as input from the user.
  2. Initialize the matrix by some random values.
  3. Create number of threads equal to the number of rows (m).
  4. Each thread will sort a row using quicksort in ascending order.
  5. Implement quicksort using recursive decomposition.
  6. Each subtask will need to be done by a new thread.
