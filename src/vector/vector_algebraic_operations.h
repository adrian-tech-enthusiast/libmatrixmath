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

/**
 * Vector multiplication: dot product.
 *
 * @param struct vector* a
 *   The first vector object to be multiplied.
 * @param struct vector* b
 *   The second vector object to be multiplied.
 *
 * @return long double*
 *   The pointer to the long double value from the product of two vectors; otherwise NULL.
 */
long double *vector_dot_product(struct vector *a, struct vector *b);

/**
 * Vector multiplication: cross product.
 *
 * @param struct vector* a
 *   The first vector object to be multiplied.
 * @param struct vector* b
 *   The second vector object to be multiplied.
 *
 * @return struct vector*
 *   The new vector instance with the product of two vectors; otherwise NULL.
 */
struct vector *vector_cross_product(struct vector *a, struct vector *b);

/**
 * Vector multiplication by a scalar.
 *
 * @param long double scalar
 *   The scalar to be multiplied.
 * @param struct vector* a
 *   The second vector object to be multiplied.
 *
 * @return struct vector*
 *   The new vector instance with the multiplication; otherwise NULL.
 */
struct vector *vector_scalar_mul(long double scalar, struct vector *a);

#endif
