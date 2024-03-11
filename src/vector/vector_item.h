#ifndef VECTOR_ITEM_H
#define VECTOR_ITEM_H

/**
 * The data struct definition for an individual vector item object.
 */
struct vector_item
{

   /**
    * The item key used for indexing.
    *
    * @var int key.
    */
   int key;

   /**
    * The value for the current entry.
    *
    * @var void* value.
    */
   void *value;
};

/**
 * Free the memory associted to a vector item object.
 *
 * @param struct vector_item* object
 *   The vector_item object to be clean.
 */
void vector_item_destroy(struct vector_item *object);

/*
 * Create a new vector item object.
 *
 * @param int index
 *   The index position of the vector item.
 * @param void *value
 *   The value to be stored in the vector item.
 *
 * @return struct vector_item *
 *   The pointer to the vector item object, otherwise NULL.
 */
struct vector_item *vector_item_set(int index, void *value);

/*
 * Get the value of the given vector item object.
 *
 * @param struct vector_item* object
 *   The vector_item object to retrieve the value from.
 *
 * @return void *
 *   A pointer to the value stored in the item, otherwise NULL
 */
void *vector_item_get(struct vector_item *object);

#endif
