#include <stdio.h>
#include <stdlib.h>
#include "../../include/matrixmath.h"

/**
 * {@inheritdoc}
 */
void matrix_print(struct matrix *object) {
  printf("{\n");
  long double *lvalue;
  for (int j = 0; j < object->rows; j++) {
    printf(" [");
    for (int k = 0; k < object->columns; k++) {
      lvalue = matrix_getl(object, j, k);
      printf(" %Lf ", *lvalue);
    }
    printf("]\n");
  }
  printf("}\n");
}
