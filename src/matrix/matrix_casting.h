#ifndef MATRIX_CASTING_H
#define MATRIX_CASTING_H

#include "../vector/vector.h"
#include "matrix.h"

/*
 * Convert the given vector into a one column matrix.
 *
 * @param struct vector* a
 *   The vector object to be type casted.
 *
 * @return struct matrix*
 *   The pointer to the new matrix instance, otherwise NULL.
 */
struct matrix *vector_to_matrix(struct vector *a);

#endif
