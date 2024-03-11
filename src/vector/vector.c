#include <stdlib.h>
#include "vector.h"
#include "vector_item.h"

/**
 * {@inheritdoc}
 */
struct vector *vector_create(const int capacity)
{
   if (!(capacity > 0))
   {
      // Vector with no capacity not allowed.
      return NULL;
   }
   // Allocate vector memory space.
   size_t size = sizeof(struct vector);
   struct vector *object = (struct vector *)malloc(size);
   if (object == NULL)
   {
      return NULL;
   }
   // Init vector object properties.
   object->capacity = capacity;
   // Try to set the requested vector capacity.
   size_t items_size = sizeof(struct _vector_item *) * object->capacity;
   object->items = (void **)malloc(items_size);
   if (object->items == NULL)
   {
      vector_destroy(object);
      return NULL;
   }
   // NULL initialize the vector items.
   for (int i = 0; i < object->capacity; i++)
   {
      object->items[i] = NULL;
   }
   // Return the vector object.
   return object;
}

/**
 * {@inheritdoc}
 */
void vector_destroy(struct vector *object)
{
   if (object == NULL)
   {
      return;
   }
   // Free the object properties.
   for (int i = 0; i < object->capacity; i++)
   {
      vector_item_destroy(object->items[i]);
   }
   object->capacity = 0;
   // Free the object.
   free(object);
   object = NULL;
}

/**
 * {@inheritdoc}
 */
long double *vector_setl(struct vector *object, int index, long double value)
{
   // Create void pointer with the value.
   size_t size = sizeof(long double);
   long double *item_value = (long double *)malloc(size);
   if (item_value == NULL)
   {
      return NULL;
   }
   *item_value = value;
   // Create item.
   void *item = vector_item_set(index, item_value);
   if (item == NULL)
   {
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
long double *vector_getl(struct vector *object, int index)
{
   void *item = object->items[index];
   if (item == NULL)
   {
      return NULL;
   }
   void *value = vector_item_get(item);
   if (value == NULL)
   {
      return NULL;
   }
   return (long double *)value;
}
