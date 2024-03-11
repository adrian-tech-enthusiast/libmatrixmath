#include <stdio.h>
#include <stdlib.h>
#include "vector_print.h"
#include "vector_item_print.h"

/**
 * {@inheritdoc}
 */
void vector_print(struct vector *object)
{
   // @todo: Complete this implementation.
   printf("Vector: {\n");
   for (int i = 0; i < object->capacity; i++)
   {
      vector_item_print(object->items[i]);
   }
   printf("} \n");
}
