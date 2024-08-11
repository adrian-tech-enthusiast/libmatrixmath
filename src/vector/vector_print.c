#include <stdio.h>
#include <stdlib.h>
#include "../../include/matrixmath.h"
#include "vector_item_print.h"

/**
 * {@inheritdoc}
 */
void vector_print(struct vector *object) {
  printf("[");
  for (int i = 0; i < object->capacity; i++) {
    // Print a comma and space to separate values after the first one.
    if (i != 0) {
      printf(", ");
    }
    // Print the current item value.
    vector_item_print(object->items[i]);
  }
  printf("]");
}

/**
 * {@inheritdoc}
 */
void vector_println(struct vector *object) {
  vector_print(object);
  printf("\n");
}
