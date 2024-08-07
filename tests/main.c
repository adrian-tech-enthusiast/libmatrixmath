#include "vector_tests.h"
#include "matrix_tests.h"

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
int main(int argc, char const *argv[]) {
  vector_tests();
  matrix_tests();
  // Return success response.
  return 0;
}
