
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

f64 relu(f64 n);// ReLU (Rectified Linear Unit)

f64 sigmoid(f64 n);// sigmoid


void csv_linear_regression(CSV *csv, size_t iter, sv *cols, size_t count);

void linear_regression(size_t iter, f64 *values,f64 *result ,size_t count);

void linear_regressionLS(f64 *values,f64 *result ,size_t count);

#endif