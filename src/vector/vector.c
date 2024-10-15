#include <stdlib.h>
#include "../../include/matrixmath.h"
#include "vector_item.h"

/**
 * {@inheritdoc}
 */
struct vector *vector_create(const int capacity) {
  if (capacity <= 0) {
    // Vector with no capacity not allowed.
    return NULL;
  }
  // Allocate vector memory space.
  size_t size = sizeof(struct vector);
  struct vector *object = malloc(size);
  if (object == NULL) {
    return NULL;
  }
  // Init vector object properties.
  object->capacity = capacity;
  // Try to set the requested vector capacity.
  size_t items_size = sizeof(struct _vector_item *) * object->capacity;
  object->items = malloc(items_size);
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
struct vector *vector_create_zeros(const int capacity) {
  // Reuse the generalized function to create a vector with a specific default value.
  return vector_create_with_value(capacity, 0);
}

/**
 * {@inheritdoc}
 */
struct vector *vector_create_with_value(const int capacity, long double default_value) {
  // Create a new vector object instance.
  struct vector *object = vector_create(capacity);
  if (object == NULL) {
    return NULL;
  }
  // Fill the vector with the provided default value.
  vector_fill(object, default_value);
  // Return the vector object.
  return object;
}

/**
 * {@inheritdoc}
 */
struct vector *vector_create_random(const int capacity, const long double min, const long double max) {
  // Create a new vector object instance.
  struct vector *object = vector_create(capacity);
  if (object == NULL) {
    return NULL;
  }
  // Fill vector with random values between min and max.
  vector_fill_random(object, min, max);
  // Return the vector object.
  return object;
}

/**
 * {@inheritdoc}
 */
struct vector **vector_create_multiple(int size) {
  // Ensure size is valid.
  if (size <= 0) {
    return NULL;
  }
  // Try to set the requested the items memory.
  size_t items_size = sizeof(struct vector *) * size;
  struct vector **items = malloc(items_size);
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
  if (object->items != NULL) {
    for (int i = 0; i < object->capacity; i++) {
      if (object->items[i] != NULL) {
        vector_item_destroy(object->items[i]);
        object->items[i] = NULL;
      }
    }
    free(object->items);
    object->items = NULL;
  }
  object->capacity = 0;
  // Free the object.
  free(object);
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
  // Check for NULL or invalid size.
  if (items == NULL || size <= 0) {
    return;
  }
  for (size_t i = 0; i < size; i++) {
    vector_destroy(items[i]);
  }
  free(items);
}

/**
 * {@inheritdoc}
 */
long double *vector_setl(struct vector *object, int index, long double value) {
  // Check for valid index.
  if (object == NULL || index < 0 || index >= object->capacity) {
    // Index out of bounds.
    return NULL;
  }
  // Create void pointer with the value.
  size_t size = sizeof(long double);
  long double *item_value = malloc(size);
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
  // Check for valid index
  if (object == NULL || index < 0 || index >= object->capacity) {
    // Index out of bounds.
    return NULL;
  }
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
  // Ensure both vectors are valid.
  if (a == NULL || b == NULL) {
    return NULL;
  }
  int capacity = a->capacity + b->capacity;
  // Create the new vector to store the result of the operation.
  struct vector *result = vector_create(capacity);
  if (result == NULL) {
    return NULL;
  }
  // Copy values from vector a.
  long double *val;
  for (size_t i = 0; i < a->capacity; i++) {
    val = vector_getl(a, i);
    if (val == NULL) {
      vector_destroy(result);
      return NULL;
    }
    vector_setl(result, i, *val);
  }
  // Copy values from vector b.
  size_t start = a->capacity;
  for (size_t j = 0; j < b->capacity; j++) {
    val = vector_getl(b, j);
    if (val == NULL) {
      vector_destroy(result);
      return NULL;
    }
    vector_setl(result, (start + j), *val);
  }
  // Return the result of the operation.
  return result;
}

/**
 * {@inheritdoc}
 */
struct vector *vector_clone(struct vector *a) {
  // Ensure the source vector is valid.
  if (a == NULL) {
    return NULL;
  }
  // Create the new vector to store the result of the operation.
  struct vector *result = vector_create(a->capacity);
  if (result == NULL) {
    return NULL;
  }
  // Copy values from vector a.
  long double *val;
  for (size_t i = 0; i < a->capacity; i++) {
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
  // Check for NULL pointers.
  if (a == NULL || callback == NULL) {
    return 0;
  }
  long double *val;
  for (size_t i = 0; i < a->capacity; i++) {
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
  // Check for NULL vector object.
  if (object == NULL) {
    return;
  }
  for (size_t i = 0; i < object->capacity; i++) {
    vector_setl(object, i, value);
  }
}

/**
 * Generate a random long double value between a specified range.
 *
 * This function generates a random floating-point value between the provided
 * `min` and `max` values using a uniform distribution. It uses the `rand()`
 * function to generate a random integer and scales it to the desired range by
 * normalizing the result to a floating-point number between 0 and 1, then scaling
 * it to fit within the specified bounds.
 *
 * Note: The function relies on the standard `rand()` function, which provides
 * limited precision and should be seeded with `srand()` before use in the program.
 * For applications that require higher precision or different distributions,
 * consider using other random number generators.
 *
 * @param long double min
 *   The minimum possible value in the generated range.
 * @param long double max
 *   The maximum possible value in the generated range.
 *
 * @return
 *   A random long double between `min` and `max`.
 */
static long double random_long_double(long double min, long double max) {
  // Random number between 0 and 1.
  long double scale = rand() / (long double)RAND_MAX;
  // Scale it to the desired range.
  return min + scale * (max - min);
}

/**
 * {@inheritdoc}
 */
void vector_fill_random(struct vector *object, const long double min, const long double max) {
  // Handle NULL vector object.
  if (object == NULL) {
    return;
  }
  // Assign a random value to each element in the vector.
  for (size_t i = 0; i < object->capacity; i++) {
    vector_setl(object, i, random_long_double(min, max));
  }
}

/**
 * {@inheritdoc}
 */
int vector_copy(struct vector *src, struct vector *dest) {
  // Ensure both source and destination are valid.
  if (src == NULL || dest == NULL) {
    return 1;
  }
  // Ensure destination capacity is sufficient.
  if (dest->capacity < src->capacity) {
    return 1;
  }
  long double *val;
  for (size_t i = 0; i < src->capacity; i++) {
    val = vector_getl(src, i);
    if (val != NULL) {
      vector_setl(dest, i, *val);
    }
  }
  return 0;
}
