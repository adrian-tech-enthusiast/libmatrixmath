#include <stdlib.h>
#include <error.h>
#include "../../include/matrixmath.h"

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
int matrix_add_dest(struct matrix *a, struct matrix *b, struct matrix *dest) {
  // For matrices to be added together they must have identical dimensions.
  if (a->rows != b->rows || a->columns != b->columns) {
    return 1;
  }
  // Check if the destination matrix matches the expected dimensions.
  if (dest->rows != a->rows || dest->columns != a->columns) {
    return 1;
  }
  // Sum the values.
  long double *val1;
  long double *val2;
  long double sum = 0;
  for (int j = 0; j < a->rows; j++) {
    for (int k = 0; k < a->columns; k++) {
      val1 = matrix_getl(a, j, k);
      val2 = matrix_getl(b, j, k);
      if (val1 == NULL || val2 == NULL) {
        return 1;
      }
      sum = *val1 + *val2;
      matrix_setl(dest, j, k, sum);
    }
  }
  // Return the result of the operation.
  return 0;
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
   // Subtract the values.
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
int matrix_sub_dest(struct matrix *a, struct matrix *b, struct matrix *dest) {
  // For matrices to be subtracted together they must have identical dimensions.
  if (a->rows != b->rows || a->columns != b->columns) {
    return 1;
  }
  // Check if the destination matrix matches the expected dimensions.
  if (dest->rows != a->rows || dest->columns != a->columns) {
    return 1;
  }
  // Subtract the values.
  long double *val1;
  long double *val2;
  long double sub = 0;
  for (int j = 0; j < a->rows; j++) {
    for (int k = 0; k < a->columns; k++) {
      val1 = matrix_getl(a, j, k);
      val2 = matrix_getl(b, j, k);
      if (val1 == NULL || val2 == NULL) {
        return 1;
      }
      sub = *val1 - *val2;
      matrix_setl(dest, j, k, sub);
    }
  }
  // Return the result of the operation.
  return 0;
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
struct vector *matrix_mul_vector(struct matrix *a, struct vector *b)
{
   // To perform multiplication between a matrix and a vector, we must
   // make sure that the number of columns in the matrix is equal
   // to the rows in the vector.
   if (a->columns != b->capacity)
   {
      return NULL;
   }
   // Create the new Vector to store the result of the operation.
   struct vector *c = vector_create(a->rows);
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
      result = 0;
      for (int k = 0; k < a->columns; k++)
      {
         val1 = matrix_getl(a, j, k);
         val2 = vector_getl(b, k);
         result += (*val1) * (*val2);
      }
      vector_setl(c, j, result);
   }
   // Return the result of the operation.
   return c;
}

/**
 * {@inheritdoc}
 */
struct matrix *matrix_scalar_mul(long double scalar, struct matrix *a)
{
   // Create the new Matrix to store the result of the operation.
   struct matrix *result = matrix_create(a->rows, a->columns);
   if (result == NULL) {
      return NULL;
   }
   // Mul the values.
   long double *val;
   long double mul;
   for (int j = 0; j < a->rows; j++)
   {
      for (int k = 0; k < a->columns; k++)
      {
         val = matrix_getl(a, j, k);
         if (val == NULL)
         {
            return NULL;
         }
         mul = scalar * (*val);
         matrix_setl(result, j, k, mul);
      }
   }
   // Return the result of the operation.
   return NULL;
}

/**
 * {@inheritdoc}
 */
int matrix_scalar_mul_dest(long double scalar, struct matrix *a, struct matrix *dest)
{
   // Mul the values.
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
         matrix_setl(dest, j, k, mul);
      }
   }
   // Return the result of the operation.
   return 0;
}

/**
 * {@inheritdoc}
 */
struct matrix *matrix_transpose(struct matrix *a) {
  // Check if the input matrix is NULL.
  if (a == NULL) {
    return NULL;
  }
  // Create the transposed matrix.
  struct matrix *transposed = matrix_create(a->columns, a->rows);
  if (transposed == NULL) {
    return NULL;
  }
  // Fill the transposed matrix.
  long double *value;
  for (int i = 0; i < a->rows; ++i) {
    for (int j = 0; j < a->columns; ++j) {
      value = matrix_getl(a, i, j);
      matrix_setl(transposed, j, i, *value);
    }
  }
  return transposed;
}
