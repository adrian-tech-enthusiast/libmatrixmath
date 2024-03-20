#include <stdio.h>
#include "matrix.h"
#include "matrix_print.h"
#include "matrix_algebraic_operations.h"
#include "matrix_tests.h"

/**
 * Main controller function.
 *
 * @return int
 *   The constant that represent the exit status.
 */
int matrix_tests()
{
   printf("------------ Matrix setters and getters. ------------\n");
   // Create two matrixes of 3 * 3 elements from arrays.
   int rows = 3, columns = 3;

   long double array_a[3][3] = {
       {1, 2, 3},
       {5, 6, 7},
       {9, 10, 11}
   };
   struct matrix *matrix_a = matrix_from_array(&array_a[0][0], rows, columns);

   long double array_b[3][3] = {
       {12, 20, 3},
       {45, 6, 9},
       {9, 5, 11}
   };
   struct matrix *matrix_b = matrix_from_array(&array_b[0][0], rows, columns);

   // Print the Matrix.
   matrix_print(matrix_a);
   matrix_print(matrix_b);

   // Test Scalar multiplication.
   printf("------------ Matrix multiplication by a scalar[4.5]. ------------\n");
   matrix_scalar_mul(4.5, matrix_a);
   matrix_print(matrix_a);

   // Clear the used memory.
   matrix_destroy(matrix_a);
   matrix_destroy(matrix_b);

   // Return success response.
   return 0;
}
