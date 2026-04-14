
#ifndef ML_H
#define ML_H
#include "lib3man.h"
#include "csv.h"

void csv_linear_regression(CSV *csv, size_t iter, sv *cols, size_t count);
void linear_regression(size_t iter, sv *cols, size_t count);


#endif