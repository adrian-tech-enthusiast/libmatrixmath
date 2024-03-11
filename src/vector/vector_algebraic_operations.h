#ifndef VECTOR_ALGEBRAIC_OPERATIONS_H
#define VECTOR_ALGEBRAIC_OPERATIONS_H

/**
 * Vector addition.
 *
 * @param struct vector* a
 *   The first vector object to be added.
 * @param struct vector* b
 *   The second vector object to be added.
 *
 * @return struct vector*
 *   The new vector instance with the sum of the two given vectors; otherwise NULL.
 */
struct vector *vector_add(struct vector *a, struct vector *b);

/**
 * Vector subtraction.
 *
 * @param struct vector* a
 *   The first vector object to be subtracted.
 * @param struct vector* b
 *   The second vector object to be subtracted.
 *
 * @return struct vector*
 *   The new vector instance with the subtraction of the two given vectors; otherwise NULL.
 */
struct vector *vector_sub(struct vector *a, struct vector *b);

#endif
