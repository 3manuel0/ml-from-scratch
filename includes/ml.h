
#ifndef ML_H
#define ML_H
#include "lib3man.h"
#include "csv.h"

#ifdef _WIN32
  #include <windows.h>
  #include <bcrypt.h>
  #pragma comment(lib, "bcrypt.lib")

#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
  #include <stdlib.h> // arc4random_buf

#else
  #include <sys/random.h>
  #include <errno.h>
#endif

typedef struct min_max{
    f64 min;
    f64 max;
}min_max;

typedef struct Matrix{
    f64    *mtx;
    size_t rows;
    size_t cols;
}Matrix;


f64 relu(f64 n);// ReLU (Rectified Linear Unit)

f64 sigmoid(f64 n);// sigmoid

Matrix matrix_create(size_t rows, size_t cols);

int matrix_fill(Matrix *matrix, f64 value);

void matrix_randomize(Matrix* matrix, f64 min, f64 max);

void matrix_add(Matrix *a, Matrix b);

void matrix_sub(Matrix *a, Matrix b);

void matrix_scale(Matrix *matrix, f64 k);

Matrix matrix_copy(Matrix src);

void matrix_map(Matrix *matrix, f64(*func)(f64));

void matrix_print(Matrix matrix);

void matrix_free(Matrix *matrix);

void csv_linear_regression(CSV *csv, size_t iter, sv *cols, size_t count);

void linear_regression(size_t iter, f64 *values,f64 *result ,size_t count);

void linear_regressionLS(f64 *values,f64 *result ,size_t count);

// void linear_regression(size_t iter, f64 *values,f64 *result , min_max x, min_max y, size_t count);

double random_range(double min, double max);

u32 u32_random(void);
#endif