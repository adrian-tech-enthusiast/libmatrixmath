#ifndef MATRIX_ALGEBRAIC_OPERATIONS_H
#define MATRIX_ALGEBRAIC_OPERATIONS_H

/**
 * Matrix addition.
 *
 * @param struct matrix* a
 *   The first matrix object to be added.
 * @param struct matrix* b
 *   The second matrix object to be added.
 *
 * @return struct matrix*
 *   The new matrix instance with the sum of the two given matrixes; otherwise NULL.
 */
struct matrix *matrix_add(struct matrix *a, struct matrix *b);

/**
 * Matrix subtraction.
 *
 * @param struct matrix* a
 *   The first matrix object to be subtracted.
 * @param struct matrix* b
 *   The second matrix object to be subtracted.
 *
 * @return struct matrix*
 *   The new matrix instance with the subtraction of the two given matrixes; otherwise NULL.
 */
struct matrix *matrix_sub(struct matrix *a, struct matrix *b);

/**
 * Matrix multiplication.
 *
 * @param struct matrix* a
 *   The first matrix object to be multiplied.
 * @param struct matrix* b
 *   The second matrix object to be multiplied.
 *
 * @return struct matrix*
 *   The new matrix instance with the product of two matrixes; otherwise NULL.
 */
struct matrix *matrix_mul(struct matrix *a, struct matrix *b);

/**
 * Matrix multiplication by a scalar.
 *
 * @param long double scalar
 *   The scalar to be multiplied.
 * @param struct matrix* a
 *   The second matrix object to be multiplied.
 *
 * @return int
 *   Returns 0 when the operation succeeded, otherwise 1.
 */
int matrix_scalar_mul(long double scalar, struct matrix *a);

#endif
