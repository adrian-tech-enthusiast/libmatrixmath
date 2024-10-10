#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
long double normalize_minmaxl(long double x, long double min, long double max) {
  return (RANGE_MAX - RANGE_MIN) * ((x - min) / (max - min)) + RANGE_MIN;
}

/**
 * Cube callback function.
 *
 * @param long double x
 *   The long double value.
 *
 * @return long double
 *   The value cubed.
 */
long double cube(long double x) {
  return (x * x * x);
}

/**
 * Main controller function.
 *
 * @return int
 *   The constant that represent the exit status.
 */
int vector_tests() {
  printf("------------ Vector setters and getters. ------------\n");
  // Create an vector of #20 elements.
  int capacity = 20;
  struct vector *VectorObject = vector_create(capacity);
  // Fill in the vector.
  long double value = 0;
  for (int i = 0; i < capacity; i++) {
    value = normalize_minmaxl(i, 0, capacity);
    vector_setl(VectorObject, i, value);
  }
  // Print the vector.
  vector_println(VectorObject);
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
  vector_println(a);
  vector_println(b);
  vector_println(result1);

  printf("------------ Vectors subtraction. ------------\n");
  struct vector *result2 = vector_sub(a, b);
  vector_println(a);
  vector_println(b);
  vector_println(result2);

  printf("------------ Vector multiplication: dot product. ------------\n");
  long double *scalar_result = vector_dot_product(a, b);
  vector_println(a);
  vector_println(b);
  printf("Vector multiplication - Dot product result is: [%Lf]\n", *scalar_result);

  printf("------------ Vector multiplication by a scalar[4.5]. ------------\n");
  struct vector *result3 = vector_scalar_mul(4.5, a);
  vector_println(a);
  vector_println(result3);

  printf("------------ Vector concatenation. ------------\n");
  struct vector *result4 = vector_concatenate(a, b);
  vector_println(a);
  vector_println(b);
  vector_println(result4);

  printf("------------ Vector Walk. ------------\n");
  capacity = 5;
  struct vector *result5 = vector_create(capacity);
  for (int i = 0; i < capacity; i++) {
    vector_setl(result5, i, (i + 1));
  }
  vector_println(result5);
  vector_walk(result5, &cube);
  vector_println(result5);

  printf("------------ Vector Hadamard product. ------------\n");
  vector_println(a);
  vector_println(b);
  struct vector *result6 = vector_hadamard_product(a, b);
  vector_println(result6);

  printf("------------ Vector Clone. ------------\n");
  vector_println(a);
  struct vector *result7 = vector_clone(a);
  vector_println(result7);

  // Test Vector Create Random.
  printf("------------ Vector Create Random. ------------\n");
  // Seed the random number generator with the current time.
  srandom(time(NULL));
  struct vector *vector_p = vector_create_random(capacity, 0.1, 1.0);
  struct vector *vector_q = vector_create_random(capacity, 0.1, 1.0);
  struct vector *vector_r = vector_create_random(capacity, 0.1, 1.0);

  vector_println(vector_p);
  vector_println(vector_q);
  vector_println(vector_r);

  // Clear the used memory.
  vector_destroy(a);
  vector_destroy(b);
  vector_destroy(result1);
  vector_destroy(result2);
  vector_destroy(result3);
  vector_destroy(result4);
  vector_destroy(result5);
  vector_destroy(result6);
  vector_destroy(result7);
  // Return success response.
  return 0;
}
