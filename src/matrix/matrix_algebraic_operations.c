#include <stdlib.h>
#include "matrix.h"
#include "matrix_algebraic_operations.h"
#include <error.h>

/**
 * {@inheritdoc}
 */
struct matrix *matrix_add(struct matrix *a, struct matrix *b)
{
   // For matrices to be added together they must have identical dimensions.
   if (a->rows != b->rows || a->columns != b->columns)
   {
      return NULL;
   }
   // Create the new Matrix to store the result of the operation.
   struct matrix *result = matrix_create(a->rows, a->columns);
   if (result == NULL)
   {
      return NULL;
   }
   // Sum the values.
   long double *val1;
   long double *val2;
   long double sum = 0;
   for (int j = 0; j < a->rows; j++)
   {
      for (int k = 0; k < a->columns; k++)
      {
         val1 = matrix_getl(a, j, k);
         val2 = matrix_getl(b, j, k);
         if (val1 == NULL || val2 == NULL)
         {
            free(result);
            return NULL;
         }
         sum = *val1 + *val2;
         matrix_setl(result, j, k, sum);
      }
   }
   // Return the result of the operation.
   return result;
}

/**
 * {@inheritdoc}
 */
struct matrix *matrix_sub(struct matrix *a, struct matrix *b)
{
   // For matrices to be subtracted together they must have identical dimensions.
   if (a->rows != b->rows || a->columns != b->columns)
   {
      return NULL;
   }
   // Create the new Matrix to store the result of the operation.
   struct matrix *result = matrix_create(a->rows, a->columns);
   if (result == NULL)
   {
      return NULL;
   }
   // Sum the values.
   long double *val1;
   long double *val2;
   long double sub = 0;
   for (int j = 0; j < a->rows; j++)
   {
      for (int k = 0; k < a->columns; k++)
      {
         val1 = matrix_getl(a, j, k);
         val2 = matrix_getl(b, j, k);
         if (val1 == NULL || val2 == NULL)
         {
            free(result);
            return NULL;
         }
         sub = *val1 - *val2;
         matrix_setl(result, j, k, sub);
      }
   }
   // Return the result of the operation.
   return result;
}

/**
 * {@inheritdoc}
 */
struct matrix *matrix_mul(struct matrix *a, struct matrix *b)
{
   // To perform multiplication of two matrices, we should make
   // sure that the number of columns in the 1st matrix is equal
   // to the rows in the 2nd matrix.
   // Therefore, the resulting matrix product will have a number
   // of rows of the 1st matrix and a number of columns of the
   // 2nd matrix.
   if (a->columns != b->rows)
   {
      return NULL;
   }
   // Create the new Matrix to store the result of the operation.
   struct matrix *c = matrix_create(a->rows, b->columns);
   if (c == NULL)
   {
      return NULL;
   }
   // Mul the values.
   long double *val1;
   long double *val2;
   long double result = 0;
   for (int j = 0; j < a->rows; j++)
   {
      for (int k = 0; k < b->columns; k++)
      {
         result = 0;

         for (int l = 0; l < b->rows; l++)
         {
            val1 = matrix_getl(a, j, l);
            val2 = matrix_getl(b, l, k);
            result += (*val1) * (*val2);
         }
         matrix_setl(c, j, k, result);
      }
   }
   // Return the result of the operation.
   return c;
}

/**
 * {@inheritdoc}
 */
int matrix_scalar_mul(long double scalar, struct matrix *a)
{
   long double *val;
   long double mul;
   for (int j = 0; j < a->rows; j++)
   {
      for (int k = 0; k < a->columns; k++)
      {
         val = matrix_getl(a, j, k);
         if (val == NULL)
         {
            return 1;
         }
         mul = scalar * (*val);
         matrix_setl(a, j, k, mul);
      }
   }
   return 0;
}
