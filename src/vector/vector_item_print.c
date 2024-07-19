#include <stdio.h>
#include <stdlib.h>
#include "vector_item_print.h"

/**
 * {@inheritdoc}
 */
void vector_item_print(struct vector_item *object) {
  if (object == NULL) {
    return;
  }
  if (object->value == NULL) {
    return;
  }
  // @todo: Add support for multiple types.
  long double *lvalue = (long double *)object->value;
  printf("   %.13Lf\n", *lvalue);
}
