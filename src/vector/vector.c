#include <stdlib.h>
#include "../../include/matrixmath.h"
#include "vector_item.h"

/**
 * {@inheritdoc}
 */
struct vector *vector_create(const int capacity) {
  if (!(capacity > 0)) {
    // Vector with no capacity not allowed.
    return NULL;
  }
  // Allocate vector memory space.
  size_t size = sizeof(struct vector);
  struct vector *object = (struct vector *)malloc(size);
  if (object == NULL) {
    return NULL;
  }
  // Init vector object properties.
  object->capacity = capacity;
  // Try to set the requested vector capacity.
  size_t items_size = sizeof(struct _vector_item *) * object->capacity;
  object->items = (void **)malloc(items_size);
  if (object->items == NULL) {
    vector_destroy(object);
    return NULL;
  }
  // NULL initialize the vector items.
  for (int i = 0; i < object->capacity; i++) {
    object->items[i] = NULL;
  }
  // Return the vector object.
  return object;
}

/**
 * {@inheritdoc}
 */
struct vector **vector_create_multiple(int size) {
  // Try to set the requested the items memory.
  size_t items_size = sizeof(struct vector *) * size;
  struct vector **items = (struct vector **)malloc(items_size);
  return items;
}

/**
 * {@inheritdoc}
 */
void vector_destroy(struct vector *object) {
  if (object == NULL) {
    return;
  }
  // Free the object items.
  for (int i = 0; i < object->capacity; i++) {
    vector_item_destroy(object->items[i]);
  }
  free(object->items);
  object->items = NULL;
  object->capacity = 0;
  // Free the object.
  free(object);
  object = NULL;
}

/**
 * Destroys multiple vectors.
 *
 * @param struct vector **items
 *   The list of vectors to destroy.
 * @param int size
 *   The number of vectors to destroy.
 */
void vector_destroy_multiple(struct vector **items, int size) {
  for (size_t i = 0; i < size; i++) {
    vector_destroy(items[i]);
  }
  free(items);
  items = NULL;
}

/**
 * {@inheritdoc}
 */
long double *vector_setl(struct vector *object, int index, long double value) {
  // Create void pointer with the value.
  size_t size = sizeof(long double);
  long double *item_value = (long double *)malloc(size);
  if (item_value == NULL) {
    return NULL;
  }
  *item_value = value;
  // Create item.
  void *item = vector_item_set(index, item_value);
  if (item == NULL) {
    free(item_value);
    return NULL;
  }
  object->items[index] = item;
  // Return the pointer to the value stored.
  return item_value;
}

/**
 * {@inheritdoc}
 */
long double *vector_getl(struct vector *object, int index) {
  void *item = object->items[index];
  if (item == NULL) {
    return NULL;
  }
  void *value = vector_item_get(item);
  if (value == NULL) {
    return NULL;
  }
  return (long double *)value;
}

/**
 * {@inheritdoc}
 */
struct vector *vector_concatenate(struct vector *a, struct vector *b) {
  int capacity = a->capacity + b->capacity;
  // Create the new vector to store the result of the operation.
  struct vector *result = vector_create(capacity);
  if (result == NULL) {
    return NULL;
  }
  // Copy values from vector a.
  long double *val;
  for (int i = 0; i < a->capacity; i++) {
    val = vector_getl(a, i);
    if (val == NULL) {
      free(result);
      return NULL;
    }
    vector_setl(result, i, (*val));
  }
  // Copy values from vector b.
  int start = a->capacity;
  for (int j = 0; j < b->capacity; j++) {
    val = vector_getl(b, j);
    if (val == NULL) {
      free(result);
      return NULL;
    }
    vector_setl(result, (start + j), (*val));
  }
  // Return the result of the operation.
  return result;
}

/**
 * {@inheritdoc}
 */
struct vector *vector_clone(struct vector *a) {
  // Create the new vector to store the result of the operation.
  struct vector *result = vector_create(a->capacity);
  if (result == NULL) {
    return NULL;
  }
  // Copy values from vector a.
  long double *val;
  for (int i = 0; i < a->capacity; i++) {
    val = vector_getl(a, i);
    if (val != NULL) {
      vector_setl(result, i, (*val));
    }
  }
  // Return the result of the operation.
  return result;
}

/**
 * {@inheritdoc}
 */
int vector_walk(struct vector *a, long double (*callback)(long double)) {
  long double *val;
  for (int i = 0; i < a->capacity; i++) {
    val = vector_getl(a, i);
    if (val == NULL) {
      return 0;
    }
    vector_setl(a, i, callback(*val));
  }
  return 1;
}

/**
 * {@inheritdoc}
 */
void vector_fill(struct vector *object, const long double value) {
  for (size_t i = 0; i < object->capacity; i++) {
    vector_setl(object, i, value);
  }
}

/**
 * {@inheritdoc}
 */
int vector_copy(struct vector *src, struct vector *dest) {
  if (src == NULL || dest == NULL || src->capacity != dest->capacity) {
    return 1;
  }
  long double *val;
  for (int i = 0; i < src->capacity; i++) {
    val = vector_getl(src, i);
    vector_setl(dest, i, *val);
  }
  return 0;
}
