
#ifndef ML_H
#define ML_H
#include "lib3man.h"
#include "csv.h"

typedef struct min_max{
    f64 min;
    f64 max;
}min_max;

void csv_linear_regression(CSV *csv, size_t iter, sv *cols, size_t count);
void linear_regression(size_t iter, f64 *values,f64 *result ,size_t count);

// void linear_regression(size_t iter, f64 *values,f64 *result , min_max x, min_max y, size_t count);
#endif