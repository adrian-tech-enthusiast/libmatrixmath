#include <stdio.h>
#include "vector/vector.h"
#include "vector/vector_print.h"
#include "vector/vector_algebraic_operations.h"

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
 * @param int argc
 *   The number of arguments passed by the user in the command line.
 * @param array argv
 *   Array of char, the arguments names.
 *
 * @return int
 *   The constant that represent the exit status.
 */
int main(int argc, char const *argv[])
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
   // Get value at a specific position.
   long double *item_value = vector_getl(VectorObject, 2);
   printf("The value at position 2 is: [%Lf]\n", *item_value);
   item_value = vector_getl(VectorObject, 10);
   printf("The value at position 10 is: [%Lf]\n", *item_value);
   // Print the vector.
   vector_print(VectorObject);
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

   struct vector *result = vector_add(a, b);
   vector_print(a);
   vector_print(b);
   vector_print(result);

   printf("------------ Vectors subtraction. ------------\n");
   result = vector_sub(a, b);
   vector_print(a);
   vector_print(b);
   vector_print(result);

   // Clear the used memory.
   vector_destroy(a);
   vector_destroy(b);
   vector_destroy(result);

   // Return success response.
   return 0;
}
