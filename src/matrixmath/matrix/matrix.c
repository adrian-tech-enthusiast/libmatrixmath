#include <stdlib.h>
#include "../../../include/matrixmath.h"

/**
 * {@inheritdoc}
 */
struct matrix *matrix_create(const int rows, const int columns) {
  if (!(rows > 0) || !(columns > 0)) {
    // Matrix with no capacity not allowed.
    return NULL;
  }
  // Allocate matrix memory space.
  size_t size = sizeof(struct matrix);
  struct matrix *object = (struct matrix *)malloc(size);
  if (object == NULL) {
    return NULL;
  }
  // Init matrix object properties.
  object->rows = rows;
  object->columns = columns;
  // Try to set the requested matrix capacity.
  size_t matrix_size = sizeof(struct vector *) * object->rows;
  object->items = (void **)malloc(matrix_size);
  if (object->items == NULL) {
    matrix_destroy(object);
    return NULL;
  }
  // Initialize the mtrix row/columns elements.
  for (int i = 0; i < object->rows; i++) {
    object->items[i] = vector_create(object->columns);
    if (object->items[i] == NULL) {
      matrix_destroy(object);
      return NULL;
    }
  }
  // Return the vector object.
  return object;
}

/**
 * {@inheritdoc}
 */
void matrix_destroy(struct matrix *object) {
  if (object == NULL) {
    return;
  }
  // Free the object items.
  for (int i = 0; i < object->rows; i++) {
    if (object->items[i] != NULL) {
      vector_destroy(object->items[i]);
    }
  }
  free(object->items);
  object->items = NULL;
  // Free the object.
  free(object);
  object = NULL;
}

/**
 * {@inheritdoc}
 */
int matrix_check_boundaries(struct matrix *object, int j, int k) {
  if (j >= 0 && j < object->rows && k >= 0 && k < object->columns) {
    return 1;
  }
  return 0;
}

/**
 * {@inheritdoc}
 */
long double *matrix_setl(struct matrix *object, int j, int k, long double value) {
  // Check if the requested positions are valid.
  if (matrix_check_boundaries(object, j, k) == 0) {
    return NULL;
  }
  // Get the vector in the position j.
  struct vector *vector_object = object->items[j];
  if (vector_object == NULL) {
    return NULL;
  }
  // Store the value in the vector in the k position.
  return vector_setl(vector_object, k, value);
}

/**
 * {@inheritdoc}
 */
long double *matrix_getl(struct matrix *object, int j, int k) {
  // Check if the requested positions are valid.
  if (matrix_check_boundaries(object, j, k) == 0) {
    return NULL;
  }
  // Get the vector in the position j.
  struct vector *vector_object = object->items[j];
  if (vector_object == NULL) {
    return NULL;
  }
  // Get the value from the vector in the k position.
  return vector_getl(vector_object, k);
}

/**
 * {@inheritdoc}
 */
struct matrix *matrix_from_array(long double *array, const int rows, const int columns) {
  struct matrix *object = matrix_create(rows, columns);
  if (object == NULL) {
    return NULL;
  }
  matrix_fill_from_array(array, object, rows, columns);
  return object;
}

/**
 * {@inheritdoc}
 */
void matrix_fill_from_array(long double *array, struct matrix *object, const int rows, const int columns) {
  if (object == NULL) {
    return;
  }
  int j, k;
  long double *value;
  for (j = 0; j < rows; j++) {
    for (k = 0; k < columns; k++) {
      value = (array + j * columns) + k;
      matrix_setl(object, j, k, *value);
    }
  }
}

/**
 * {@inheritdoc}
 */
void matrix_fill(struct matrix *object, const long double value) {
  for (size_t j = 0; j < object->rows; j++) {
    for (size_t k = 0; k < object->columns; k++) {
      matrix_setl(object, j, k, value);
    }
  }
}
