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
    * @var struct vector **items.
    */
   struct vector **items;

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

#endif