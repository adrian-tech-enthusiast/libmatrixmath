#include <stdlib.h>
#include "vector.h"
#include "vector_algebraic_operations.h"

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
