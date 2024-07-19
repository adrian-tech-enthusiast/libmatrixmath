#include <stdlib.h>
#include "vector_item.h"

/**
 * {@inheritdoc}
 */
void vector_item_destroy(struct vector_item *object) {
  if (object == NULL) {
    return;
  }
  // Clean the object properties.
  object->key = 0;
  if (object->value != NULL) {
    free(object->value);
    object->value = NULL;
  }
  // Free the item object.
  free(object);
  object = NULL;
}

/**
 * {@inheritdoc}
 */
struct vector_item *vector_item_set(int index, void *value) {
  // Allocate vector item memory space.
  size_t size = sizeof(struct vector_item);
  struct vector_item *object = (struct vector_item *)malloc(size);
  if (object == NULL) {
    return NULL;
  }
  // Init vector item object properties.
  object->key = index;
  object->value = value;
  // Return the vector item object.
  return object;
}

/**
 * {@inheritdoc}
 */
void *vector_item_get(struct vector_item *object) {
  if (object == NULL) {
    return NULL;
  }
  return object->value;
}
