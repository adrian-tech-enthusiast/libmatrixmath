#ifndef VECTOR_H
#define VECTOR_H

/**
 * The data struct definition for an individual vector object.
 *
 * Definition: A vector is a list of numbers.
 */
struct vector
{

   /**
    * Pointer to the vectors items in the chain.
    *
    * Allow you to walk array/object chains.
    *
    * @var void **items.
    */
   void **items;

   /**
    * The maximum amount elements that the vector instance can contain.
    *
    * @var int capacity.
    */
   int capacity;
};

/*
 * Create a new vector object instance.
 *
 * @param const int capacity
 *   The max size of the vector.
 *
 * @return struct vector*
 *   The pointer to the vector instance, otherwise NULL.
 */
struct vector *vector_create(const int capacity);

/**
 * Free the memory associted to a vector object.
 *
 * @param struct vector* object
 *   The vector object to be clean.
 */
void vector_destroy(struct vector *object);

/**
 * Sets the long double value at the specified index in the given vector.
 *
 * @param struct vector* object
 *   The vector object.
 * @param int index
 *   The position to store the given value.
 * @param long double value
 *   The value to store.
 *
 * @return long double*
 *   The pointer to the long double value stored at the given position; otherwise NULL.
 */
long double *vector_setl(struct vector *object, int index, long double value);

/**
 * Gets the long double value stored at the given index in the given vector.
 *
 * @param struct vector* object
 *   The vector object.
 * @param int index
 *   The position to store the given value.
 * @param long double value
 *
 * @return long double*
 *   The pointer to the long double value stored at the given position; otherwise NULL.
 */
long double *vector_getl(struct vector *object, int index);

#endif
