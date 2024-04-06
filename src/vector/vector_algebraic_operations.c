#include <stdlib.h>
#include "../../include/matrixmath.h"

/**
 * {@inheritdoc}
 */
struct vector *vector_add(struct vector *a, struct vector *b)
{
   // Check the size of the two vector matches.
   if (a->capacity != b->capacity)
   {
      return NULL;
   }
   // Create the new vector to store the result of the operation.
   struct vector *result = vector_create(a->capacity);
   if (result == NULL)
   {
      return NULL;
   }
   // Sum the values.
   long double *val1;
   long double *val2;
   long double sum = 0;
   for (int i = 0; i < a->capacity; i++)
   {
      val1 = vector_getl(a, i);
      val2 = vector_getl(b, i);
      if (val1 == NULL || val2 == NULL)
      {
         free(result);
         return NULL;
      }
      sum = *val1 + *val2;
      vector_setl(result, i, sum);
   }
   // Return the result of the operation.
   return result;
}

/**
 * {@inheritdoc}
 */
struct vector *vector_sub(struct vector *a, struct vector *b)
{
   // Check the size of the two vector matches.
   if (a->capacity != b->capacity)
   {
      return NULL;
   }
   // Create the new vector to store the result of the operation.
   struct vector *result = vector_create(a->capacity);
   if (result == NULL)
   {
      return NULL;
   }
   // Sum the values.
   long double *val1;
   long double *val2;
   long double sub = 0;
   for (int i = 0; i < a->capacity; i++)
   {
      val1 = vector_getl(a, i);
      val2 = vector_getl(b, i);
      if (val1 == NULL || val2 == NULL)
      {
         free(result);
         return NULL;
      }
      sub = *val1 - *val2;
      vector_setl(result, i, sub);
   }
   // Return the result of the operation.
   return result;
}

/**
 * {@inheritdoc}
 */
long double *vector_dot_product(struct vector *a, struct vector *b)
{
   // Check the size of the two vector matches.
   if (a->capacity != b->capacity)
   {
      return NULL;
   }
   // Create pointer to the result value.
   size_t size = sizeof(long double);
   long double *result = (long double *)malloc(size);
   if (result == NULL)
   {
      return NULL;
   }
   // Multiply values.
   long double *val1;
   long double *val2;
   *result = 0;
   for (int i = 0; i < a->capacity; i++)
   {
      val1 = vector_getl(a, i);
      val2 = vector_getl(b, i);
      if (val1 == NULL || val2 == NULL)
      {
         free(result);
         return NULL;
      }
      *result = *result + (*val1) * (*val2);
   }
   // Return the result of the operation.
   return result;
}

/**
 * {@inheritdoc}
 */
struct vector *vector_scalar_mul(long double scalar, struct vector *a)
{
   // Create the new vector to store the result of the operation.
   struct vector *result = vector_create(a->capacity);
   if (result == NULL)
   {
      return NULL;
   }
   // Sum the values.
   long double *val;
   long double mul;
   for (int i = 0; i < a->capacity; i++)
   {
      val = vector_getl(a, i);
      if (val == NULL)
      {
         free(result);
         return NULL;
      }
      mul = scalar * (*val);
      vector_setl(result, i, mul);
   }
   // Return the result of the operation.
   return result;
}
