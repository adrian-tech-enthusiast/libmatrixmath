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
   // Create an matrix of #20 elements.
   int rows = 3, columns = 3;
   struct matrix *matrix_object = matrix_create(rows, columns);
   // Fill in the matrix.
   long double m[3][3] = {
       {1, 2, 3},
       {5, 6, 7},
       {9, 10, 11}
   };
  for (int j = 0; j < rows; j++)
   {
      for (int k = 0; k < columns; k++)
      {
         matrix_setl(matrix_object, j, k, m[j][k]);
      }
   }
   // Print the Matrix.
   matrix_print(matrix_object);
   // Clear the used memory.
   matrix_destroy(matrix_object);
   // Return success response.
   return 0;
}
