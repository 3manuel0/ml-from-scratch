#include "../includes/ml.h"
#include <math.h>


void linear_regression(size_t iter, f64 *values,f64 *result ,size_t count){
    // predicted = a*x + b
    // error = predicted - y

    // a -= lr * error * x
    // b -= lr * error
    f64 a = 0;
    f64 b = 0;
    f64 lr = 0.0000001;
    for(size_t i = 0; i < iter; i++){
        for(size_t j = 0; j < count; j++){
            f64 x = values[j];
            f64 y = result[j];
            f64 predicted = a * x + b;
            f64 error = predicted - y;
            a -= lr * error * x;
            b -= lr * error;
            if(i > 999900)
                printf("y = %g, predected = %g error = %.2lf%%\n", y, predicted, (fabs(y - predicted) / fabs(y) * 100));
        }
    }
        

    return;
}

void csv_linear_regression(CSV *csv, size_t iter, sv *cols, size_t count){
    printf("%zu  %zu\n", iter, count);
    for(size_t i = 0; i < count; i++)
        sv_println(&cols[i]);
    for(size_t i = 0; i < csv->numrows; i++)
        csv_print_row(csv->data[i], csv->types, csv->numcols);
    return;
}