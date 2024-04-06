#include <stdio.h>
#include "../include/matrixmath.h"
#include "vector_tests.h"

/**
 * Data min and max value.
 *
 * @todo: move this to the scaler and to the function params.
 */
#define RANGE_MIN -1
#define RANGE_MAX 1

/**
 * Scale a long double value to a range.
 *
 * @param long double x
 *   The long double value.
 * @param long double min
 *   The minimum value of the feature.
 * @param long double max
 *   The maximum value of the feature.
 *
 * @return long double
 *   The normalized value.
 */
long double normalize_minmaxl(long double x, long double min, long double max)
{
   return (RANGE_MAX - RANGE_MIN) * ((x - min) / (max - min)) + RANGE_MIN;
}

/**
 * Main controller function.
 *
 * @return int
 *   The constant that represent the exit status.
 */
int vector_tests()
{
   printf("------------ Vector setters and getters. ------------\n");
   // Create an vector of #20 elements.
   int capacity = 20;
   struct vector *VectorObject = vector_create(capacity);
   // Fill in the vector.
   long double value = 0;
   for (int i = 0; i < capacity; i++)
   {
      value = normalize_minmaxl(i, 0, capacity);
      vector_setl(VectorObject, i, value);
   }
   // Print the vector.
   vector_print(VectorObject);
   // Get value at a specific position.
   long double *item_value = vector_getl(VectorObject, 2);
   printf("The value at position 2 is: [%Lf]\n", *item_value);
   item_value = vector_getl(VectorObject, 10);
   printf("The value at position 10 is: [%Lf]\n", *item_value);
   // Clear the used memory.
   vector_destroy(VectorObject);

   printf("------------ Vectors addition. ------------\n");
   capacity = 2;
   struct vector *a = vector_create(capacity);
   vector_setl(a, 0, 4);
   vector_setl(a, 1, 3);

   struct vector *b = vector_create(capacity);
   vector_setl(b, 0, 1);
   vector_setl(b, 1, 2);

   struct vector *result1 = vector_add(a, b);
   vector_print(a);
   vector_print(b);
   vector_print(result1);

   printf("------------ Vectors subtraction. ------------\n");
   struct vector *result2 = vector_sub(a, b);
   vector_print(a);
   vector_print(b);
   vector_print(result2);

   printf("------------ Vector multiplication: dot product. ------------\n");
   long double *scalar_result = vector_dot_product(a, b);
   vector_print(a);
   vector_print(b);
   printf("Vector multiplication - Dot product result is: [%Lf]\n", *scalar_result);

   printf("------------ Vector multiplication by a scalar[4.5]. ------------\n");
   struct vector *result3 = vector_scalar_mul(4.5, a);
   vector_print(a);
   vector_print(result3);

   printf("------------ Vector concatenation. ------------\n");
   struct vector *result4 = vector_concatenate(a, b);
   vector_print(a);
   vector_print(b);
   vector_print(result4);

   // Clear the used memory.
   vector_destroy(a);
   vector_destroy(b);
   vector_destroy(result1);
   vector_destroy(result2);
   vector_destroy(result3);
   vector_destroy(result4);

   // Return success response.
   return 0;
}
