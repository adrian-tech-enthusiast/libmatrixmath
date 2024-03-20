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
long double *matrix_dot_product(struct matrix *a, struct matrix *b)
{
   // @todo: Complete this implementation.
   return NULL;
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
