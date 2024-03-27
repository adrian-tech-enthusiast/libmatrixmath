#include <stdlib.h>
#include "matrix_casting.h"

/**
 * {@inheritdoc}
 */
struct matrix *vector_to_matrix(struct vector *a)
{
   // Create the new matrix.
   struct matrix *object = matrix_create(a->capacity, 1);
   if (object == NULL)
   {
      return NULL;
   }
   // Set the matrix row/columns elements.
   long double *set_val;
   long double *get_val;
   for (int i = 0; i < a->capacity; i++)
   {
      set_val = vector_getl(a, i);
      if (set_val == NULL)
      {
         matrix_destroy(object);
         return NULL;
      }
      get_val = matrix_setl(object, i, 0, (*set_val));
      if (get_val == NULL)
      {
         matrix_destroy(object);
         return NULL;
      }
   }
   // Return the matrix object.
   return object;
}
