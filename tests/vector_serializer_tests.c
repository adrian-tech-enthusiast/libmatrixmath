#include <stdio.h>
#include <stdlib.h>
#include "../include/matrixmath_serializer.h"
#include "vector_serializer_tests.h"

/**
 * {@inheritdoc}
 */
int vector_serialize_tests() {
  printf("------------ Vector Serialize Tests. ------------\n");
  // Create an vector of #20 elements.
  int capacity = 2;
  struct vector *vector_object = vector_create(capacity);
  // Fill in the vector.
  vector_setl(vector_object, 0, 0.0000000000045);
  vector_setl(vector_object, 1, 320.2519111111193);
  // Serialize the vector.
  char *vector_string = vector_serialize(vector_object);
  if (vector_string != NULL) {
    printf("Serialized Vector String: %s \n", vector_string);
    free(vector_string);
  }
  // Print the vector.
  vector_print(vector_object);
  // Clear the used memory.
  vector_destroy(vector_object);
  // Return success response.
  return 0;
}

/**
 * {@inheritdoc}
 */
int vector_unserialize_tests() {
  printf("------------ Vector Un-Serialize Tests. ------------\n");
  // Define the vector string representation.
  char *vector_string = "[\"0.0000000000045\",\"320.2519111111193\"]";
  // Unserialize the vector string
  struct vector *vector_object = vector_unserialize(vector_string);
  if (vector_object == NULL) {
    return EXIT_FAILURE;
  }
  printf("Vector String: %s.\n", vector_string);
  // Print the vector.
  printf("Unserialized ");
  vector_print(vector_object);
  // Clear the used memory.
  vector_destroy(vector_object);
  return EXIT_SUCCESS;
}

/**
 * {@inheritdoc}
 */
int vector_serializer_tests() {
  if (vector_serialize_tests() == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }
  if (vector_unserialize_tests() == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
