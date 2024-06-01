#include <stdlib.h>
#include "../../include/matrixmath.h"

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

/**
 * {@inheritdoc}
 */
struct vector *matrix_to_vector(struct matrix *m) {
  // Verify if it is a matrix with a single row and multiple columns.
  if (m->rows == 1) {
    // Create the new Vector to store the result of the operation.
    struct vector *v = vector_create(m->columns);
    if (v == NULL) {
      return NULL;
    }
    long double *val;
    for (int i = 0; i < m->columns; i++) {
      val = matrix_getl(m, 0, i);
      vector_setl(v, i, *val);
    }
    return v;
  }
  // Otherwise, assume it is a matrix with a single column and multiple rows.
  struct vector *v = vector_create(m->rows);
  if (v == NULL) {
    return NULL;
  }
  long double *val;
  for (int i = 0; i < m->rows; i++) {
    val = matrix_getl(m, i, 0);
    vector_setl(v, i, *val);
  }
  return v;
}
