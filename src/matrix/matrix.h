#ifndef MATRIX_H
#define MATRIX_H

/**
 * The data struct definition for an individual matrix object.
 *
 * Definition: A matrix, like a vector, is also a collection of numbers.
 * The difference is that a matrix is a table of numbers rather than a list.
 */
struct matrix
{

   /**
    * Pointer to the vectors in the chain.
    *
    * Allow you to walk array/object chains.
    *
    * @var void **items.
    */
   void **items;

   /**
    * The number of rows in the matrix.
    *
    * @var int rows.
    */
   int rows;

   /**
    * The number of columns in the matrix.
    *
    * @var int columns.
    */
   int columns;
};

/*
 * Create a new matrix object instance.
 *
 * @param const int rows
 *   The numer of rows in the matrix.
 * @param const int columns
 *   The numer of columns in the matrix.
 *
 * @return struct matrix*
 *   The pointer to the matrix instance, otherwise NULL.
 */
struct matrix *matrix_create(const int rows, const int columns);

/**
 * Free the memory associted to a matrix object.
 *
 * @param struct matrix* object
 *   The matrix object to be clean.
 */
void matrix_destroy(struct matrix *object);

/**
 * Check if the given positions j and K are valid in the given matrix object.
 *
 * @param struct matrix* object
 *   The matrix object.
 * @param int j
 *   The j position to check.
 * @param int k
 *   The k position to check.
 * @param long double value
 *   The value to store.
 *
 * @return int
 *   Returns 1 if the given positions j and K are valid, otherwise 0.
 */
int matrix_check_boundaries(struct matrix *object, int j, int k);

/**
 * Sets the long double value at the specified index in the given matrix.
 *
 * @param struct matrix* object
 *   The matrix object.
 * @param int j
 *   The j position to store the given value.
 * @param int k
 *   The k position to store the given value.
 * @param long double value
 *   The value to store.
 *
 * @return long double*
 *   The pointer to the long double value stored at the given position; otherwise NULL.
 */
long double *matrix_setl(struct matrix *object, int j, int k, long double value);

/**
 * Gets the long double value stored at the given index in the given matrix.
 *
 * @param struct matrix* object
 *   The matrix object.
 * @param int j
 *   The x position to store the given value.
 * @param int k
 *   The y position to store the given value.
 * @param long double value
 *
 * @return long double*
 *   The pointer to the long double value stored at the given position; otherwise NULL.
 */
long double *matrix_getl(struct matrix *object, int j, int k);

#endif