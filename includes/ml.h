
#ifndef ML_H
#define ML_H
#include "lib3man.h"
#include "csv.h"

typedef struct min_max{
    f64 min;
    f64 max;
}min_max;

typedef struct Matrix{
    f64    *mtx;
    size_t rows;
    size_t cols;
}Matrix;

Matrix matrix_create(size_t rows, size_t cols);
int matrix_fill(Matrix *matrix, f64 value);
void matrix_add(Matrix *a, Matrix b);
void matrix_scale(Matrix *matrix, f64 k);
void matrix_print(Matrix matrix);
void csv_linear_regression(CSV *csv, size_t iter, sv *cols, size_t count);
void linear_regression(size_t iter, f64 *values,f64 *result ,size_t count);
void linear_regressionLS(f64 *values,f64 *result ,size_t count);

// void linear_regression(size_t iter, f64 *values,f64 *result , min_max x, min_max y, size_t count);
#endif