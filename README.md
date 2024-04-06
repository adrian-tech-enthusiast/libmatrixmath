# Lib Matrix Math: A high-performance C library for efficient Linear Algebra computations with essential functionality for matrix and vector operations.

Welcome to the C Matrix Math Library, A robust C library tailored for linear algebra computations, offering essential functionality for matrix and vector operations. Whether you're a beginner or an experienced developer, this library provides a powerful toolkit to handle various mathematical tasks with ease.

Equipped with optimized algorithms and a user-friendly API, it provides the foundation for efficient numerical computations in diverse fields such as scientific computing, machine learning, and computer graphics. Simplify complex mathematical tasks and accelerate your projects with ease using this versatile and reliable tool.

## Features

- **Matrix Operations**: Perform common matrix operations such as addition, subtraction, multiplication, and transposition.
- **Vector Operations**: Efficiently handle vector manipulations including dot product, cross product, and vector scaling.
- **Documentation**: Comprehensive documentation and examples are provided to help you get started quickly and easily.
- **Open Source**: The library is open source and actively maintained, allowing for community contributions and enhancements.

## Prerequisites

- C compiler (e.g., GCC, Clang)
- Make build system (optional)

## Getting Started

To get started with the C Matrix Math Library, simply clone the repository and follow the installation instructions below, once installed, explore the documentation and examples to start incorporating LSTM functionality into your C projects.

## Installation

To make sure you obtain the most updated stable version of Docker Compose, you’ll download this software from its [official Github repository](https://github.com/adrian-tech-enthusiast/libmatrixmath).

First, confirm the latest version available in their [releases page](https://github.com/adrian-tech-enthusiast/libmatrixmath/releases). At the time of this writing, the most current stable version is `1.0.1`.

1. The following command will download the `1.0.1` release and save the shared library file at /usr/local/lib/libmatrixmath.so, which will make this library globally accessible to clients:

    ```bash
    sudo curl -L "https://github.com/adrian-tech-enthusiast/libmatrixmath/releases/download/v1.0.1/libmatrixmath.so" -o /usr/local/lib/libmatrixmath.so
    ```

2. Next, We need to tell the loader it is available for use, so let us update the cache, invoke the `ldconfig` utility, which configures the system's dynamic loader. This configuration ensures that the loader will find the newly published library:

    ```bash
    sudo ldconfig;
    ```

    That should create a link to our shared library and update the cache so it is available for immediate use. To verify you can run:

    ```bash
    ldconfig -p | grep matrixmath
    ```

3. Copy the library header file(`matrixmath.h`) in one of the C compiler's search path. Typical locations are `/usr/include` and `/usr/local/include`;

    ```bash
    sudo curl -L "https://raw.githubusercontent.com/adrian-tech-enthusiast/libmatrixmath/v1.0.1/include/matrixmath.h" -o /usr/local/include/matrixmath.h;
    ```

    This allows the library header file to be included in your C project:

    ```c
    #include <stdio.h>  /* standard input/output functions */
    #include <matrixmath.h> /* C Matrix Math Library functions */
    ```
    Without this `#include`, the compiler would complain about missing declarations for functions provided by the C Matrix Math Library. 

4. Finally add the link library flag during the compilation of your C project: 

    ```bash
    gcc -o tester tester.c -lmatrixmath
    ```

## Example Usage

Here's a basic example demonstrating how to use CMatrixMath to perform matrix multiplication:

```c
#include <stdio.h>
#include "matrixmath.h"

int main() {
    // Define matrices A and B
    double A_data[2][2] = {{1, 2}, {3, 4}};
    double B_data[2][2] = {{5, 6}, {7, 8}};
    Matrix A = create_matrix_from_array(2, 2, (double*)A_data);
    Matrix B = create_matrix_from_array(2, 2, (double*)B_data);

    // Perform matrix multiplication: C = A * B
    Matrix C = matrix_multiply(A, B);

    // Print the result
    printf("Result of A * B:\n");
    print_matrix(C);

    // Free allocated memory
    free_matrix(A);
    free_matrix(B);
    free_matrix(C);

    return 0;
}
```

## Contributions

Contributions to the C Matrix Math Library are welcome! Whether it's reporting issues, suggesting new features, or submitting pull requests, we appreciate any and all contributions from the community.

If you'd like to contribute, please follow these steps:

1. Fork the repository
2. Create your feature branch (git checkout -b feature/my-feature)
3. Commit your changes (git commit -am 'Add my feature')
4. Push to the branch (git push origin feature/my-feature)
5. Create a new Pull Request

## License

This library is licensed under the `GNU General Public License v3.0` License. See the LICENSE file for details.

## Acknowledgments

- Inspired by the need for efficient linear algebra operations in C.
- Special thanks to contributors and open-source libraries that provided inspiration and guidance.
