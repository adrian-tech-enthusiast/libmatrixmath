#include <stdlib.h>
#include "matrix.h"
#include "matrix_algebraic_operations.h"
#include <error.h>

/**
 * {@inheritdoc}
 */
struct matrix *matrix_add(struct matrix *a, struct matrix *b)
{
   // @todo: Complete this implementation.
   return NULL;
}

/**
 * {@inheritdoc}
 */
struct matrix *matrix_sub(struct matrix *a, struct matrix *b)
{
   // @todo: Complete this implementation.
   return NULL;
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
